#include <bits/stdc++.h>
std::vector<long long> p[10], q[10];
int n, m, k, g[1000005], p1, p2;
long long f[1000005], ans = 1000000000000000000;
int choose(int &x0, int &x1, int &x2) {
  long long s0 = 1000000000000000000, s1 = 1000000000000000000,
            s2 = 1000000000000000000;
  if (x0 + 1 <= p[0].size()) s0 = q[0][x0];
  if (x1 + 1 <= p[1].size()) s1 = q[1][x1];
  if (x2 + 1 <= p[2].size()) s2 = q[2][x2];
  if (s0 == 1000000000000000000 && s1 == 1000000000000000000 &&
      s2 == 1000000000000000000)
    return 1;
  if (s0 <= s1 && s0 <= s2)
    ++x0;
  else if (s1 <= s0 && s1 <= s2)
    ++x1;
  else if (s2 <= s0 && s2 <= s1)
    ++x2;
  return 0;
}
int del(int &x0, int &x1, int &x2, int y) {
  long long s0 = -1000000000000000000, s1 = -1000000000000000000,
            s2 = -1000000000000000000;
  if (x0) s0 = q[0][x0 - 1];
  if (x1 > y) s1 = q[1][x1 - 1];
  if (x2 > y) s2 = q[2][x2 - 1];
  if (s0 == -1000000000000000000 && s1 == -1000000000000000000 &&
      s2 == -1000000000000000000)
    return 1;
  if (s0 >= s1 && s0 >= s2)
    --x0;
  else if (s1 >= s0 && s1 >= s2)
    --x1;
  else if (s2 >= s0 && s2 >= s1)
    --x2;
  return 0;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) scanf("%lld", &f[i]);
  scanf("%d", &p1);
  for (int i = 1; i <= p1; i++) {
    int x;
    scanf("%d", &x);
    g[x] = g[x] + 1;
  }
  scanf("%d", &p2);
  for (int i = 1; i <= p2; i++) {
    int x;
    scanf("%d", &x);
    g[x] = g[x] + 2;
  }
  for (int i = 1; i <= n; i++) p[g[i]].push_back(f[i]);
  for (int i = 0; i <= 3; i++) {
    std::sort(p[i].begin(), p[i].end());
    q[i].resize(p[i].size());
    for (int j = 0; j < q[i].size(); j++) q[i][j] = p[i][j];
    for (int j = 0; j < p[i].size(); j++)
      p[i][j] = (j ? p[i][j - 1] : 0) + p[i][j];
  }
  int l0 = 0, l1 = 0, l2 = 0;
  for (int i = m; i >= 0; i--) {
    int x = i, y = k - i, z, flag = 0;
    if (y < 0) y = 0;
    z = m - x - 2 * y;
    if (x > p[3].size() || y > p[1].size() || y > p[2].size() || z < 0 ||
        z > n - p[3].size())
      continue;
    while (l1 < y) ++l1;
    while (l2 < y) ++l2;
    if (l1 > p[1].size() || l2 > p[2].size()) continue;
    while (i + l0 + l1 + l2 > m && !flag) flag = del(l0, l1, l2, y);
    while (i + l0 + l1 + l2 < m && !flag) flag = choose(l0, l1, l2);
    if (flag) continue;
    ans = std::min(ans, (i ? p[3][i - 1] : 0) + (l1 ? p[1][l1 - 1] : 0) +
                            (l2 ? p[2][l2 - 1] : 0) + (l0 ? p[0][l0 - 1] : 0));
  }
  printf("%lld\n", ans == 1000000000000000000 ? -1 : ans);
  return 0;
}
