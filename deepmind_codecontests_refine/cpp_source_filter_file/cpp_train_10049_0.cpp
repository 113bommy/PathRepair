#include <bits/stdc++.h>
using namespace std;
long long int lowBit(long long int n) {
  for (long long int i = 0; i < 30; i++) {
    long long int p = 1 << i;
    if (n & p) return 1 << i;
  }
}
int32_t main() {
  long long int n, k;
  cin >> n >> k;
  long long int kk = k;
  long long int y = k;
  long long int half = n / 2;
  long long int nn = n;
  nn--;
  long long int tmp = (nn * (nn + 1)) / 2;
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  if (k == half)
    cout << tmp << endl;
  else if (k > half) {
    long long int z = n - k;
    if (z & 1)
      cout << tmp - 1 << endl;
    else
      cout << tmp << endl;
  } else if (k < half) {
    long long int sm = 0;
    for (long long int i = n; i > y; i--) {
      if (k) {
        sm += (i - 1);
        k--;
      } else {
        sm += kk;
      }
    }
    for (long long int j = y; j >= 2; j--) sm += (j - 1);
    cout << sm << endl;
  }
}
