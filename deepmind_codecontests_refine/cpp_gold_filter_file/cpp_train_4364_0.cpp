#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;

char s[9][5], t[3][3][5];
int dx[]{ -1,0,1,0 }, dy[]{ 0,1,0,-1 };
int dfs(int p) {
	int res = 0;
	rep(i, 3)rep(j, 3) {
		if (t[i][j][0])continue;
		rep(k, 4) {
			rep(l, 4) {
				int nx = i + dx[l], ny = j + dy[l];
				if (nx < 0 || 3 <= nx || ny < 0 || 3 <= ny || !t[nx][ny][0])continue;
				if (abs(s[p][(l + k) % 4] - t[nx][ny][(l + 2) % 4]) != 'a' - 'A')goto g;
			}
			if (p == 8)res++;
			else {
				rep(l, 4)t[i][j][l] = s[p][(l + k) % 4];
				res += dfs(p + 1); t[i][j][0] = 0;
			}g:;
		}
	}
	return res;
}
int main() {
	int n; scanf("%d", &n);
	rep(i, n) {
		rep(j, 9)scanf("%s", s[j]);
		printf("%d\n", dfs(0));
	}
}