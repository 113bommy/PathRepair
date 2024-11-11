#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;

const int MAXN = 3e5 + 10;
int N, M;
struct Node {
	int l, r, d;
} A[MAXN];
int tr[MAXN];

inline int lowbit(int x) {
	return x & (-x);
}

inline void update(int x, int d) {
	for(; x <= M; x += lowbit(x))
		tr[x] += d;
}

inline int query(int x) {
	int res = 0;
	for(; x; x -= lowbit(x))
		res += tr[x];
	return res;
}

int main() {
	register int i, d;
	scanf("%d%d", &N, &M);
	for(i = 1; i <= N; ++i)
		scanf("%d%d", &A[i].l, &A[i].r), A[i].d = A[i].r - A[i].l + 1;
	sort(A + 1, A + N + 1, [&](Node x, Node y) {return x.d < y.d;});
	int k = 1;
	for(d = 1; d <= M; ++d) {
		while(k <= N && A[k].d < d) {
			update(A[k].l, 1); update(A[k].r + 1, -1);
			++k;
		}
		int ans = N - k + 1;
		for(i = d; i <= M; i += d)
			ans += query(i);
		printf("%d\n", ans);
	}
	return 0;
}