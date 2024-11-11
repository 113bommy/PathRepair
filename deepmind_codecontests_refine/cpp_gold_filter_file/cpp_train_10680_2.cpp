#include <bits/stdc++.h>
using namespace std;
vector<int> a[5010];
int n, A, B, cnt;
char s[1000010];
int num[5010];
vector<int> gold[5010], tgold[5010];
int gcdv[5010];
int dfn[5010], low[5010], st[5010], top, nq[5010];
int gcd(int x, int y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
char w[5010][5010];
int tot;
void tar(int x) {
  dfn[x] = low[x] = ++cnt;
  st[++top] = x;
  for (int u = 0; u < n; u++) {
    if (w[x][u] == '0') continue;
    if (dfn[u] == 0) {
      tar(u);
      low[x] = min(low[x], low[u]);
    } else if (nq[u] == 0)
      low[x] = min(low[x], dfn[u]);
  }
  if (dfn[x] == low[x]) {
    nq[x] = ++tot;
    gcdv[tot] = num[x];
    while (st[top] != x) {
      nq[st[top]] = tot;
      gcdv[tot] = gcd(gcdv[tot], num[st[top]]);
      top--;
    }
    tgold[tot].resize(gcdv[tot]);
    top--;
  }
}
int totg[5010], mx[5010], mn[5010], fac[5010], inv[5010];
long long C(int x, int y) {
  return (long long)fac[x] * inv[y] % 1000000007 * inv[x - y] % 1000000007;
}
int main() {
  scanf("%d%d%d", &n, &A, &B);
  for (int i = 0; i < n; i++) scanf("%s", w[i]);
  for (int i = 0; i < n; i++) {
    scanf("%d", &num[i]);
    scanf("%s", s);
    for (int j = 0; j < num[i]; j++) gold[i].push_back(s[j] - '0');
  }
  for (int i = 0; i < n; i++)
    if (dfn[i] == 0) tar(i);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < num[i]; j++)
      tgold[nq[i]][j % gcdv[nq[i]]] |= gold[i][j];
  for (int i = tot; i > 1; i--) {
    int now = gcd(gcdv[i], gcdv[i - 1]);
    for (int j = 0; j < gcdv[i]; j++) tgold[i - 1][j % now] |= tgold[i][j];
  }
  for (int i = 1; i <= tot; i++)
    for (int j = 0; j < gcdv[i]; j++)
      if (tgold[i][j]) totg[i]++;
  for (int i = 0; i < n; i++) {
    mx[i] = (long long)totg[nq[i]] * num[i] / gcdv[nq[i]];
    for (int j = 0; j < num[i]; j++)
      if (gold[i][j]) mn[i]++;
  }
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = (long long)fac[i - 1] * i % 1000000007;
  inv[0] = inv[1] = 1;
  for (int i = 2; i <= n; i++)
    inv[i] = (long long)inv[1000000007 % i] * (1000000007 - 1000000007 / i) %
             1000000007;
  for (int i = 2; i <= n; i++)
    inv[i] = (long long)inv[i - 1] * inv[i] % 1000000007;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int c1 = 0, c2 = 0;
    for (int j = 0; j < n; j++)
      if (mn[j] > mx[i]) c1++;
    if (c1 >= A) continue;
    for (int j = 0; j < n; j++)
      if (mn[j] <= mx[i] && (mx[j] > mx[i] || (mx[j] == mx[i] && j > i))) c2++;
    for (int j = min(B - 1, min(c2, A - 1 - c1)); B - j - 1 <= c1 && j >= 0;
         j--)
      ans = (ans + (long long)C(c2, j) * C(c1, B - j - 1) % 1000000007) %
            1000000007;
  }
  printf("%d\n", ans);
}
