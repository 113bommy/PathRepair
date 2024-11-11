#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long curr = 0, x = 1, sum = 0;
    for (long long i = 0;; i++) {
      if (sum + x * 3 >= n) {
        curr = i;
        n -= sum;
        break;
      }
      sum += x * 3;
      x *= 4;
    }
    n--;
    long long p = 1 << (2 * curr);
    long long a = n / 3, b = (n) % 3;
    p += a;
    if (b == 0)
      cout << p << "\n";
    else {
      for (long long ct = 0; ct < 2; ct++) {
        long long m = 0;
        for (long long i = 0; i < 60; i += 2) {
          long long j, k;
          if ((p & (1LL << i)))
            j = 1;
          else
            j = 0;
          if ((p & (1LL << (i + 1))))
            k = 1;
          else
            k = 0;
          if (j == 0 && k == 0)
            ;
          else if (j == 1 && k == 0)
            m += (1LL << (i + 1));
          else if (j == 0 && k == 1)
            m += (1LL << i) + (1LL << (i + 1));
          else
            m += (1LL << i);
        }
        p = m;
        b--;
        if (b == 0) cout << m << "\n";
      }
    }
  }
  return 0;
}
