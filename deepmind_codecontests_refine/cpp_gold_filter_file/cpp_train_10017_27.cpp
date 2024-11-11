#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e9 + 7;
void solve() {
  long long int n;
  cin >> n;
  long long int arr[n];
  long long int odd = 0, even = 0;
  for (long long int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] % 2) {
      odd++;
    } else {
      even++;
    }
  }
  long long int cnt = 0;
  if (odd % 2) {
    cnt += odd;
  } else {
    cnt += even;
  }
  cout << cnt << endl;
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
