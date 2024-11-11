#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int MAX = 2e5 + 5;
const long long MAX2 = 11;
const long long MOD = 998244353;
const long long MOD2 = 1000005329;
const long long INF = 2e18;
const int dr[] = {1, 0, -1, 0, 1, 1, -1, -1, 0};
const int dc[] = {0, 1, 0, -1, 1, -1, 1, -1, 0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;
int n, m, a, b, c, v[205][205], ans;
pair<double, pair<int, int> > e[205 * 205];
double le, ri, m1, m2, n1, n2, a1, a2, u[205][205], nx;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if (i != j) v[i][j] = MOD;
  for (int i = 1; i <= m; ++i) {
    cin >> a >> b >> c;
    e[i] = {c, {a, b}};
    v[a][b] = v[b][a] = min(v[a][b], c);
  }
  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j) v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) u[i][j] = v[i][j];
  ans = 1e9;
  for (int i = 1; i <= m; ++i) {
    a = e[i].second.first, b = e[i].second.second;
    le = 0.0, ri = e[i].first;
    for (int k = 1; k <= 30; ++k) {
      m1 = (le + le + ri) / 3.0, n1 = e[i].first - m1;
      m2 = (le + ri + ri) / 3.0, n2 = e[i].first - m2;
      a1 = a2 = 0.0;
      for (int j = 1; j <= n; ++j) {
        a1 = max(a1, min(u[a][j] + m1, u[b][j] + n1));
        a2 = max(a2, min(u[a][j] + m2, u[b][j] + n2));
      }
      if (a1 < a2)
        ri = m2;
      else
        le = m1;
    }
    ans = min(ans, (int)round(a1 * 2.0));
    nx = m1;
    le = 0.0, ri = nx;
    for (int k = 1; k <= 30; ++k) {
      m1 = (le + le + ri) / 3.0, n1 = e[i].first - m1;
      m2 = (le + ri + ri) / 3.0, n2 = e[i].first - m2;
      a1 = a2 = 0.0;
      for (int j = 1; j <= n; ++j) {
        a1 = max(a1, min(u[a][j] + m1, u[b][j] + n1));
        a2 = max(a2, min(u[a][j] + m2, u[b][j] + n2));
      }
      if (a1 < a2)
        ri = m2;
      else
        le = m1;
    }
    ans = min(ans, (int)round(a1 * 2.0));
    le = nx, ri = e[i].first;
    for (int k = 1; k <= 30; ++k) {
      m1 = (le + le + ri) / 3.0, n1 = e[i].first - m1;
      m2 = (le + ri + ri) / 3.0, n2 = e[i].first - m2;
      a1 = a2 = 0.0;
      for (int j = 1; j <= n; ++j) {
        a1 = max(a1, min(u[a][j] + m1, u[b][j] + n1));
        a2 = max(a2, min(u[a][j] + m2, u[b][j] + n2));
      }
      if (a1 < a2)
        ri = m2;
      else
        le = m1;
    }
    ans = min(ans, (int)round(a1 * 2.0));
  }
  if (ans & 1)
    cout << ans / 2 << ".5\n";
  else
    cout << ans / 2 << ".0\n";
  return 0;
}
