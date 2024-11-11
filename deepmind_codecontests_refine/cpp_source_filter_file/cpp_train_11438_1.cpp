#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int, int >
#define F first
#define S second
#define int  long long int
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
using namespace std;
/// khodaya komak kon

/// ba z_func hatman dafe baad bezan
const int MAX_N = 5e5 + 5;
char a[MAX_N];
int N, pre[MAX_N], nxt[MAX_N];
bool check(int pos) {
	bool f1 = (!pre[pos]) || (pos % (pos - pre[pos]));
	bool f2 = (nxt[pos + 1] == N + 1) || (N - pos) % (N - pos - (N - nxt[pos + 1] + 1));
	if (f1 && f2) return 1;
	else return 0;
}
int main () {
	scanf("%s", a + 1);
	N = strlen(a + 1);
	pre[1] = 0;
	for (int i = 2, j = 0; i <= N; i++) {
		while (j && a[j + 1] != a[i]) j = pre[j];
		if (a[j + 1] == a[i]) ++j;
		pre[i] = j;
	}
	nxt[N] = N + 1;
	for (int i = N - 1, j = N + 1; i; i--) {
		while (j <= N && a[j - 1] != a[i]) j = nxt[j];
		if (a[j - 1] == a[i]) --j;
		nxt[i] = j;
	}
	if (!pre[N] || N % (N - pre[N])) return puts("1\n1") & 0;
	if (pre[N] == N - 1) return printf("%d\n1\n", N) & 0;
	int ans = 0;
	for (int i = 1; i < N; i++) ans += check(i);
	printf("2\n%d\n", ans);
    return 0;
}
