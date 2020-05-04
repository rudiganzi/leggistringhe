

#include "leggi_stringhe.h"

char** leggi_stringhe(const char* filename, size_t* size) {

	FILE* f = fopen(filename, "rt");

	if (f == NULL) { return NULL; }


	

	int c = fgetc(f);            //usa fgets fgets(char* stringa,int lun, file* f)

	

	char** out = malloc(1);

	char* array = malloc(1);

	
	int b;

	for (int i = 0; i < c; ++i) {

		b = fgetc(f);

		*(size) += b;

		array = realloc(array, b);



		fgets(array, b, f);
               

		memcpy(out[i][0], array, b);

		out = realloc(out, *(size));
	}

	free(array);

	return out;
}
