#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k, i, j = 0, div, tSum = 0, sum = 0, cnt = 0;
  cin >> n >> k;
  long long a[n], post[k];
  for (i = 0; i < n; i++) {
    cin >> a[i];
    tSum += a[i];
  }
  div = tSum / k;
  i = 0;
  while (i < n) {
    while (sum < div) {
      sum += a[i];
      ++cnt;
      ++i;
    }
    if (sum == div) {
      post[j] = cnt;
      cnt = 0;
      sum = 0;
      ++j;
    } else {
      cout << "NO"
           << "\n";
      return;
    }
  }
  cout << "YES"
       << "\n";
  for (i = 0; i < k; i++) {
    cout << post[i] << " ";
  }
  cout << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long test = 1;
  while (test--) solve();
  return 0;
}
