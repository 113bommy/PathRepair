#include <bits/stdc++.h>
using namespace std;
const int Mod = 1e9 + 7;
const int N = 1e5 + 10, K = 13;
int Pow(int x, int e) {
  int ret = 1;
  while (e) {
    if (e & 1) ret = 1ll * ret * x % Mod;
    x = 1ll * x * x % Mod;
    e >>= 1;
  }
  return ret;
}
int fa[N], sz[N];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
int cnt[N];
int A[N];
vector<int> dp[N], inv[N];
int n, k;
int len[K], sumlen[1 << K], fac[K];
int ans, mx;
int s, mask[K], msz[K];
void DFS(int cur, int way) {
  if (cur == k) {
    int nway = way, nmx = mx;
    for (int i = 1; i <= s; i++) {
      int x = sumlen[mask[i]];
      nway = 1ll * nway * inv[x][cnt[x]] % Mod * dp[x][cnt[x] + 1] % Mod;
      nmx = max(nmx, x);
      ++cnt[x];
    }
    if (nmx <= 2)
      ans = (ans + 1) % Mod;
    else
      ans = (ans + nway) % Mod;
    for (int i = 1; i <= s; i++) {
      int x = sumlen[mask[i]];
      --cnt[x];
    }
  } else {
    mask[++s] = (1 << (cur)), msz[s] = 1;
    DFS(cur + 1, way);
    --s;
    for (int i = 1; i <= s; i++)
      mask[i] ^= (1 << (cur)), DFS(cur + 1, 1ll * way * msz[i]++ % Mod),
          --msz[i], mask[i] ^= (1 << (cur));
  }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) fa[i] = i, sz[i] = 1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &A[i]);
    if (A[i]) {
      int x = find(i), y = find(A[i]);
      if (x == y)
        cnt[sz[x]]++, sz[x] = -1;
      else
        fa[x] = y, sz[y] += sz[x];
    }
  }
  int c = 0;
  for (int i = 1; i <= n; i++)
    if (fa[i] == i && sz[i] != -1) len[c++] = sz[i];
  assert(c == k);
  for (int i = 0; i <= (1 << (c)) - 1; i++)
    for (int j = 0; j <= c - 1; j++)
      if (i & (1 << (j))) sumlen[i] += len[j];
  fac[0] = 1;
  for (int i = 1; i <= k; i++) fac[i] = 1ll * fac[i - 1] * i % Mod;
  for (int i = 1; i <= n; i++) {
    dp[i].resize(n / i + 1);
    dp[i][0] = 1;
    for (int j = 1; j <= n / i; j++) {
      dp[i][j] = 1ll * dp[i][j - 1] * i % Mod;
      if (j > 1) dp[i][j] = (dp[i][j] + 1ll * dp[i][j - 2] * (j - 1) * i) % Mod;
    }
    for (int j = 0; j <= n / i; j++) inv[i].push_back(Pow(dp[i][j], Mod - 2));
  }
  int way = 1;
  mx = 0;
  for (int i = 1; i <= n; i++) {
    way = 1ll * way * dp[i][cnt[i]] % Mod;
    if (cnt[i]) mx = i;
  }
  DFS(0, way);
  printf("%d\n", ans);
  return 0;
}
