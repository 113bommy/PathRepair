#include<stdio.h>
int main(void){
	int N = 1;
	static int k[10000];
	int i;
	int a, b;

	for (;;){
		scanf_s("%d", &N);

		if (N == 0)
			break;

		for (i = 0; i < N; i++)
			scanf_s("%d", &k[i]);

		a = 0, b = 0;
		for (i = 0; i < N; i++){
			if (k[i] == 0)
				a++;
			if (k[i] < 2)
				b++;
		}

		if (b == N)
			printf("NA\n");
		else{
			N = N - a + 1;
			printf("%d\n", N);
		}
	}
}
