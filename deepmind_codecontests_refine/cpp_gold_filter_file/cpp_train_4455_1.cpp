#include<stdio.h>

int main()
{
	long N,K;
	long sum = 0;
	scanf("%ld %ld", &N, &K);

	for (int i = K; i <= N + 1; i++) {
			sum += (N - i + 1) * i + 1;
			sum %= 1000000007;
	}

	printf("%ld", sum);
	return 0;
}