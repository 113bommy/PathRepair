#include <bits/stdc++.h>
using namespace std;
const int LIM = 2e+5 + 100;
int get_gcd(int a, int b) { return b ? get_gcd(b, a % b) : a; }
int a[LIM], gcd[LIM];
vector<bool> good(LIM);
vector<int> len(LIM), _max(LIM);
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) gcd[i] = get_gcd(i, n);
  long long ans = 0;
  for (int i = 1; i < n; ++i) {
    if (n % i) continue;
    good.assign(n, false);
    len.assign(n, 0);
    _max.assign(n, 0);
    for (int j = 0; j < n; ++j) _max[j % i] = max(_max[j % i], a[j]);
    for (int j = 0; j < n; ++j) good[j] = _max[j % i] == a[j];
    int l = 0;
    bool all = true;
    while (l < n) {
      if (good[l]) {
        ++l;
        continue;
      }
      all = false;
      int r = (l + 1) % n;
      int cur_len = 0;
      while (good[r]) {
        ++r;
        ++cur_len;
        if (r >= n) r -= n;
      }
      for (int k = 1; k <= cur_len; ++k) len[k] += cur_len + 1 - k;
      if (r <= l) break;
      l = r;
    }
    if (all)
      for (int j = 1; j <= n; ++j) len[j] = n;
    for (int j = 1; j <= n; ++j) ans += (gcd[j] == i ? len[j] : 0);
  }
  cout << ans;
  return 0;
}
