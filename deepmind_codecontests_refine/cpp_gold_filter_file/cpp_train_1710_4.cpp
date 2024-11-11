#include <bits/stdc++.h>
using namespace std;
int ans[10000005], mp[10000005], cnt[10000005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, i, j;
  cin >> n;
  for (i = 1; i <= n; i++) {
    int a;
    cin >> a;
    ++mp[a];
  }
  vector<bool> prime(1e7 + 1, true);
  vector<int> v;
  for (i = 2; i <= 1e7; i++)
    if (prime[i]) {
      v.push_back(i);
      for (j = 2 * i; j <= 1e7; j += i) {
        prime[j] = false;
        cnt[i] += mp[j];
      }
      cnt[i] += mp[i];
    }
  for (i = 0; i < v.size(); i++) ans[v[i]] = cnt[v[i]];
  for (i = 1; i <= 1e7; i++) ans[i] += ans[i - 1];
  int m;
  cin >> m;
  while (m--) {
    int l, r;
    cin >> l >> r;
    if (l > 1e7) {
      cout << 0 << '\n';
      continue;
    }
    if (r > 1e7) r = 1e7;
    cout << ans[r] - ans[l - 1] << '\n';
  }
}
