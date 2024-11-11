#include<cstdio>
#include<algorithm>
#include<cstring>
#define rep(i, s, t) for(i = s; i <= t; ++i)
#define dep(i, s, t) for(i = s; i >= t; --i)

using namespace std;

const int N = 1010;
int n, m, nn, mm, A, B;
char mp[N][N];

void paint(int t, int o, bool stop) {
	int x, y;
	x = (t-1) / mm + 1; y = (t-1) % mm + 1;
	//printf("%d %d\n", x, y);
	x = (x-1) * 2 + 1; y = (y-1) * 2 + 1;
	if(!o) {
		mp[x][y] = '<'; mp[x][y+1] = '>';
		if(stop) return;
		mp[x+1][y] = '<'; mp[x+1][y+1] = '>';
	} else {
		mp[x][y] = '^'; mp[x+1][y] = 'v';
		if(stop) return;
		mp[x][y+1] = '^'; mp[x+1][y+1] = 'v';
	}
}

void so(int e) {
	int t, f, i, j;
	nn = n>>1; mm = m>>1; f = nn * mm;
	
	t = min(f, A/2); f -= t; A -= t*2;
	for(i = 1; i <= t; ++i) paint(i, 0, 0);
	t = min(f, B/2); f -= t; B -= t*2;
	for(t += i-1; i <= t; ++i) paint(i, 1, 0);
	
	if((A || B) && (!f)) {puts("NO"); return;}
	if(A+B <= f+e) puts("YES"); else {puts("NO"); return;}
	
	if(f == 1 && A && B && e) {
		mp[n-2][m-2] = '<'; mp[n-2][m-1] = '>';
		mp[n-1][m-2] = '^'; mp[n][m-2] = 'v';
	} else {
		if(A) paint(i++, 0, 1);
		if(B) paint(i++, 1, 1);
	}
	rep(i, 1, n) {
		rep(j, 1, m) printf("%c", mp[i][j]);
		puts("");
	}
}

int main() {
	int i, j, down, right;
	scanf("%d%d%d%d", &n, &m, &A, &B);
	rep(i, 1, n) rep(j, 1, m) mp[i][j] = '.';
	if((n & 1) && (m > 1)) {
		down = min(A, m/2);
		A -= down; down <<= 1;
		rep(i, 1, down) mp[n][i] = (i&1)? '<': '>';
		if((m&1) && m>1 && m == down+1) {
			mp[n][m-2] = '.'; mp[n][m-1] = '<'; mp[n][m] = '>';
		}
	}
	if((m & 1) && (n > 1)) {
		right = min(B, n/2);
		B -= right; right <<= 1;
		rep(i, 1, right) mp[i][m] = (i&1)? '^': 'v';
	}
	
	if((n&1) && (m&1)) so(1); else so(0);
	return 0;
}