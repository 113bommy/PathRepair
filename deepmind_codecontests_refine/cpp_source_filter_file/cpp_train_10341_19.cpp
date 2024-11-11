#include <bits/stdc++.h>
using namespace std;
const int iinf = 0x3f3f3f3f;
const long long linf = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
void fmod(int& first) {
  first += first >> 31 & mod, assert(first >= 0 && first < mod);
}
const int N = 1e6;
int n, f[N], sf[N], g[N << 1], sg[N << 1];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n;
  sf[0] = f[0] = sg[0] = g[0] = 1;
  for (int i = (1), iE = (n); i < iE; i++) {
    if (i & 1)
      fmod(f[i] = (f[i - 1] << 1) - mod);
    else
      f[i] = f[i - 1];
    fmod(sf[i] = sf[i - 1] + f[i] - mod);
  }
  for (int i = (1), iE = (n * 2); i < iE; i++) {
    if ((i & 3) == 2)
      fmod(g[i] = 1ll * sf[(i - 2) >> 1] * g[i - 1] % mod - mod);
    else
      g[i] = g[i - 1];
    fmod(sg[i] = sg[i - 1] + g[i] - mod);
  }
  cout << (1ll * sg[n * 2 - 3] * sg[n * 2 - 3] + 1) % mod * 2 % mod << '\n';
  return 0;
}
