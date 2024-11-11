#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long n;
  long long flag = 0;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long mask = 1;
  for (long long i = 0; i < n; i++) {
    mask = mask << 1;
  }
  for (long long i = 0; i < mask; i++) {
    long long sum = 0;
    long long mask1 = i;
    for (long long j = 0; j < n; j++) {
      if (mask1 & 1) {
        sum += a[j];
      } else {
        sum -= a[j];
      }
      mask1 = mask1 >> 1;
    }
    if (sum % 360 == 0) flag = 1;
  }
  if (flag)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
