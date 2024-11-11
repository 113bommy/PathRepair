#include <bits/stdc++.h>
using namespace std;
long long range(long long L) {
  L++;
  long long res = 0;
  for (long long k = 0, n = 1; n <= L; n <<= 1, k++) {
    int bit = 0;
    long long div = (1LL << k + 1);
    if (k == 0) {
      long long p = L / div;
      if (p & 1) bit = 1;
    }
    long long remain = L % div;
    if (remain - (div >> 1) >= 0 && (remain - (div >> 1)) & 1) bit = !bit;
    if (bit) res |= n;
  }
  return res;
}
int main() {
  for (int N; cin >> N;) {
    long long sum = 0;
    for (int i = 0; i < (int)(N); ++i) {
      long long m, x;
      cin >> x >> m;
      long long b = range(x - 1);
      long long a = range(x + m - 1);
      sum ^= b;
      sum ^= a;
    }
    if (sum == 0)
      cout << "bolik" << endl;
    else
      cout << "tolik" << endl;
  }
  return 0;
}
