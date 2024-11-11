//2018-1-18
//miaomiao
//
#include <bits/stdc++.h>
using namespace std;

#define Set(a, v) memset(a, v, sizeof(a))
#define For(i, a, b) for(int i = (a); i <= (int)(b); ++i)

#define M 18
#define N (100000+5)

int n, m, dn, pos[N], dis[M], nxt[N][M], beg[N], end[N];
int f[1<<M];

bool Solve(int l, int r){
	if(l == 1 && r == n) return true;

	f[0] = 0;
	
	int tmp;
	For(i, 1, (1<<dn)-1){
		f[i] = 0;
		For(j, 1, dn) if(i & (1<<(j-1))){
			tmp = f[i ^ (1<<(j-1))] + 1;
			if(tmp >= l && tmp <= r) tmp = r+1;

			f[i] = max(f[i], nxt[tmp][j]);
			if(f[i]+1 >= l && f[i]+1 <= r) f[i] = r;
		}
		if(f[i] >= n) return true;
	}
	return false;
}

int main(){
	scanf("%d%d", &n, &m);
	For(i, 1, n) scanf("%d", &pos[i]);
	
	int st, ed, cnt = 0;
	for(int d = m; d >= 0; d >>= 1){
		st = 1; if(d != m) dis[++dn] = d;

		while(st <= n){
			ed = st;
			while(ed < n && pos[ed+1]-pos[ed] <= d) ++ed;
			For(i, st, ed) nxt[i][dn] = ed;
			
			if(d == m){
				beg[++cnt] = st; end[cnt] = ed;
			}
			st = ed+1;
		}

		if(!d) break;
	}

	For(i, 1, dn) nxt[n+1][i] = n+1;
//	For(i, 1, n) For(j, 1, dn) printf("nxt[%d][%d] = %d\n", i, j, nxt[i][j]);

	if(cnt > dn+1){
		For(i, 1, n) puts("Impossible"); return 0;
	}

	For(si, 1, cnt){
	//	printf("%d -> %d free\n", beg[si], end[si]);
		if(Solve(beg[si], end[si])){
			For(i, beg[si], end[si]) puts("Possible");
		}else{
			For(i, beg[si], end[si]) puts("Impossible"); 
		}
	}
	
	return 0;
}