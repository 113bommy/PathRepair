#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 100;
const int mod = 998244353;
const int G = 3;
int n, A, B;
int poA[maxn] = {0};
int poinvA[maxn] = {0};
int power(int x, int y) {
  if (!y) return 1;
  int ret = power(x, y >> 1);
  ret = (long long)ret * ret % mod;
  if (y & 1) ret = (long long)ret * x % mod;
  return ret;
}
void init() {
  poA[0] = poinvA[0] = 1;
  for (int i = 1; i < maxn; ++i) {
    poA[i] = (long long)poA[i - 1] * i % mod;
  }
  poinvA[maxn - 1] = power(poA[maxn - 1], mod - 2);
  for (int i = maxn - 2; i >= 1; --i) {
    poinvA[i] = (long long)poinvA[i + 1] * (i + 1) % mod;
  }
}
int rev[maxn] = {0};
int bound = 0;
void init_rev() {
  for (int i = 0; i < bound; ++i) {
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) ? (bound >> 1) : 0);
  }
}
void NTT(int *a, bool inv) {
  for (int i = 0; i < bound; ++i) {
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  }
  for (int i = 1; i < bound; i <<= 1) {
    int wi = power(G, (mod - 1) / (2 * i));
    if (inv) wi = power(wi, mod - 2);
    for (int j = 0; j < bound; j += 2 * i) {
      int w = 1;
      for (int k = 0; k < i; ++k) {
        int x = a[j + k], y = (long long)a[j + k + i] * w % mod;
        a[j + k] = (x + y) % mod;
        a[j + k + i] = (x - y + mod) % mod;
        w = (long long)w * wi % mod;
      }
    }
  }
  if (inv) {
    int div = power(bound, mod - 2);
    for (int i = 0; i < bound; ++i) {
      a[i] = (long long)a[i] * div % mod;
    }
  }
}
int f[20][maxn] = {0};
void solve(int d, int L, int R) {
  if (L == R) {
    f[d][0] = L, f[d][1] = 1;
    return;
  }
  int mid = (L + R) >> 1;
  solve(d + 1, L, mid);
  int len1 = mid - L + 1;
  for (int i = 0; i <= len1; ++i) {
    f[d][i] = f[d + 1][i];
  }
  solve(d + 1, mid + 1, R);
  int len2 = R - mid;
  bound = 1;
  while (bound <= len1 + len2) {
    bound <<= 1;
  }
  for (int i = len1 + 1; i < bound; ++i) f[d][i] = 0;
  for (int i = len2 + 1; i < bound; ++i) f[d + 1][i] = 0;
  init_rev();
  NTT(f[d], 0), NTT(f[d + 1], 0);
  for (int i = 0; i < bound; ++i) {
    f[d][i] = (long long)f[d][i] * f[d + 1][i] % mod;
  }
  NTT(f[d], 1);
  int Len = (R - L + 1);
  for (int i = Len + 1; i < bound; ++i) {
    f[d][i] = 0;
  }
}
int C(int n, int m) {
  if (m > n) return 0;
  return (long long)poA[n] * poinvA[m] % mod * poinvA[n - m] % mod;
}
int main() {
  ios::sync_with_stdio(0);
  init();
  cin >> n >> A >> B;
  if (A + B - 1 > n || A == 0 || B == 0) {
    cout << 0 << endl;
    return 0;
  }
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  solve(0, 0, n - 2);
  int S = f[0][A + B - 2];
  cout << (long long)S * C(A + B - 2, A - 1) << endl;
  return 0;
}
