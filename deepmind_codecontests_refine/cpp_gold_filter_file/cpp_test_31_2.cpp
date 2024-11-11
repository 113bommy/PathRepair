#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long arr[n];
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
    }
    long long b[n];
    if (n % 2 == 0) {
      for (long long i = 0; i < n - 1; i = i + 2) {
        b[i] = arr[i + 1];
        b[i + 1] = -1 * arr[i];
      }
      for (long long i = 0; i < n; i++) {
        cout << b[i] << " ";
      }
      cout << "\n";
    } else {
      for (long long i = 3; i < n - 1; i = i + 2) {
        b[i] = arr[i + 1];
        b[i + 1] = -1 * arr[i];
      }
      if (arr[0] + arr[1] != 0) {
        cout << -arr[2] << " " << -arr[2] << " " << arr[0] + arr[1] << " ";
      } else if (arr[1] + arr[2] != 0) {
        cout << arr[1] + arr[2] << " " << -arr[0] << " " << -arr[0] << " ";
      } else {
        cout << -arr[1] << " " << arr[0] + arr[2] << " " << -arr[1] << " ";
      }
      for (long long i = 3; i < n; i++) {
        cout << b[i] << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}
