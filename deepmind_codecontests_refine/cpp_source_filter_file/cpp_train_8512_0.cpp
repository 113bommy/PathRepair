#include <cstdio>
#include <algorithm>

typedef long long LL;
const int MN = 200005;

int N, stk[MN], tp;
LL A[MN], B[MN], C[MN], f[MN], Ans;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%lld", &A[i]);
	for (int i = 1; i <= N; ++i) scanf("%lld", &B[i]);
	int p = std::max_element(A + 1, A + N + 1) - A;
	std::rotate(A + 1, A + p, A + N + 1);
	std::rotate(B + 1, B + p, B + N + 1);
	A[N + 1] = A[1];
	for (int i = 2; i <= N; ++i) C[i + 1] = 2 * (C[i] + B[i]) - C[i - 1];
	for (int i = 1; i <= N + 1; ++i) {
		A[i] -= C[i];
		while (tp > 1 && (A[stk[tp]] - A[stk[tp - 1]]) * (i - stk[tp]) <= (A[i] - A[stk[tp]]) * (stk[tp] - stk[tp - 1])) --tp;
		stk[++tp] = i;
	}
	for (int i = 2; i <= tp; ++i) {
		int c = stk[i] - stk[i - 1];
		Ans += A[stk[i - 1]] * (c + 1) + A[stk[i]] * (c - 1);
	}
	for (int i = 1; i <= N; ++i) Ans += 2 * C[i];
	printf("%.12lf\n", Ans / (2. * N);
	return 0;
}