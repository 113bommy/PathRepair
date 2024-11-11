#include <bits/stdc++.h>
using namespace std;
const int N = 11;
const long long mod = 1e6 + 3;
long long p[N], r[mod];
long long Pow(long long x, long long y) {
  if (y == 1) return x;
  long long tmp = Pow(x, y / 2);
  return (y % 2 ? tmp * tmp % mod * x % mod : tmp * tmp % mod);
}
int main() {
  if (fopen("exam.inp", "r"))
    freopen("exam.inp", "r", stdin), freopen("exam.out", "w", stdout);
  for (int i = 0; i < mod; i++) r[i] = Pow(i, mod - 2);
  r[0] = 1;
  for (int i = 0; i < N; i++) {
    cout << "? " << i << endl;
    cin >> p[i];
    if (p[i] == 0) {
      cout << "! " << i << endl;
      return 0;
    }
  }
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) (p[i] *= r[(i - j + mod) % mod]) %= mod;
  for (int x = 11; x < mod; x++) {
    long long ret = 0;
    for (int i = 0; i < N; i++) (ret += p[i] * r[x - i]) %= mod;
    if (!ret) {
      cout << "! " << x << endl;
      return 0;
    }
  }
  cout << "! -1";
}
