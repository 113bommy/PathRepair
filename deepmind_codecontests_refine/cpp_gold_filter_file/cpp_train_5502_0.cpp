#include <stdio.h>

const long long mod = 1000000007;

struct mat {
	long long a[3][3];

	mat operator -(mat t) {
		mat r;
		for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++){
			r.a[i][j] = (a[i][j] + mod - t.a[i][j]) % mod;
		}
		return r;
	}

	mat operator *(mat t){
		mat r;
		for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++){
			r.a[i][j] = 0;
			for (int k = 0; k < 3; k++) {
				r.a[i][j] = (r.a[i][j] + a[i][k] * t.a[k][j]) % mod;
			}
		}
		return r;
	}
};

mat pow(mat a, int p)
{
	mat r;
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) r.a[i][j] = 0;
	for (int i = 0; i < 3; i++) r.a[i][i] = 1;
	while (p) {
		if (p & 1) r = r * a;
		a = a * a;
		p /= 2;
	}
	return r;
}

int N, M, X[100100];
long long D[100100];

long long get(mat t) {
	return (t.a[2][0] * 5 + t.a[2][1]) % mod;
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int t = 1; t <= M; t++) scanf("%d", &X[t]);
	X[M + 1] = N;

	mat base = { 4,mod - 2,1,1,0,0,0,1,0 };
	mat sum = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	for (int i = 1; i <= M + 1; i++) {
		sum = sum * pow(base, X[i] - X[i-1]);
		D[i] = get(pow(base, X[i]) - sum);
		for (int k = 0; k < 3; k++) sum.a[k][k] = (sum.a[k][k] + D[i]) % mod;
	}

	printf("%lld\n", D[M+1]);
	return 0;
}