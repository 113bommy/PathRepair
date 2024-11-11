#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:32000000")
using namespace std;
inline bool read(int& val) { return scanf("%d", &val) != -1; }
inline bool read(long long& val) { return scanf("%I64d", &val) != -1; }
inline bool read(double& val) { return scanf("%lf", &val) != -1; }
inline bool read(char* val) { return scanf("%s", val) != -1; }
template <class T1, class T2>
inline bool read(T1& a, T2& b) {
  return read(a) && read(b);
}
template <class T1, class T2, class T3>
inline bool read(T1& a, T2& b, T3& c) {
  return read(a) && read(b) && read(c);
}
template <class T1, class T2, class T3, class T4>
inline bool read(T1& a, T2& b, T3& c, T4& d) {
  return read(a) && read(b) && read(c) && read(d);
}
template <class T1, class T2, class T3, class T4, class T5>
inline bool read(T1& a, T2& b, T3& c, T4& d, T5& e) {
  return read(a) && read(b) && read(c) && read(d) && read(e);
}
const double eps = 1e-9;
const double pi = acos(-1.0);
const int inf = 0x0FFFFFFF;
const int nil = -1;
const int root = nil + 1;
const int N = 111111;
long long mod = 1000000007;
long long ans[N];
vector<pair<int, int> > bang[2][2][2][N];
bool vis[2][2][2][N];
int sgn(int x) {
  if (x > 0) return 1;
  if (x < 0) return -1;
  return 0;
}
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0, _ = (k); i < _; ++i) ans[i] = -1;
  for (int i = 0, _ = (k); i < _; ++i) {
    int x, y, t;
    cin >> x >> y;
    for (int b = 0, _ = (2); b < _; ++b) {
      t = b == 0 ? y : m - y;
      if (x - t >= 0) bang[0][b][1][x - t].push_back(pair<int, int>(i, t));
      if (x + t <= n) bang[0][b][0][x + t].push_back(pair<int, int>(i, t));
      t = b == 0 ? x : n - x;
      if (y - t >= 0) bang[1][b][1][y - t].push_back(pair<int, int>(i, t));
      if (y + t <= m) bang[1][b][0][y + t].push_back(pair<int, int>(i, t));
    }
  }
  int a = 0, b = 0, c = 1, p = 0;
  long long time = 0;
  while (!vis[a][b][c][p]) {
    vis[a][b][c][p] = true;
    int s, t;
    if (a == 0) {
      if (c == 0) {
        s = p - m;
        t = p;
      } else {
        s = (n - p) - m;
        t = n - p;
      }
    } else {
      if (c == 0) {
        s = p - n;
        t = p;
      } else {
        s = (m - p) - n;
        t = m - p;
      }
    }
    vector<pair<int, int> >& ref = bang[a][b][c][p];
    for (int i = 0, _ = (ref.size()); i < _; ++i) {
      int ai = ref[i].first, val = ref[i].second;
      long long tmp = time + val;
      if (ans[ai] == -1 || ans[ai] > tmp) ans[ai] = tmp;
    }
    if (s == 0) break;
    if (s > 0) {
      time += (a == 0 ? m : n);
      if (c == 0)
        p -= (a == 0 ? m : n);
      else
        p += (a == 0 ? m : n);
      b ^= 1;
    } else {
      time += t;
      if (b == 0)
        p = t;
      else
        p = (a == 0 ? m - t : n - t);
      int pb = b;
      a ^= 1;
      b = c;
      c = pb ^ 1;
    }
  }
  for (int i = 0, _ = (k); i < _; ++i) printf("%I64d\n", ans[i]);
  return 0;
}
