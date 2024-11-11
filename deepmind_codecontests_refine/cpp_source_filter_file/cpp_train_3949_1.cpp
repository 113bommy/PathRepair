#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>
#include <functional>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <fstream>
#include <list>
using namespace std;
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toStr(T x) { ostringstream sout; sout << x; return sout.str(); }
typedef vector<int> vi;
typedef vector<vi>  vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n) FOR(i,0,(n)-1)
const double EPS = 1e-10;
const double PI = acos(-1.0);
const int INF = INT_MAX / 10;

vvi mul(vvi &A, vvi &B, ll M) {
	vvi C(A.size(), vi(B[0].size()));
	REP(i, A.size()) {
		REP(k, B.size()) {
			REP(j, B[0].size()) {
				C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % M;
			}
		}
	}
	return C;
}

vvi pow(vvi A, ll n, ll M) {
	vvi B(A.size(), vi(A.size()));
	REP(i, A.size()) {
		B[i][i] = 1;
	}
	while (n > 0) {
		if (n & 1) {
			B = mul(B, A, M);
		}
		A = mul(A, A, M);
		n >>= 1;
	}
	return B;
}

int main() {
	int N, M, A, B, C, T;
	while (cin >> N >> M >> A >> B >> C >> T, N) {
		vvi mat(N, vi(N));
		REP(i, N) {
			if (i != N - 1) {
				mat[i + 1][i] = A;
			}
			mat[i][i] = B;
			if (i != 0) {
				mat[i - 1][i] = C;
			}
		}

		vvi S(N, vi(1));
		REP(i, N) {
			cin >> S[i][0];
		}

		vvi ans = mul(pow(mat, T, M), S, M);
		REP(i, N) {
			cout << ans[i][0];
			if (i != N - 1) {
				cout << " ";
			}
		}
		cout << endl;
	}

	return 0;
}