#include <bits/stdc++.h>
using namespace std;
int n, k, a[int(1e5 + 5)];
map<int, int> f[int(1e5 + 5)], mp, b;
void solve() {
  sort(a, a + n);
  for (int i = 0; i < (n); ++i) {
    int t = a[i];
    for (int j = 2; j * j <= a[i]; j++) {
      while (t % j == 0) f[i][j]++, t /= j;
    }
    if (t > 1) f[i][t]++;
  }
  int ans = 0;
  for (int i = 0; i < (n); ++i) {
    long long v = 1, z = 1;
    for (auto j : f[i]) {
      v *= pow(j.first, (k - j.second % k) % k);
      z *= pow(j.first, k * (j.second / k));
    }
    if (mp.count(v)) ans += mp[v];
    mp[a[i] / z]++;
  }
  cout << ans;
}
int main() {
  int test = 1;
  while (test--) {
    cin >> n >> k;
    for (int i = 0; i < (n); ++i) cin >> a[i];
    solve();
    cout << "\n";
  }
  return 0;
}
