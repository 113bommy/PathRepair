#include <bits/stdc++.h>
using namespace std;
int n, m, k, mod;
int cnt[1000] = {}, prod[1000];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m >> k;
  if (n % 2 != m % 2) {
    cout << 0 << endl;
    return 0;
  }
  int g = 0;
  for (int i = 0; i < (int)(1000); ++i) prod[i] = 1;
  for (int i = 0; i < (int)(k); ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    if (n < m) {
      prod[a] *= c;
      if (++cnt[a] == n) {
        ++g;
        if (prod[a] == 1) {
          cout << 0 << endl;
          return 0;
        }
      }
    } else {
      prod[b] *= c;
      if (++cnt[b] == m) {
        ++g;
        if (prod[b] == 1) {
          cout << 0 << endl;
          return 0;
        }
      }
    }
  }
  cin >> mod;
  --n, --m;
  n = max(0, n * m - k + g);
  int ans = 1;
  for (int i = 0; i < (int)(n); ++i) ans = (ans * 2) % mod;
  cout << ans << endl;
  return 0;
}
