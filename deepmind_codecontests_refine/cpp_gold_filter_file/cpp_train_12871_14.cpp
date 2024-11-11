#include <bits/stdc++.h>
using namespace std;
const long long inf = (long long)1e9 + 10;
const long long linf = (long long)1e18 + 10;
const long long mod = (long long)(1e9 + 7);
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};
const double eps = 1e-10;
struct oreno_initializer {
  oreno_initializer() {
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
} oreno_initializer;
int n, m, r;
bool p[200202];
void sieve() {
  fill(p, p + 200200, true);
  p[0] = p[1] = false;
  for (int i = 2; i * i <= 200200; ++i) {
    if (p[i]) {
      for (int j = 2 * i; j <= 200200; j += i) p[j] = false;
    }
  }
}
signed main() {
  cin >> n >> m;
  sieve();
  r = n - 1;
  while (!p[r]) r++;
  cout << r << ' ' << r << '\n';
  cout << "1 2 " << r - (n - 2) << '\n';
  for (int(i) = (2); (i) < (n); ++(i))
    cout << i << ' ' << i + 1 << " 1" << '\n';
  m -= n - 1;
  if (m == 0) return 0;
  for (int(i) = (1); (i) < (n); ++(i)) {
    for (int(j) = (i + 2); (j) < (((n) + 1)); ++(j)) {
      cout << i << ' ' << j << " 1000000000" << '\n';
      m--;
      if (m == 0) return 0;
    }
  }
}
