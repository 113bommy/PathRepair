#include <bits/stdc++.h>
#pragma GCC optimize "trapv"
using namespace std;
int INT_MX = 1e6 + 9;
vector<int> a(26);
int par(int i) {
  while (i != a[i]) i = a[i];
  return i;
}
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int ans = 0, ans_l = 0;
  int l = 0, r = 0;
  vector<int> m(1000006, 0);
  int count = 0;
  for (int i = 0; i < n; i++) {
    while (r < n) {
      if (m[a[r]] == 0 && count == k) {
        r--;
        break;
      }
      if (m[a[r]] == 0) {
        count++;
        m[a[r]] = 1;
      } else
        m[a[r]]++;
      r++;
    }
    if (r >= n) r = n - 1;
    if (ans < r - i + 1) {
      ans = r - i + 1;
      ans_l = i;
    }
    m[a[i]]--;
    if (m[a[i]] == 0) count--;
  }
  cout << ans_l + 1 << " " << ans_l + ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}
