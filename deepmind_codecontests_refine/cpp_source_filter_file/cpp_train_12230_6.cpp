#include <bits/stdc++.h>
using namespace std;
template <class T>
T inline sqr(T x) {
  return x * x;
}
const long double pi = 3.1415926535897932384626433832795;
const long double eps = 1e-8;
const int N = 102;
vector<int> g[N][2];
int d[N][N];
void no() {
  cout << "IMPOSSIBLE\n";
  exit(0);
}
bool check(int l, int r) {
  for (int v = l; v <= r; v++)
    for (int t = 0; t < (int)(2); ++t)
      for (int x : g[v][t])
        if (x < l || x > r) return false;
  return true;
}
bool isIn(int x, int l, int r) { return x >= l && x <= r; }
bool dyn(int l, int r) {
  if (d[l][r] != 0) return d[l][r] > 0;
  if (l - 1 == r) {
    return true;
  }
  if (l == r) {
    d[l][r] = l;
    return true;
  }
  d[l][r] = -1;
  for (int k = l + 1; k <= r + 1; k++) {
    if (dyn(l + 1, k - 1) && dyn(k, r)) {
      bool ok = check(l + 1, k - 1) && check(k, r);
      for (int to : g[l][0])
        if (!isIn(to, l + 1, k - 1)) ok = false;
      for (int to : g[l][1])
        if (!isIn(to, k, r)) ok = false;
      if (ok) {
        d[l][r] = k;
        return true;
      }
    }
  }
  return false;
}
void rec(int l, int r) {
  if (l > r) return;
  if (l == r) {
    cout << l + 1 << " ";
    return;
  }
  rec(l + 1, d[l][r] - 1);
  cout << l + 1 << " ";
  rec(d[l][r], r);
}
int main() {
  int n, c;
  cin >> n >> c;
  for (int i = 0; i < (int)(c); ++i) {
    int u, v;
    string s;
    cin >> u >> v >> s;
    --u, --v;
    int t = (s == "RIGHT");
    if (u > v) no();
    g[u][t].push_back(v);
  }
  if (!dyn(0, n - 1)) {
    no();
  }
  rec(0, n - 1);
  return 0;
}
