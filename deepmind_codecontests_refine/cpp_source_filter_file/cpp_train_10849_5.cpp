#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int n, siz[1 << N], f[1 << N];
long long a[N], s[1 << N];
bool can[1 << N];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (!a[i]) --i, --n;
  }
  for (int i = 1; i < (1 << n); i++) {
    siz[i] = siz[i >> 1] + (i & 1);
    for (int j = 0; j < n; j++)
      if (i >> j & 1) s[i] += a[j];
    if ((s[i] + siz[i]) & 1) {
      long long lo = s[i] - siz[i] + 1, hi = s[i] + siz[i] - 1;
      for (int j = i; ((--j) &= i) && !can[i];)
        if (lo <= 2 * s[j] && 2 * s[j] <= hi) can[i] = 1;
    }
  }
  for (int i = 1; i < (1 << n); i++)
    if (can[i] && !f[i]) {
      f[i] = 1;
      int s = (1 << n) - 1 - i;
      for (int j = s; j; j = (j - 1) & s) f[i | j] = max(f[i | j], f[i] + 1);
    }
  cout << n - f[(1 << n) - 1];
  return 0;
}
