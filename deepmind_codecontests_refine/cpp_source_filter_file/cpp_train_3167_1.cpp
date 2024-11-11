#include <bits/stdc++.h>
using namespace std;
int power(int a, int b, int m = 1000000007) {
  if (b == 0) return 1;
  if (b == 1) return a;
  int res = power(a, b / 2, m);
  res = (res * res) % m;
  if (b & 1) res = (res * a) % m;
  return res;
}
int modinv(int a) { return power(a, 1000000007 - 2); }
void solve() {
  int n, m, p;
  cin >> n >> m >> p;
  int a[n], i, b;
  for (i = 0; i < n; i++) cin >> a[i];
  unordered_map<int, int> mp, mp1;
  for (i = 0; i < m; i++) {
    cin >> b;
    mp[b]++;
  }
  vector<int> ans;
  for (i = 0; i < p; i++) {
    int k = 0, j = i, dif = 0;
    mp1.clear();
    while (k < m && j < n) {
      k++;
      mp1[a[j]]++;
      if (mp1[a[j]] == mp[a[j]] + 1 || mp1[a[j]] == 1) dif++;
      if (mp1[a[j]] == mp[a[j]]) dif--;
      j += p;
    }
    for (; j < n;) {
      int j1 = j - m * p;
      if (dif == 0) ans.push_back(j1 + 1);
      mp1[a[j1]]--;
      if (mp1[a[j1]] == mp[a[j1]] - 1) dif++;
      if (mp1[a[j1]] == mp[a[j1]] || mp1[a[j1]] == 0) dif--;
      mp1[a[j]]++;
      if (mp1[a[j]] == mp[a[j]] + 1 || mp1[a[j]] == 1) dif++;
      if (mp1[a[j]] == mp[a[j]]) dif--;
      j += p;
    }
    if (dif == 0) ans.push_back(j - m * p + 1);
  }
  cout << ans.size() << "\n";
  sort(ans.begin(), ans.end());
  for (i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  cout << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) solve();
  return 0;
}
