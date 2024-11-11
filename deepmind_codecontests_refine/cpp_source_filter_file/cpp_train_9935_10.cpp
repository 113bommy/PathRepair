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
inline bool chmin(T &a, T b) {
  return a > b ? a = b, 1 : 0;
}
template <class T>
inline bool chmax(T &a, T b) {
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
void convert(string first, T &r) {
  stringstream ss(first);
  ss >> r;
}
template <class A, class B>
ostream &operator<<(ostream &o, pair<A, B> t) {
  o << "(" << t.first << ", " << t.second << ")";
  return o;
}
const int inf = 0x3f3f3f3f;
const int mod = int(1e9) + 7;
const int N = 401;
int n, m;
int d[N][N];
int nextCol[N][N];
int g[N][N];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> d[i][j];
  int res = 0;
  fill(&nextCol[0][0], &nextCol[N][0], m + 1);
  fill(&g[0][0], &g[N][0], m + 1);
  for (int k = m; k >= 1; k--) {
    for (int l = 1; l <= n; l++)
      for (int i = 1; i + l - 1 <= n; i++) {
        int j = i + l - 1;
        if (i != j) {
          chmin(nextCol[i][j], nextCol[i + 1][j]);
          chmin(nextCol[i][j], nextCol[i][j - 1]);
        } else {
          chmin(nextCol[i][j], g[i][d[i][k]]);
        }
        chmin(nextCol[i][j], g[i][d[j][k]]);
        chmin(nextCol[i][j], g[j][d[i][k]]);
        if (d[i][k] == d[j][k] && i != j) chmin(nextCol[i][j], k);
        chmax(res, (j - i + 1) * (nextCol[i][j] - k));
      }
    for (int i = 1; i <= n; i++) g[i][d[i][k]] = k;
  }
  cout << res << endl;
  return 0;
}
