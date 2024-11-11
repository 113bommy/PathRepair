#include <bits/stdc++.h>
using namespace std;
long long pow(long long a, long long b, long long MOD) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x * y);
      if (x > MOD) x %= MOD;
    }
    y = (y * y);
    if (y > MOD) y %= MOD;
    b /= 2;
  }
  return x;
}
long long modInverse(long long a, long long m) { return pow(a, m - 2, m); }
long long arr[(int)1e5 + 1 + 1], val[(int)1e5 + 1];
int main() {
  long long n;
  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      val[i] = 1;
    }
    long long ans = 1;
    for (int i = 1; i < n; i++) {
      if (arr[i] >= arr[i - 1]) {
        val[i] = max(val[i], val[i - 1] + 1);
      }
      ans = max(ans, val[i]);
    }
    cout << ans << endl;
  }
}
