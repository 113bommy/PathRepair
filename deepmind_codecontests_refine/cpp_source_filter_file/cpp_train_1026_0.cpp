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

#include <complex>
typedef complex<double> P;

#define LT(x,y) ((x)-(y)<=-EPS)
#define LE(x,y) ((x)-(y)<+EPS)

vector<P> cross_circles(P c1, double r1, P c2, double r2) {
	double d = abs(c2 - c1);
	if (LT(r1 + r2, d) || LT(d, fabs(r1 - r2))) {
		return vector<P>();
	}
	double l = 0.5*((r1*r1 - r2*r2) / d + d);
	double h = sqrt(r1*r1 - l*l);
	vector<P> ret(2);
	ret[0] = P(l, +h)*(c2 - c1) / d + c1;
	ret[1] = P(l, -h)*(c2 - c1) / d + c1;
	return ret;
}
 
int main() {
	int n;
	while (cin >> n, n) {
		double x, y;
		char c;
		vector<P> circles(n);
		REP(i, n) {
			cin >> x >> c >> y;
			circles[i] = P(x, y);
		}

		int ans = 1;
		REP(i, n - 1) {
			REP(j, i + 1, n - 1) {
				vector<P> pts = cross_circles(circles[i], 1.0, circles[j], 1.0);
				int size = pts.size();
				REP(k, size) {
					int count = 2;
					REP(l, n) {
						if (l == i || l == j) {
							continue;
						}
						else {
							if (LE(abs(circles[l] - pts[k]), 1.0)) {
								count++;
							}
						}
					}
					ans = max(ans, count);
				}
			}
		}

		cout << ans << endl;
	}

	return 0;
}