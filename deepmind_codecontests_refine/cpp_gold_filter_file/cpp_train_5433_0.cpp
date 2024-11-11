#include <bits/stdc++.h>
const int N = 40;
int n, m;
int leftNum, rightNum;
int leftMask, rightMask;
long long ans, adj[N];
int L2L[1 << 20], R2R[1 << 20], L2R[1 << 20];
int a[1 << 20];
bool bipartite = 1;
int color[N];
long long vis;
void dfs(int x) {
  vis |= 1LL << x;
  for (long long b = adj[x]; b; b &= b - 1) {
    int i = __builtin_ctzll(b);
    if (vis >> i & 1) {
      if (color[i] == color[x]) bipartite = 0;
    } else {
      color[i] = !color[x];
      dfs(i);
    }
  }
}
void subset_sum(int *a, int lim) {
  for (int i = 1; i < lim; i <<= 1)
    for (int j = 0; j < lim; j += i << 1)
      for (int k = 0; k < i; ++k) a[k + j + i] += a[k + j];
}
int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  std::cin >> n >> m;
  leftNum = n >> 1, rightNum = n - leftNum;
  leftMask = ~(-1 << leftNum), rightMask = ~(-1 << rightNum);
  for (int i = 0; i < m; ++i) {
    int x, y;
    std::cin >> x >> y, --x, --y;
    if (x > y) std::swap(x, y);
    adj[x] |= 1LL << y, adj[y] |= 1LL << x;
    if (y < leftNum) {
      L2L[1 << x] |= 1 << y;
    } else if (x >= leftNum) {
      R2R[1 << x - leftNum] |= 1 << y - leftNum;
    } else {
      L2R[1 << x] |= 1 << y - leftNum;
    }
  }
  ans = 1LL << n;
  for (int i = 1; i <= leftMask; ++i) {
    L2L[i] = L2L[i & -i] | L2L[i & i - 1];
    L2R[i] = L2R[i & -i] | L2R[i & i - 1];
  }
  for (int i = 1; i <= rightMask; ++i) R2R[i] = R2R[i & -i] | R2R[i & i - 1];
  for (int i = 0; i <= rightMask; ++i)
    if ((R2R[i] & i) == 0) ++a[i];
  subset_sum(a, 1 << rightNum);
  for (int i = 0; i <= leftMask; ++i)
    if (!(L2L[i] & i)) ans -= a[rightMask ^ L2R[i]] * 2;
  int isolate = 0;
  for (int i = 0; i < n; ++i) isolate += !adj[i];
  ans += 1LL << isolate + 1;
  int part = 0;
  for (int i = 0; i < n; ++i) color[i] = -1;
  for (int i = 0; i < n; ++i)
    if (color[i] == -1) {
      color[i] = 0, dfs(i), ++part;
    }
  if (!bipartite) ans -= 1LL << part;
  if (isolate == n) ans -= 1LL << n;
  std::cout << ans << '\n';
  return 0;
}
