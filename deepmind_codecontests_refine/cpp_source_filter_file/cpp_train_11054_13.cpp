#include <bits/stdc++.h>
using namespace std;
long long n, x;
long long num[21], f[1 << 20], g[21][21];
int main() {
  cin >> n;
  for (; n--;) {
    cin >> x;
    ++num[--x];
    for (int i = 0; i < 20; ++i) g[x][i] += num[i];
  }
  memset(f, 99999999, sizeof(f));
  f[0] = 0;
  for (int i = 0; i < 1 << 20; ++i)
    for (int j = 0; j < 20; ++j)
      if (!(i >> j & 1)) {
        long long tmp = f[i];
        for (int k = 0; k < 20; ++k)
          if (i >> k & 1) tmp += g[j][k];
        f[i | (1 << j)] = min(f[i | (1 << j)], tmp);
      }
  cout << f[(1 << 20) - 1];
}
