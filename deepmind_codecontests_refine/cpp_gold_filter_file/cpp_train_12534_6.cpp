#include <bits/stdc++.h>
const int N = 9;
int ans = 0x7fffffff, n, pnum[N], cnt;
long long a[N], root;
inline void getpnum() {
  for (int i = 1; i <= n; ++i) {
    long long x = a[i];
    for (long long j = 2; j * j <= x; ++j)
      for (; x % j == 0; x /= j) ++pnum[i];
    if (x != 1) ++pnum[i];
  }
}
void dfs2(const int idx, const int sum) {
  if (idx == 0) {
    ans = std::min(ans, sum + n + 1);
    return;
  }
  for (int i = n; i > idx; --i) {
    if (a[i] % a[idx] == 0) {
      a[i] /= a[idx];
      dfs2(idx - 1, sum);
      a[i] *= a[idx];
    }
  }
  dfs2(idx - 1, sum + pnum[idx]);
}
bool dfs1(const int idx) {
  if (idx == 0) {
    ans = pnum[n] + n;
    return 1;
  }
  for (int i = n; i > idx; --i) {
    if (a[i] % a[idx] == 0) {
      a[i] /= a[idx];
      if (dfs1(idx - 1)) {
        a[i] = a[i] * a[idx];
        return 1;
      }
      a[i] = a[i] * a[idx];
    }
  }
  return 0;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%I64d", a + i);
  std::sort(a + 1, a + 1 + n);
  root = a[n];
  getpnum();
  for (int i = 1; i <= n; ++i)
    if (pnum[i] == 1) ++cnt;
  if (!dfs1(n - 1)) dfs2(n, 0);
  printf("%d\n", ans - cnt);
}
