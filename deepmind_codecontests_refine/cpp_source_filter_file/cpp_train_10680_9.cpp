#include <bits/stdc++.h>
using namespace std;
int n, a, b, c;
char str[2000000 + 5];
vector<int> G[10000 + 5];
vector<int> per[10000 + 5];
int siz[10000 + 5], dfn[10000 + 5], low[10000 + 5], dcnt;
int blo[10000 + 5], bgcd[10000 + 5], blocnt;
int stk[10000 + 5], t;
int num[10000 + 5], mx[10000 + 5], mn[10000 + 5];
bool instk[10000 + 5];
int fact[10000 + 5], inv[10000 + 5];
int PowMod(int x, int y) {
  int ret = 1;
  while (y) {
    if (y & 1) ret = 1LL * ret * x % 1000000007;
    x = 1LL * x * x % 1000000007;
    y >>= 1;
  }
  return ret;
}
int gcd(int x, int y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
void InPut() {
  scanf("%d %d %d", &n, &a, &b);
  for (int i = 1; i <= n; i++) {
    scanf("%s", str + 1);
    for (int j = 1; j <= n; j++)
      if (str[j] == '1') G[i].push_back(j);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &siz[i]);
    per[i].resize(siz[i] + 1);
    scanf("%s", str);
    for (int j = 0; j < siz[i]; j++)
      if (str[j] == '1')
        per[i][j] = 1;
      else if (str[j] == '0')
        per[i][j] = 0;
  }
}
void Tarjan(int u, int fa) {
  dfn[u] = low[u] = ++dcnt;
  instk[u] = true;
  stk[t++] = u;
  for (int i = 0; i < (int)G[u].size(); i++) {
    int v = G[u][i];
    if (dfn[v] == 0) {
      Tarjan(v, u);
      low[u] = min(low[u], low[v]);
    } else if (instk[v] == true)
      low[u] = min(low[u], dfn[v]);
  }
  if (low[u] == dfn[u]) {
    int fro = 0;
    blocnt++;
    do {
      fro = stk[--t];
      instk[fro] = false;
      blo[fro] = blocnt;
      bgcd[blocnt] = gcd(bgcd[blocnt], siz[fro]);
    } while (fro != u);
  }
}
void Part1() {
  for (int i = 1; i <= n; i++)
    if (dfn[i] == 0) Tarjan(i, -1);
  for (int i = 1; i <= blocnt; i++) per[i + n].resize(bgcd[i] + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < siz[i]; j++)
      per[blo[i] + n][j % bgcd[blo[i]]] |= per[i][j];
  int nw;
  for (int i = blocnt; i > 1; i--) {
    nw = gcd(bgcd[i], bgcd[i - 1]);
    for (int j = 0; j < bgcd[i]; j++)
      if (per[i + n][j]) {
        per[i - 1 + n][j % nw] |= 1;
        num[i]++;
      }
  }
  for (int j = 0; j < bgcd[1]; j++) num[1] += per[1 + n][j];
  for (int i = 1; i <= n; i++) {
    mx[i] = mn[i] = 0;
    mx[i] = num[blo[i]] * siz[i] / bgcd[blo[i]];
    for (int j = 0; j < siz[i]; j++) mn[i] += per[i][j];
  }
}
void Prepare() {
  fact[0] = 1;
  for (int i = 1; i <= 10000; i++) fact[i] = 1LL * fact[i - 1] * i % 1000000007;
  inv[10000] = PowMod(fact[10000], 1000000007 - 2);
  for (int i = 10000 - 1; i >= 0; i--)
    inv[i] = 1LL * inv[i + 1] * (1LL * i + 1LL) % 1000000007;
}
inline int C(int x, int y) {
  return 1LL * fact[x] * inv[y] % 1000000007 * inv[x - y] % 1000000007;
}
int Part2() {
  Prepare();
  int cnt1 = 0, cnt2 = 0, ret = 0;
  for (int i = 1; i <= n; i++) {
    cnt1 = cnt2 = 0;
    for (int j = 1; j <= n; j++) {
      if (i != j && mn[j] > mx[i]) cnt1++;
      if (i != j && mn[j] <= mx[i] &&
          (mx[j] > mx[i] || (mx[j] == mx[i] && j < i)))
        cnt2++;
    }
    if (cnt1 > a - 1) continue;
    for (int j = min(b, min(a - 1 - cnt1, cnt2)); j >= 0 && j + 1 + cnt1 >= b;
         j--)
      ret = (1LL * ret + 1LL * C(cnt2, j) * C(cnt1, b - j - 1) % 1000000007) %
            1000000007;
  }
  return ret;
}
int main() {
  InPut();
  Part1();
  int ans = Part2();
  printf("%d\n", ans);
  return 0;
}
