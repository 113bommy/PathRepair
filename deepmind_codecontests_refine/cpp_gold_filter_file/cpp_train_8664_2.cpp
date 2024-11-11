#include <bits/stdc++.h>
using namespace std;
int pref[100001];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> arr(m);
  long long s = 0;
  for (int& it : arr) {
    cin >> it;
    s += it;
  }
  if (s < n) {
    cout << "-1";
    return 0;
  }
  for (int i = 0; i < m; i++) {
    pref[i] = max(i == 0 ? 0 : pref[i - 1], i + arr[i]);
    if (pref[i] > n) {
      cout << "-1";
      return 0;
    }
  }
  int d = n - pref[m - 1];
  vector<int> ans(m + 1);
  for (int i = 0; i < m; i++) ans[i] = i + 1;
  ans[m] = n + 1;
  for (int i = m - 1; i > 0; i--) {
    if (d <= 0) break;
    d -= arr[i] - (pref[i] - pref[i - 1]);
    ans[i] = ans[i + 1] - arr[i];
  }
  for (int i = 0; i < m; i++) cout << ans[i] << " ";
  return 0;
}
