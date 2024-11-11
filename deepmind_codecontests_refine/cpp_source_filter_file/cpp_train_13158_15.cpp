#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, j, k, n, m, t, x, y;
  long long s = 0;
  cin >> n >> k;
  vector<long long> arr(n, 0);
  vector<long long> dp(n, 0);
  vector<long long> a;
  for (i = 0; i < n; i++) {
    cin >> arr[i];
    s += arr[i];
    dp[i] = s;
  }
  a.push_back(dp[k - 1]);
  for (i = 0; i < n - k; i++) {
    a.push_back(dp[i + k] - dp[i]);
  }
  m = -1, s = 0;
  vector<int> b(a.size(), 0);
  for (i = a.size() - 1; i >= 0; i--) {
    m = max(m, a[i]);
    b[i] = m;
  }
  for (i = 0; i < a.size() - k; i++) {
    if (a[i] + b[i + k] > s) s = a[i] + b[i + k], x = i;
  }
  for (i = x + k; i < a.size(); i++) {
    if (a[i] == s - a[x]) {
      y = i;
      break;
    }
  }
  cout << x + 1 << " " << y + 1 << endl;
}
