#include <bits/stdc++.h>
using namespace std;
long long int calc(int n, int k) {
  long long int res = 1;
  if (k > n - k) k = n - k;
  for (int i = 0; i < k; ++i) {
    res *= (long long)(n - i);
    res /= (long long)(i + 1);
  }
  return res % 998244353;
}
void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  vector<int> f(n + 1, -1), last(n + 1, -1), diff(n + 1, -1), freq(n + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    freq[arr[i]]++;
    if (f[arr[i]] == -1) {
      f[arr[i]] = i;
      last[arr[i]] = i;
      diff[arr[i]] = 0;
    } else {
      diff[arr[i]] = max(diff[arr[i]], i - last[arr[i]]);
      last[arr[i]] = i;
    }
  }
  sort(arr.begin(), arr.end());
  if (arr[0] == arr[n - 1]) {
    for (int i = 0; i < n; i++) {
      cout << arr[0] << " ";
    }
    cout << "\n";
    return;
  }
  int j = n + 1;
  vector<int> ans(n + 1, -1);
  for (int i = 1; i <= n; i++) {
    if (freq[i]) {
      int d = max(f[i] - 0, max(n - 1 - last[i], diff[i]));
      d++;
      if (j > d) {
        j = d;
        ans[n] = d;
      }
    }
  }
  int z = -1;
  for (int i = 1; i <= n; i++) {
    if (ans[i] != -1) z = ans[i];
    cout << z << " ";
  }
  cout << "\n";
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
