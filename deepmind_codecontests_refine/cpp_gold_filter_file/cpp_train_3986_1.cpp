#include <bits/stdc++.h>
using namespace std;
const int modP = 1e9 + 7;
const long long oo = 1000000000000000LL;
const int maxN = 999999;
long long g[maxN + 10];
int k, F[6];
void knapsack() {
  fill(g, g + maxN + 10, -1);
  g[0] = 0;
  for (auto i = 0, d = 1; i < 6; ++i, d *= 10)
    for (int p = 1, left = 3 * k; left > 0; p *= 2) {
      auto t = min(p, left);
      auto w = 1ll * t * d * 3, v = 1ll * t * F[i];
      for (auto s = maxN; s >= w; s -= 3) {
        if (g[s - w] != -1) g[s] = max(g[s], g[s - w] + v);
      }
      left -= t;
    }
  for (auto i = 0, d = 1; i < 6; ++i, d *= 10)
    for (auto s = maxN; s >= 1; --s)
      for (auto j = 0; j * d <= min(9 * d, s); ++j) {
        auto tmp = (j % 3) ? 0ll : 1ll * (j / 3) * F[i];
        if (g[s - j * d] != -1) {
          g[s] = max(g[s], g[s - j * d] + tmp);
        }
      }
}
int main() {
  cin >> k;
  --k;
  for (auto i = 0; i < 6; ++i) cin >> F[i];
  knapsack();
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    cout << g[n] << endl;
  }
}
