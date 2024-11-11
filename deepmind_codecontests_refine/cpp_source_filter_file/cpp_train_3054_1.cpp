#include <bits/stdc++.h>
using namespace std;
const int maxn = 605, maxm = 100005;
int n, m, cnt, be, en, en1, en2, ans, mod, flag, S[maxn], T[maxn],
    f[maxn][maxn];
int v[maxn], in[maxn], nex[maxm], out[maxn], top[maxn], info[maxm],
    eq[maxn][maxn];
void add(int u, int v1) {
  nex[++cnt] = info[u];
  info[u] = cnt;
  v[cnt] = v1;
}
int qp(int a, int k) {
  int res = 1;
  while (k) {
    if (k & 1) res = 1ll * res * a % mod;
    k >>= 1;
    a = 1ll * a * a % mod;
  }
  return res;
}
void Gauss() {
  for (int i = 1; i <= en1; i++) {
    if (!eq[i][i]) {
      for (int j = i + 1; j <= en1; j++)
        if (eq[j][i]) {
          swap(eq[i], eq[j]);
          ans *= -1;
          break;
        }
    }
    if (!eq[i][i]) {
      flag = 1;
      return;
    }
    int inv = qp(eq[i][i], mod - 2);
    for (int j = 1; j <= en1; j++)
      if (i != j && eq[j][i]) {
        int t = 1ll * eq[j][i] * inv % mod;
        if (!t) continue;
        for (int k = 1; k <= en1; k++)
          eq[j][k] = (1ll * mod + 1ll * eq[j][k] - 1ll * eq[i][k] * t) % mod;
      }
  }
  for (int i = 1; i <= en1; i++) ans = 1ll * ans * eq[i][i] % mod;
}
int main() {
  scanf("%d%d%d", &n, &m, &mod);
  for (int i = 1, u, v1; i <= m; i++)
    scanf("%d%d", &u, &v1), add(u, v1), out[u]++, in[v1]++;
  for (int i = 1; i <= n; i++) {
    if (in[i] == 0) S[++en1] = i, top[++en] = i, f[i][i] = 1;
    if (out[i] == 0) T[++en2] = i;
  }
  while (be < en) {
    int x = top[++be];
    for (int i = info[x]; i; i = nex[i]) {
      in[v[i]]--;
      if (!in[v[i]]) top[++en] = v[i];
    }
    for (int i = 1; i <= en1; i++)
      for (int j = info[x]; j; j = nex[j]) (f[S[i]][v[j]] += f[S[i]][x]) %= mod;
  }
  for (int i = 1; i <= en1; i++)
    for (int j = 1; j <= en2; j++) eq[i][j] = f[S[i]][T[j]];
  ans = 1;
  Gauss();
  printf("%d", flag ? 0 : (ans + mod) % mod);
}
