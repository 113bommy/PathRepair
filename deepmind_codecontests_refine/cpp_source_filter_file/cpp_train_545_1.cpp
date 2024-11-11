#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int32_t main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t;
  t = 1;
  for (long long tc = 0; tc < t; tc++) {
    long long n;
    cin >> n;
    long long arr[n];
    for (long long i1 = 0; i1 < n; i1++) cin >> arr[i1];
    if (n == 1) {
      cout << 1 << " " << 1 << "\n";
      cout << 0 << "\n";
      cout << 1 << " " << 1 << "\n";
      cout << 0 << "\n";
      cout << 1 << " " << 1 << "\n";
      cout << -arr[0] << "\n";
      continue;
    }
    cout << 1 << " " << 1 << "\n";
    cout << -arr[0] << "\n";
    cout << 1 << " " << n << "\n";
    cout << 0 << " ";
    for (long long i = 1; i < n; i++) cout << "-" << n * arr[i] << " ";
    cout << "\n";
    cout << 2 << " " << n << "\n";
    for (long long i = 1; i < n; i++) cout << (n - 1) * arr[i] << " ";
    cout << "\n";
  }
  return 0;
}
