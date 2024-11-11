#include <bits/stdc++.h>
using namespace std;
const int maxn = (1 << 23) + 10;
inline int read() {
  register int p = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    p = p * 10 + ch - '0';
    ch = getchar();
  }
  return p * f;
}
inline int qpow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = res * a;
    b >>= 1;
    a = a * a;
  }
  return res;
}
int dp[maxn], cnt[maxn], lg[maxn];
int n;
int fa[50], sz[50];
inline int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
int m, id[50], nxt[50];
char mp[50][50];
inline bool check(int mid) {
  int res = 0;
  for (int i = 0; i < (1 << m); i++)
    res += (((m - cnt[i]) & 1) ? -1 : 1) * qpow(dp[i], mid);
  return res != 0;
}
int main() {
  n = read();
  for (int i = 0; i < n; i++) fa[i] = i, sz[i] = 1, id[i] = -1;
  for (int i = 0; i < n; i++) {
    scanf("%s", mp[i]);
    for (int j = 0; j < n; j++)
      if (mp[i][j] == 'A' && find(i) != find(j)) {
        sz[find(i)] += sz[find(j)];
        fa[find(j)] = find(i);
      }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (mp[i][j] == 'X' && find(i) == find(j)) {
        puts("-1");
        return 0;
      }
  for (int i = 0; i < n; i++)
    if (find(i) == i && sz[i] > 1) id[i] = ++m;
  if (!m) {
    printf("%d\n", n - 1);
    return 0;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (mp[i][j] == 'X') {
        int a = id[find(i)], b = id[find(j)];
        if (a != -1 && b != -1) nxt[a] |= (1 << b), nxt[b] |= (1 << a);
      }
  for (int i = 0; i < m; i++) lg[1 << i] = i;
  for (int i = 1; i < (1 << m); i++) {
    int x = lg[i & -i];
    dp[i] = 1 + dp[i ^ (1 << x)] + dp[i ^ (1 << x) ^ (i & nxt[x])];
    cnt[i] = cnt[i ^ (1 << x)] + 1;
  }
  int l = 1, r = m, ans;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%d\n", ans + n - 1);
}
