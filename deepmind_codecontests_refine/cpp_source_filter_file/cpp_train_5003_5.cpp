#include <cstdio>

int main()
{
	int r,c;
	scanf("%d %d", &r, &c);

	int array[r+1][c+1] = {0};

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf("%d", &array[i][j]);
			array[i][c] += array[i][j];
			array[r][j] += array[i][j];
			array[r][c] += array[i][j];
		}
	}

	/* test */ 
	for (int i = 0; i <= r; i++) {
		for (int j = 0; j <= c; j++) {
			printf("%d", array[i][j]);
			if(j != c) printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}
