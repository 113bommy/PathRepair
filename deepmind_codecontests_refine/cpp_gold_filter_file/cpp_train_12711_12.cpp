#include <bits/stdc++.h>
using namespace std;
namespace BlueQuantum {
int const M = 21, N = (1 << M) + 5;
int m, n;
char s[N], t[N];
long long a[N], b[N], c[N];
inline void FWT(long long f[], int typ) {
  for (int len = 1; len < n; len <<= 1) {
    for (int i = 0; i < n; i += len << 1) {
      for (int j = 0; j < len; j++) {
        f[i + j + len] += typ * f[i + j];
      }
    }
  }
}
inline int main() {
  cin >> m >> s >> t;
  n = 1 << m;
  for (int i = 0; i < n; ++i) {
    a[i] = (long long)(s[i] - '0') << (long long)(__builtin_popcount(i) << 1LL);
  }
  for (int i = 0; i < n; ++i) {
    b[i] = (long long)(t[i] - '0') << (long long)(__builtin_popcount(i) << 1LL);
  }
  FWT(a, 1);
  FWT(b, 1);
  for (int i = 0; i < n; ++i) c[i] = a[i] * b[i];
  FWT(c, -1);
  for (int i = 0; i < n; ++i)
    cout << char((c[i] >> (__builtin_popcount(i) << 1LL) & 3) + '0');
  return 0;
}
}  // namespace BlueQuantum
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  return BlueQuantum::main();
}
