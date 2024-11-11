#include <bits/stdc++.h>
using namespace std;
long long n = 0;
const long long mod = 1e9 + 7;
long long sol(long long tc) {
  cin >> n;
  long long arr[n];
  for (long long i = 0; i < n; i++) cin >> arr[i];
  bool flag = true;
  if (n > 1) {
    bool inc = (arr[1] > arr[0]), dec = false;
    for (long long i = 2; i < n; i++) {
      if (arr[i] == arr[i - 1] && !dec) {
        inc = false;
        continue;
      } else if (arr[i] > arr[i - 1] && inc)
        continue;
      else if (arr[i] < arr[i - 1]) {
        dec = true;
        inc = false;
      } else {
        flag = false;
        break;
      }
    }
  }
  if (flag)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0LL;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long tc = 1;
  while (tc--) {
    sol(tc);
  }
  return 0;
}
