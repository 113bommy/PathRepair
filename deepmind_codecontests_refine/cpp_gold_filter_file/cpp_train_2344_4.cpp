#include <bits/stdc++.h>
using namespace std;
long long mod, a[1000005];
inline void product(long long a[2][2], long long b[2][2], long long c[2][2]) {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      c[i][j] = 0;
      for (int k = 0; k < 2; k++) {
        (c[i][j] += a[i][k] * b[k][j]) %= mod;
      }
    }
  }
}
inline void power(long long a[2][2], long long pp, long long ret[2][2]) {
  ret[0][0] = ret[1][1] = 1;
  ret[1][0] = ret[0][1] = 0;
  long long tmp[2][2];
  while (pp) {
    if (pp & 1) {
      product(ret, a, tmp);
      memcpy(ret, tmp, sizeof(tmp));
    }
    product(a, a, tmp);
    memcpy(a, tmp, sizeof(tmp));
    pp >>= 1;
  }
}
inline long long getMax(long long x, long long m, long long M) {
  long long a[2][2] = {{1, 1}, {1, 0}};
  long long b[2][2];
  power(a, x, b);
  return (M * b[0][0] + m * b[0][1]) % mod;
}
inline long long getSum(long long sum, long long mM, long long y) {
  long long a[2][2] = {{3, (mod - mM) % mod}, {0, 1}};
  long long b[2][2];
  power(a, y, b);
  return (sum * b[0][0] + b[0][1]) % mod;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout << setprecision(32);
  int n;
  long long x, y;
  cin >> n >> x >> y >> mod;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n == 1) {
    cout << a[0] % mod;
    exit(0);
  }
  long long sum = accumulate(a, a + n, 0LL) % mod;
  sum = getSum(sum, (a[0] + a[n - 1]) % mod, x);
  long long mn = a[0], mx = getMax(x, a[n - 2], a[n - 1]);
  cout << getSum(sum, (mn + mx) % mod, y);
  return 0;
}
