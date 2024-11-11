#include <bits/stdc++.h>
using namespace std;
const int maxn = 310;
bool s[maxn], f[maxn][maxn];
int n, m, k, u[maxn], v[maxn];
bool invalid(const int a, const int b) {
  return f[a][b] || (a == v[0] && s[b]) || (b == v[0] && s[a]);
}
void solve() {
  for (int i = 2; i < k; ++i) {
    printf("%d %d\n", v[i - 1], v[i]);
    f[v[i - 1]][v[i]] = f[v[i]][v[i - 1]] = 1;
  }
  for (int i = 1; i < n - k; ++i) {
    printf("%d %d\n", u[i - 1], u[i]);
    f[u[i - 1]][u[i]] = f[u[i]][u[i - 1]] = 1;
  }
  printf("%d %d\n", u[0], v[0]);
  f[u[0]][v[0]] = f[v[0]][u[0]] = 1;
  printf("%d %d\n", u[0], v[1]);
  f[u[0]][v[1]] = f[v[1]][u[0]] = 1;
  int w = n - 1;
  for (int i = 1; i <= n && w < m; ++i) {
    for (int j = i + 1; j <= n && w < m; ++j) {
      if (!invalid(i, j)) {
        printf("%d %d\n", i, j);
        ++w;
      }
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < k; ++i) {
    scanf("%d", &v[i]);
    s[v[i]] = 1;
  }
  int l = 0;
  for (int i = 1; i <= n; ++i) {
    if (!s[i]) {
      u[l++] = i;
    }
  }
  int e = n * (n - 1) / 2 - k + 1;
  if (k == n || e < m) {
    printf("-1\n");
  } else {
    solve();
  }
  return 0;
}
