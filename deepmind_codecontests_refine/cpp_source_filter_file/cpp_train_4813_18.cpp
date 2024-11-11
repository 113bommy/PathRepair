#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b, c;
    cin >> a >> b >> c;
    long long mx = LONG_MAX, fst = 0, scnd = 0, thrd = 0;
    for (long long i = 1; i <= 10000; i++) {
      for (long long j = i; j <= 10000; j += i) {
        for (long long k = j; k <= 10000; k += j) {
          long long temp = abs(a - i) + abs(b - j) + abs(c - k);
          if (temp < mx) {
            mx = temp;
            fst = i;
            scnd = j;
            thrd = k;
          }
        }
      }
    }
    cout << mx << endl;
    cout << fst << " " << scnd << " " << thrd << endl;
  }
  return 0;
}
