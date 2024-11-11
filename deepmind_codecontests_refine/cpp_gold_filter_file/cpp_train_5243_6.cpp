#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long z[50];
long long p[50] = {0,       2,       3,       5,        7,       13,
                   17,      19,      31,      61,       89,      107,
                   127,     521,     607,     1279,     2203,    2281,
                   3217,    4253,    4423,    9689,     9941,    11213,
                   19937,   21701,   23209,   44497,    86243,   110503,
                   132049,  216091,  756839,  859433,   1257787, 1398269,
                   2976221, 3021377, 6972593, 13466917, 20996011};
inline long long qpow(long long a, long long b) {
  long long c = 1;
  while (b) {
    if (b & 1) c = c * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return c;
}
int main() {
  for (int i = 1; i <= 40; ++i) {
    z[i] = qpow(2, p[i] - 1) - 1;
    z[i] = (z[i] % MOD + MOD) % MOD;
  }
  int n;
  cin >> n;
  cout << z[n] << endl;
}
