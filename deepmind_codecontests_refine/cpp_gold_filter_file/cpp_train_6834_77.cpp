#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  if (n <= 36) {
    if (n % 2 == 0) {
      for (long long i = 0; i < n / 2; i++) {
        cout << "8";
      }
    } else {
      for (long long i = 0; i < n / 2; i++) {
        cout << "8";
      }
      cout << "6";
    }
  } else
    cout << "-1";
  return 0;
}
