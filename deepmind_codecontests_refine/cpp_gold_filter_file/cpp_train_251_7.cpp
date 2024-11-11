#include <bits/stdc++.h>
using namespace std;
const int DX[] = {1, 0, -1, 0, 1, -1, 1, -1};
const int DY[] = {0, 1, 0, -1, 1, -1, -1, 1};
const long long mod = 1000000007;
const int maxn = (int)(1 << 20) + 10;
const int M = 21;
int n;
long long a[maxn], f[maxn][M + 5], g[maxn], pow2[maxn];
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed;
  cin >> n;
  int _;
  for (int i = 1; i < n + 1; i++) {
    cin >> _;
    a[_]++;
  }
  for (int x = 0; x < (1 << 20); x++) {
    f[x][0] = a[x];
  }
  for (int i = 1; i < M; i++) {
    for (int x = 0; x < (1 << 20); x++) {
      if ((x >> (i - 1)) & 1)
        f[x][i] = f[x][i - 1];
      else
        f[x][i] = f[x][i - 1] + f[x | (1 << (i - 1))][i - 1];
    }
  }
  if (0)
    for (int i = 0; i < 5; i++) {
      for (int x = 0; x < (1 << 4); x++) {
        cerr << f[x][i] << ' ';
      }
      cerr << endl;
    }
  pow2[0] = 1;
  for (int i = 1; i < (1 << 20); i++) {
    pow2[i] = (2 * pow2[i - 1]) % mod;
  }
  long long ans = 0;
  for (int x = 0; x < (1 << 20); x++) {
    ans += ((__builtin_popcount(x) & 1) ? -1 : 1) * pow2[f[x][20]];
    while (ans < 0) ans += mod;
    ans %= mod;
  }
  cout << ans << endl;
  if (0) cerr << "time = " << clock() * 1.0 / CLOCKS_PER_SEC << " s" << endl;
  return 0;
}
