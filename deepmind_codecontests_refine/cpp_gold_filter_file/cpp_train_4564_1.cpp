#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

int A,B;
int d[11][11];
const int C = 101;
int S = 1 , T = 2 * C;
int N = T , M = 2 * (C-1) + C * C;
int e[C][C];
 
int main(){
	cin >> A >> B;
	for (int i = 1; i <= A; ++i) {
		for (int j = 1; j <= B; ++j) {
			cin >> d[i][j];
		}
	}
	rep(i,C) rep(j,C){
		for (int x = 1; x <= A; ++x) {
			for (int y = 1; y <= B; ++y) {
				e[i][j] = max(e[i][j] , d[x][y]-i*x-j*y);
			}
		}
	}

	for (int x = 1; x <= A; ++x) {
		for (int y = 1; y <= B; ++y) {
			int z = C;
			rep(i,C) rep(j,C) z = min(z,e[i][j]+i*x+j*y);
			if(z != d[x][y]) return cout << "Impossible" << endl , 0;
		}
	}
	cout << "Possible" << endl;
	cout << N << ' ' << M << endl;
	for (int i = 1; i < C; ++i) {
		cout << i << ' ' << i+1 << " X" << endl;
		cout << C+i << ' ' << C+i+1 << " Y" << endl;
	}
	rep(i,C) rep(j,C) cout << i+1 << ' ' << N-j << ' ' << e[i][j] << endl;
	cout << S << ' ' << T << endl;
	return 0;
}