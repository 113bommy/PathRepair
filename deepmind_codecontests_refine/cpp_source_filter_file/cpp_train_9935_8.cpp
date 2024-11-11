#include <bits/stdc++.h>
using namespace std;
struct _ {
  _() { ios_base::sync_with_stdio(0); }
} _;
template <class T>
void PV(T a, T b) {
  while (a != b) cout << *a++, cout << (a != b ? " " : "\n");
}
template <class T>
inline bool chmin(T& a, T b) {
  return a > b ? a = b, 1 : 0;
}
template <class T>
inline bool chmax(T& a, T b) {
  return a < b ? a = b, 1 : 0;
}
template <class T>
string tostring(T first, int len = 0) {
  stringstream ss;
  ss << first;
  string r = ss.str();
  if (r.length() < len) r = string(len - r.length(), '0') + r;
  return r;
}
template <class T>
void convert(string first, T& r) {
  stringstream ss(first);
  ss >> r;
}
template <class A, class B>
ostream& operator<<(ostream& o, pair<A, B> t) {
  o << "(" << t.first << ", " << t.second << ")";
  return o;
}
const int inf = 0x3f3f3f3f;
const int mod = int(1e9) + 7;
const int N = 401;
int n, m;
int d[N][N];
int nextCol[N][N];
int g[N][N * N];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> d[i][j];
  int res = 0;
  fill(&nextCol[0][0], &nextCol[N][0], m + 1);
  fill(&g[0][0], &g[N][0], m + 1);
  for (int k = m; k >= 1; k--) {
    for (int l = 1; l <= n; l++) {
      if (l == 1) {
        for (int i = 1; i <= n; i++) {
          nextCol[i][i] = g[i][d[i][k]];
          chmax(res, nextCol[i][i] - k);
        }
      } else {
        for (int i = 1; i + l - 1 <= n; i++) {
          int j = i + l - 1;
          int& tmp = nextCol[i][j];
          chmin(tmp, nextCol[i + 1][j]);
          chmin(tmp, nextCol[i][j - 1]);
          chmin(tmp, g[i][d[j][k]]);
          chmin(tmp, g[j][d[i][k]]);
          if (d[i][k] == d[j][k]) chmin(tmp, k);
          chmax(res, l * (tmp - k));
        }
      }
    }
    for (int i = 1; i <= n; i++) g[i][d[i][k]] = k;
  }
  cout << res << endl;
  return 0;
}
