#include<iostream>
#include<algorithm>
#define LL long long
int N;
int A[100010];
LL sum;

int main() {
	std::cin >> N;
	for (int i = 1; i <= N; i++) {
		scanf_s("%d",&A[i]);
		sum += A[i];
		if (i == 0)A[0] = A[N];
	}
	LL D = ((N + 1)*N) / 2;
	if (sum%D) {
		printf("%s\n", "NO");
		return 0;
	}
	int ave = sum / D;
	for (int i = 1; i < N; i++) {
		int tmp = A[i] - A[i + 1] + ave;
		if (tmp < 0 || tmp % N) {
			printf("%s\n", "NO");
			return 0;
		}
	}
	printf("%s\n", "YES");
	return 0;
}
