#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, s = 0;
  cin >> n;
  long long arr[n][n];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }
  for (long long j = 0; j < n; j++) {
    for (long long i = 0; i < n; i++) {
      s = s + arr[i][j];
    }
    if (s != 0) {
      cout << "NO";
      break;
    }
  }
  if (s == 0) {
    cout << "YES";
  }
}
