#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
using namespace std;
const int MAX = 1e6 + 5;
const long long MOD = 1000000007;
const long long MOD2 = 2010405347;
const long long INF = 2e18;
const int dr[] = {1, 0, -1, 0, 1, 1, -1, -1, 0};
const int dc[] = {0, 1, 0, -1, 1, -1, 1, -1, 0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 315;
inline long long pw(long long x, long long y, long long md = MOD) {
  long long ret = 1;
  while (y) {
    if (y & 1) ret = ret * x % md;
    x = x * x % md, y >>= 1;
  }
  return ret;
}
inline void add(int &a, int b, int md = MOD) {
  a = a + b >= md ? a + b - md : a + b;
}
int n, m, p[105], a, b;
char x[55][55], y[55][55];
vector<int> r[55], c[105];
int par(int z) {
  if (p[z] == z) return z;
  return p[z] = par(p[z]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = (1); i <= (n + m); ++i) p[i] = i;
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (m); ++j) {
      cin >> x[i][j];
      if (x[i][j] == '#') {
        a = par(i), b = par(n + j);
        p[b] = a;
      }
    }
  for (int i = (1); i <= (n); ++i) r[par(i)].push_back(i);
  for (int i = (n + 1); i <= (n + m); ++i) {
    c[par(i)].push_back(i - n);
  }
  memset(y, '.', sizeof y);
  for (int i = (1); i <= (n); ++i) {
    for (int a : r[i])
      for (int b : c[i]) y[a][b] = '#';
  }
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (m); ++j)
      if (x[i][j] != y[i][j]) return cout << "No\n", 0;
  cout << "Yes\n";
  return 0;
}
