#include <cstdio>
#include <iostream>
#include <cstring>
#define poi(lx,ly,rx,ry) ((lx>rx||ly>ry)?0:(ice[rx][ry] + ice[lx-1][ly-1] - ice[rx][ly-1] - ice[lx-1][ry]))
int n, m, hx, hy;
int ice[41][41], ans=2147483647, f[41][41][41][41];
char tmp;
using std::min;
using std::cin;
signed main() {
	register int i, j, o, p, s, t;
	cin >> n >> m;
	memset(f, 0x7f, sizeof(f));
	f[1][1][n][m] = 0;
	for ( i = 1; i <= n; ++ i )
		for ( j = 1; j <= m; ++ j ) {
			cin >> tmp;
			if (tmp == 'P')
				hx = i, hy = j;
			ice[i][j] = ice[i-1][j] + ice[i][j-1] - ice[i-1][j-1] + (tmp == '#');
		}
	for ( i = 1; i <= hx; ++ i )
	for ( j = 1; j <= hy; ++ j )
	for ( o = n; o >= hx; -- o )
	for ( p = m; p >= hy; -- p ) {
		ans = min(ans, f[i][j][o][p]+min(min(poi(i,j,hx,hy),poi(i,hy,hx,p)),min(poi(hx,j,o,hy),poi(hx,hy,o,p))));
		for ( s = i; s <= o; ++ s )
		for ( t = j; t <= p; ++ t ) {
			if (hx<=s&&hy<=t)
				f[i][j][s][t]=min(f[i][j][s][t],f[i][j][o][p]+poi(i,t+1,s,p)+poi(s+1,j,o,t));
			if (hx<=s&&hy>=t)
				f[i][t][s][p]=min(f[i][t][s][p],f[i][j][o][p]+poi(i,j,s,t-1)+poi(s+1,t,o,p));
			if (hx>=s&&hy>=t)
				f[s][t][o][p]=min(f[s][t][o][p],f[i][j][o][p]+poi(i,t,s-1,p)+poi(s,j,o,t-1));
			if (hx>=s&&hy<=t)
				f[s][j][o][t]=min(f[s][j][o][t],f[i][j][o][p]+poi(i,j,s-1,t)+poi(s,t+1,o,p));
		}
	}
	std::cout << ans;
	return 0;
}