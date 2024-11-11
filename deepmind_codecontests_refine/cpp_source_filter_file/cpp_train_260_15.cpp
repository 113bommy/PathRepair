#include <bits/stdc++.h>
using namespace std;
string s;
int64_t g[1100005], cnt[1100005], sz[1100005], pop[1100005];
void FWT(int64_t *a, int64_t nn, bool idwt = false) {
  for (int64_t h = 1; h <= nn; h <<= 1) {
    for (int64_t i = 0; i < nn; i += h) {
      for (int64_t j = i; j < i + h / 2; j++) {
        int64_t x = a[j], y = a[j + h / 2];
        a[j] = x + y;
        a[j + h / 2] = x - y;
        if (idwt) a[j] >>= 1, a[j + h / 2] >>= 1;
      }
    }
  }
}
int32_t main() {
  {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
  };
  int64_t n, m, nn;
  cin >> n >> m;
  nn = (1 << n);
  for (int64_t i = 0; i < n; i++) {
    cin >> s;
    for (int64_t j = 0; j < m; j++) {
      g[j] |= (s[j] - '0') << i;
    }
  }
  for (int64_t i = 0; i < m; i++) cnt[g[i]]++;
  for (int64_t i = 1; i < nn; i++) sz[i] = sz[i >> 1] + (i & 1);
  for (int64_t i = 0; i < nn; i++) pop[i] = min(sz[i], n - sz[i]);
  FWT(cnt, nn);
  FWT(pop, nn);
  for (int64_t i = 0; i < nn; i++) cnt[i] *= pop[i];
  FWT(cnt, nn, true);
  cout << *min_element(cnt, cnt + n) << '\n';
  return 0;
}
