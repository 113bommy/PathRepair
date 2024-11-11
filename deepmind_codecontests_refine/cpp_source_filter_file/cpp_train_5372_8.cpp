#include <bits/stdc++.h>
using namespace std;
int main() {
  std ::ios_base ::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  if (k == 1) {
    cout << 1ll * n * (n + 1) / 2 << endl;
    return 0;
  }
  map<int, vector<int> > m;
  map<int, int> k_fac;
  vector<int> b;
  if (k % 2 == 0) {
    b.push_back(2);
    while (k % 2 == 0) {
      k_fac[2]++;
      k /= 2;
    }
  }
  for (int i = 3; i * i <= n; i += 2) {
    if (k % i == 0) {
      b.push_back(i);
      while (k % i == 0) {
        k_fac[i]++;
        k /= i;
      }
    }
  }
  if (k != 1) {
    b.push_back(k);
    k_fac[k]++;
  }
  for (int i = 0; i < n; ++i) {
    for (auto fac : b) {
      int ct = 0;
      int x = a[i];
      while (x % fac == 0) {
        ct++;
        x /= fac;
      }
      m[fac].push_back(ct);
    }
  }
  for (auto it : m)
    for (int i = 1; i < it.second.size(); ++i)
      m[it.first][i] += m[it.first][i - 1];
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int act_idx = INT_MAX;
    for (auto fac : b) {
      int req = k_fac[fac];
      if (i != 0) req = k_fac[fac] + (m[fac][i - 1]);
      int idx = lower_bound(m[fac].begin(), m[fac].end(), req) - m[fac].begin();
      act_idx = min(act_idx, n - idx);
    }
    ans += act_idx;
  }
  cout << ans << endl;
}
