#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

template <typename Tp> inline void getint(Tp &num){
	register int ch, neg = 0;
	while(!isdigit(ch = getchar())) if(ch == '-') neg = 1;
	num = ch & 15;
	while(isdigit(ch = getchar())) num = num * 10 + (ch & 15);
	if(neg) num = -num;
}

int N, cnt, fa[200005]; ll D, A[200005], L[200005], R[200005], ans;
struct edge {int u, v; ll w;} ed[4000005];

inline bool operator < (const edge &ed1, const edge &ed2) {return ed1.w < ed2.w;}
int getf(const int &u) {return fa[u] == u ? u : fa[u] = getf(fa[u]);}

inline int findmin(const ll *a, int l, const int &r){
	register int res = l;
	while(++l <= r) if(a[l] < a[res]) res = l;
	return res;
}

void build(const int &l, const int &r){
	if(l == r) return; const int mid = l + r >> 1;
	const int Lmin = findmin(L, l, mid), Rmin = findmin(R, mid + 1, r);
	for(register int i = l; i <= mid; i++) ed[++cnt] = (edge){i, Rmin, L[i] + R[Rmin]};
	for(register int i = mid + 1; i <= r; i++) ed[++cnt] = (edge){Lmin, i, L[Lmin] + R[i]};
	build(l, mid), build(mid + 1, r);
}

int main(){
	getint(N), getint(D);
	for(register int i = 1; i <= N; i++) getint(A[i]), fa[i] = i;
	for(register int i = 1; i <= N; i++) L[i] = A[i] - i * D, R[i] = A[i] + i * D;
	build(1, N), sort(ed + 1, ed + cnt + 1);
	for(register int i = 1, bl = N; i <= cnt && bl > 1; i++){
		const int fu = getf(ed[i].u), fv = getf(ed[i].v);
		if(fu != fv) bl--, fa[fv] = fu, ans += ed[i].w;
	}
	return printf("%lld\n", ans), 0;
}