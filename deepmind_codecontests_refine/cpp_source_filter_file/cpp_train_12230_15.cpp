#include <bits/stdc++.h>
using namespace std;
template <class T>
T gcd(T x, T y) {
  if (x > y) swap(x, y);
  while (x != 0) {
    T r = y % x;
    y = x;
    x = r;
  }
  return y;
}
template <class T>
int cntbit(T s) {
  return __builtin_popcountll(s);
}
const int esp = (int)(1e9);
const double pi = acos(-1);
const int base = 1;
bool dd[111][111], f[111][111];
int n, m;
vector<int> ad[111][2];
bool cal(int u, int v) {
  if (u >= v) return true;
  if (dd[u][v]) return f[u][v];
  dd[u][v] = 1;
  int L = u + 1, R = v + 1;
  for (int i = 0; i <= 1; i++)
    for (int j = 0; j <= (int)ad[u][i].size() - 1; j++) {
      int x = ad[u][i][j];
      if (x > v || x < u) {
        f[u][v] = false;
        return false;
      }
      if (i == 0)
        L = max(L, x + 1);
      else
        R = min(R, x);
    }
  for (int i = L; i <= R; i++)
    if (cal(u + 1, i - 1) && cal(i, v)) {
      f[u][v] = 1;
      return 1;
    }
  return 0;
}
void trace(int u, int v) {
  if (u >= v) {
    if (u == v) cout << u << ' ';
    return;
  }
  int L = u + 1, R = v + 1;
  for (int i = 0; i <= 1; i++)
    for (int j = 0; j <= (int)ad[u][i].size() - 1; j++) {
      int x = ad[u][i][j];
      if (i == 0)
        L = max(L, x + 1);
      else
        R = min(R, x);
    }
  for (int i = L; i <= R; i++)
    if (cal(u + 1, i - 1) && cal(i, v)) {
      trace(u + 1, i - 1);
      cout << u << ' ';
      trace(i, v);
      return;
    }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    string s;
    int x, y, ok;
    cin >> x >> y >> s;
    if (s == "LEFT")
      ok = 0;
    else
      ok = 1;
    if (x >= y) {
      cout << "IMPOSSIBLE";
      return 0;
    }
    ad[x][ok].push_back(y);
  }
  if (cal(1, n)) {
    trace(1, n);
  } else
    cout << "IMPOSSIBLE";
  return 0;
}
