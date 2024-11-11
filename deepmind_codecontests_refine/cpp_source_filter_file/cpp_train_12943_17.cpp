#include <bits/stdc++.h>
using namespace std;
long long range(long long L) {
  L++;
  long long res = 0;
  for (long long k = 0, n = 1; n <= L; n <<= 1, k++) {
    int on = 0;
    if (k == 0 && L & 1) on = 1;
    long long div = (1LL << k + 1);
    long long remain = L & div - 1;
    if (remain - (div >> 1) >= 0 && (remain - (div >> 1)) & 1) on = !on;
    if (on) res |= n;
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
