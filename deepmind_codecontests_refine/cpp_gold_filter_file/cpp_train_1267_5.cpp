#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long n, x, y;
  cin >> n >> x >> y;
  long long arr[n + 1];
  long long check = 1;
  for (long long i = 1; i <= n; ++i) {
    cin >> arr[i];
  }
  for (long long i = 1; i <= n; ++i) {
    for (long long j = i - 1; j >= i - x && j >= 1; --j) {
      if (arr[j] > arr[i]) {
        check *= 1;
      } else
        check *= 0;
    }
    for (long long j = i + 1; j <= i + y && j <= n; ++j) {
      if (arr[j] > arr[i]) {
        check *= 1;
      } else
        check *= 0;
    }
    if (check == 1) {
      cout << i << endl;
      return 0;
    } else
      check = 1;
  }
}
