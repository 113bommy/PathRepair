#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
constexpr int inf = 1e9;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
    }
    int u = 1 << n;
    std::vector<int> sv;
    std::vector<int> dl;
    std::vector<int> h(u * 2, 0);
    std::vector<std::vector<int>> f(n + 1, std::vector<int>(u * 2, 0));
    std::vector<std::vector<int>> g(n + 1, std::vector<int>(u * 2, 0));
    for (int l = 0; l < n; l++) {
      bool found = false;
      for (int s = 0; s < u; s++) {
        if (__builtin_popcount(s) == l) {
          sv.clear(), sv.emplace_back(0);
          dl.clear();
          for (int i = 0; i < n; i++) {
            if (s >> i & 1) {
              dl.emplace_back(i);
            } else {
              sv.emplace_back(i);
            }
          }
          int uu = 1 << (int)dl.size();
          for (int i = 0; i < uu; i++) {
            h[i] = 0;
            for (int j = 0; j < (int)dl.size(); j++) {
              if (i >> j & 1) {
                h[i] += a[dl[j]];
              }
            }
          }
          f[0][0] = 0;
          for (int i = 1; i < uu; i++) {
            f[0][i] = inf;
          }
          for (int i = 1; i < (int)sv.size(); i++) {
            for (int j = 0; j < uu; j++) {
              f[i][j] = inf;
              if (a[sv[i]] > f[i - 1][j]) {
                f[i][j] = a[sv[i]];
                g[i][j] = 0;
              } else {
                for (int k = j; k; --k &= j) {
                  if (a[sv[i]] + h[k] > f[i - 1][j ^ k] &&
                      a[sv[i]] + h[k] < f[i][j]) {
                    f[i][j] = a[sv[i]] + h[k];
                    g[i][j] = k;
                  }
                }
              }
            }
          }
          if (f[(int)sv.size() - 1][uu - 1] != inf) {
            found = true;
            break;
          }
        }
      }
      if (found) {
        std::cout << l << "\n";
        std::vector<int> p(n);
        std::iota(p.begin(), p.end(), 0);
        int k = 1 << (int)dl.size();
        --k;
        for (int i = (int)sv.size() - 1; i > 0; --i) {
          for (int j = 0; j < (int)dl.size(); j++) {
            if (g[i][k] >> j & 1) {
              std::cout << p[dl[j]] + 1 << " " << p[sv[i]] + 1 << "\n";
              for (int t = dl[j]; t < n; ++t) {
                --p[l];
              }
            }
          }
          k ^= g[i][k];
        }
        break;
      }
    }
  }
  return 0;
}
