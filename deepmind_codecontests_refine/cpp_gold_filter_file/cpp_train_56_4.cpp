#include <bits/stdc++.h>
const int N = 400;
std::bitset<N> q[N][N], ans[N];
char map[N][N + 5], mode[N][N + 5];
int n, m, a, b;
int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  std::cin >> n >> m;
  for (int i = 0; i < n; ++i) std::cin >> map[i];
  std::cin >> a >> b;
  for (int i = 0; i < a; ++i) std::cin >> mode[i];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) ans[i].set(j);
  for (char c = 'a'; c <= 'z'; ++c) {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) q[i][j].reset();
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        if (map[i][j] == c)
          for (int k = 0; k < m; ++k) q[i][k].set((j + m - k) % m);
    for (int i = 0; i < a; ++i)
      for (int j = 0; j < b; ++j)
        if (mode[i][j] == c)
          for (int k = 0; k < n; ++k) ans[k] &= q[(k + i) % n][j % m];
  }
  for (int i = 0; i < n; ++i, std::cout << '\n')
    for (int j = 0; j < m; ++j) std::cout << (bool)ans[i].test(j);
  return 0;
}
