#include <bits/stdc++.h>
using namespace std;
const int MAXN = 35000000;
const int MD = 1051131;
const int rev2 = 525566;
int a[MAXN];
int m, s;
long long t;
int mult_coeff;
int powMod(int x, long long st) {
  int res = 1;
  while (st) {
    if (st & 1) {
      res = 1ll * res * x % MD;
    }
    st /= 2;
    x = 1ll * x * x % MD;
  }
  return res;
}
void getMult(int *a, int m, int k, long long t) {
  if (m == 0) {
    *a = 1ll * (*a) * powMod((1 + 1ll * k * rev2) % MD, t) % MD;
  } else {
    int half = 1 << (m - 1);
    for (int i = 0; i < half; ++i) {
      a[i] = (a[i] + a[i + half]) % MD;
      a[i + half] = (a[i] - 2 * a[i + half] + 2 * MD) % MD;
    }
    int kprime = (powMod(2, m - 1) + MD - 1) % MD;
    kprime = (kprime - 1ll * rev2 * k % MD + MD) % MD;
    k = (k + kprime) % MD;
    kprime = powMod((MD - kprime) % MD, t);
    for (int i = 0; i < half; ++i) {
      a[i + half] = 1ll * a[i + half] * kprime * rev2 % MD;
    }
    getMult(a, m - 1, k, t);
    for (int i = 0; i < half; ++i) {
      a[i] = 1ll * a[i] * mult_coeff % MD;
    }
    for (int i = 0; i < half; ++i) {
      a[i] = (a[i] + a[i + half]) % MD;
      a[i + half] = (a[i] - 2 * a[i + half] + 2 * MD) % MD;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> m >> t >> s;
  mult_coeff = powMod(2, t - 1);
  for (int i = 0; i < s; ++i) {
    cin >> a[i];
  }
  for (int i = s; i < (1 << m); ++i) {
    a[i] = (101 * a[i - s] + 10007) % MD;
  }
  getMult(a, m, 0, t);
  int res = 0;
  for (int i = 0; i < (1 << m); ++i) {
    res ^= a[i];
  }
  cout << res << '\n';
  return 0;
}
