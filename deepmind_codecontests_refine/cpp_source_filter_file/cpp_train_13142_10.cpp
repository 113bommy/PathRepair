#include <bits/stdc++.h>
using namespace std;
int seq(long long a, long long k) {
  for (long long i = 0; i < k; i++) {
    long long min = INT_MAX, max = INT_MIN;
    long long temp = a;
    while (a > 0) {
      long long r = a % 10;
      if (r > max) max = r;
      if (r < min) min = r;
      a = a / 10;
    }
    a = temp;
    if (min == 0) {
      break;
    }
    a = a + max * min;
  }
  return a;
}
int main() {
  long long t;
  cin >> t;
  long long a, k, fn;
  for (long long i = 0; i < t; i++) {
    cin >> a >> k;
    fn = seq(a, k - 1);
    cout << fn << endl;
  }
  return 0;
}
