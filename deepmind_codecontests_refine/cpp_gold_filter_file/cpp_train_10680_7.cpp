#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
const int M = 2000005;
const int mo = 1000000007;
bool e[N][N];
int dfn[N], low[N], vis[N];
int n, A, B, tot, fac[N], inv[N];
int l[N], G[N], be[N], stk[N];
int lo[N], hi[N], ans;
vector<int> v[N], ok[N];
char s[M];
void init() {
  fac[0] = inv[0] = inv[1] = 1;
  for (int i = (int)(2); i <= (int)(N - 1); i++)
    inv[i] = 1ll * inv[mo % i] * (mo - mo / i) % mo;
  for (int i = (int)(1); i <= (int)(N - 1); i++)
    inv[i] = 1ll * inv[i - 1] * inv[i] % mo;
  for (int i = (int)(1); i <= (int)(N - 1); i++)
    fac[i] = 1ll * fac[i - 1] * i % mo;
}
int C(int x, int y) {
  if (x < 0 || y < 0 || y > x) return 0;
  return 1ll * fac[x] * inv[y] % mo * inv[x - y] % mo;
}
void tarjan(int x) {
  dfn[x] = low[x] = ++*dfn;
  vis[x] = 1;
  stk[++*stk] = x;
  for (int i = (int)(1); i <= (int)(n); i++)
    if (i != x && e[x][i]) {
      if (!dfn[i]) {
        tarjan(i);
        low[x] = min(low[x], low[i]);
      } else if (vis[i])
        low[x] = min(low[x], dfn[i]);
    }
  if (low[x] == dfn[x]) {
    ++tot;
    int y = 19260817;
    for (; y != x;) {
      y = stk[(*stk)--];
      vis[y] = 0;
      be[y] = tot;
    }
  }
}
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
int main() {
  scanf("%d%d%d", &n, &A, &B);
  for (int i = (int)(1); i <= (int)(n); i++) {
    scanf("%s", s + 1);
    for (int j = (int)(1); j <= (int)(n); j++) e[i][j] += (s[j] == '1');
  }
  for (int i = (int)(1); i <= (int)(n); i++) {
    scanf("%d%s", &l[i], s + 1);
    for (int j = (int)(1); j <= (int)(l[i]); j++) v[i].push_back(s[j] == '1');
  }
  for (int i = (int)(1); i <= (int)(n); i++)
    if (!dfn[i]) tarjan(i);
  for (int i = (int)(1); i <= (int)(n); i++) G[be[i]] = gcd(G[be[i]], l[i]);
  for (int i = (int)(1); i <= (int)(tot); i++) ok[i].resize(G[i]);
  for (int i = (int)(1); i <= (int)(n); i++)
    for (int j = (int)(0); j <= (int)(l[i] - 1); j++)
      ok[be[i]][j % G[be[i]]] |= v[i][j];
  for (int i = (int)(tot); i >= (int)(2); i--) {
    static int OK[M];
    int l = gcd(G[i], G[i - 1]);
    for (int j = (int)(0); j <= (int)(l - 1); j++) OK[j] = 0;
    for (int j = (int)(0); j <= (int)(G[i] - 1); j++) OK[j % l] |= ok[i][j];
    for (int j = (int)(0); j <= (int)(G[i - 1] - 1); j++)
      ok[i - 1][j] |= OK[j % l];
  }
  for (int i = (int)(1); i <= (int)(n); i++) {
    for (int j = (int)(0); j <= (int)(l[i] - 1); j++) lo[i] += v[i][j];
    for (int j = (int)(0); j <= (int)(l[i] - 1); j++)
      hi[i] += ok[be[i]][j % G[be[i]]];
  }
  init();
  for (int i = (int)(1); i <= (int)(n); i++)
    for (int j = (int)(i + 1); j <= (int)(n); j++)
      if (hi[i] < hi[j]) {
        swap(lo[i], lo[j]);
        swap(hi[i], hi[j]);
      }
  for (int i = (int)(1); i <= (int)(n); i++) {
    int s1 = 0;
    for (int j = (int)(1); j <= (int)(i - 1); j++)
      if (lo[j] > hi[i]) ++s1;
    for (int j = (int)(0); j <= (int)(s1); j++)
      if (B > j && s1 - j <= A - B)
        ans = (ans + 1ll * C(s1, j) * C(i - s1 - 1, B - j - 1)) % mo;
  }
  printf("%d\n", ans);
}
