#include <bits/stdc++.h>
using namespace std;
const int max_c = 14;
const int maxsize = 10002;
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  int n = 0;
  int k = 0;
  cin >> n >> k;
  vector<int> v(n, 0);
  int cnt[maxsize * 2] = {};
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    cnt[v[i]]++;
  }
  long long ans = 0;
  vector<int> masks;
  for (int i = 0; i < (1 << (max_c + 1)); i++) {
    if (__builtin_popcount(i) == k) {
      masks.push_back(i);
    }
  }
  for (int mask = 0; mask < maxsize; mask++) {
    for (auto diff_mask : masks) {
      ans += cnt[mask] * 1ll * cnt[mask ^ diff_mask];
    }
  }
  if (k == 0) ans -= n;
  cout << ans / 2;
  return 0;
}
