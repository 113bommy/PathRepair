#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
long long mod;
inline long long po(long long a, long long p) {
  long long r = 1;
  for (; p; p >>= 1, a = a * a % mod)
    if (p & 1) r = r * a % mod;
  return r;
}
int n;
long long k;
long long xv;
int v[N << 1];
int x[N << 1];
int ct;
int al[N];
int siz[N];
long long we[N];
bool cut[N];
map<long long, int> ct1, ct2;
int q1[N];
int hd1;
int q2[N];
int hd2;
long long hsh1[N];
long long key1[N];
long long hsh2[N];
long long mi[N];
int ans1[N];
int ans2[N];
inline void add(int u, int V) {
  v[++ct] = V;
  x[ct] = al[u];
  al[u] = ct;
}
inline int dfs1(int u, int f) {
  siz[u] = 1;
  for (int i = al[u]; i; i = x[i])
    if (!cut[v[i]] && v[i] != f) siz[u] += dfs1(v[i], u);
  return siz[u];
}
inline int find(int u, int f, const int& tot) {
  for (int i = al[u]; i; i = x[i])
    if (!cut[v[i]] && (siz[v[i]] << 1) >= tot && v[i] != f)
      return find(v[i], u, tot);
  return u;
}
inline void dfs3(int u, int f, int dis) {
  hsh1[u] = (hsh1[f] * k + we[u]) % mod;
  key1[u] = (xv + mod - hsh1[u]) * po(mi[dis + 1], mod - 2) % mod;
  hsh2[u] = (hsh2[f] + mi[dis - 1] * we[u]) % mod;
  q2[++hd2] = u;
  for (int i = al[u]; i; i = x[i])
    if (!cut[v[i]] && v[i] != f) dfs3(v[i], u, dis + 1);
}
inline void dfs4(int u, int f) {
  q2[++hd2] = u;
  for (int i = al[u]; i; i = x[i])
    if (!cut[v[i]] && v[i] != f) dfs4(v[i], u);
}
inline void solve(int u) {
  dfs1(u, 0);
  int g = find(u, 0, siz[u]);
  cut[g] = true;
  if (siz[u] == 1) return;
  hd1 = 0;
  hsh1[g] = we[g];
  hsh2[g] = 0;
  ct1.clear();
  ct2.clear();
  for (int i = al[g]; i; i = x[i]) {
    if (cut[v[i]]) continue;
    q1[++hd1] = v[i];
    hd2 = 0;
    dfs3(v[i], g, 1);
    for (int i = 1; i <= hd2; i++) {
      int u = q2[i];
      ans1[u] += ct2[key1[u]];
      ans2[u] += ct1[hsh2[u]];
    }
    for (int i = 1; i <= hd2; i++) {
      int u = q2[i];
      ct1[key1[u]]++;
      ct2[hsh2[u]]++;
    }
  }
  ct1.clear();
  ct2.clear();
  long long keyg = (xv + mod - we[g]) * po(mi[1], mod - 2) % mod;
  for (int i = hd1; i >= 1; i--) {
    hd2 = 0;
    dfs4(q1[i], u);
    for (int i = 1; i <= hd2; i++) {
      int u = q2[i];
      ans1[u] += ct2[key1[u]];
      ans2[u] += ct1[hsh2[u]];
    }
    for (int i = 1; i <= hd2; i++) {
      int u = q2[i];
      ct1[key1[u]]++;
      ct2[hsh2[u]]++;
      if (hsh1[u] == xv) ans1[u]++, ans2[g]++;
      if (hsh2[u] == keyg) ans2[u]++, ans1[g]++;
    }
  }
  for (int i = al[g]; i; i = x[i])
    if (!cut[v[i]]) solve(v[i]);
}
int main() {
  scanf("%d%I64d%I64d%I64d", &n, &mod, &k, &xv);
  mi[0] = 1;
  for (int i = 1; i <= n; i++) mi[i] = mi[i - 1] * k % mod;
  for (int i = 1; i <= n; i++) scanf("%I64d", &we[i]);
  for (int i = 1; i <= n; i++)
    if (we[i] == xv) ans1[i]++, ans2[i]++;
  for (int i = 2, u, v; i <= n; i++)
    scanf("%d%d", &u, &v), add(u, v), add(v, u);
  solve(1);
  long long ret = 0;
  for (int i = 1; i <= n; i++)
    ret += ((long long)ans1[i] * (n - ans1[i]) +
            (long long)ans2[i] * (n - ans2[i])) *
               2 +
           (long long)ans1[i] * (n - ans2[i]) +
           (long long)(n - ans1[i]) * ans2[i];
  printf("%I64d\n", (long long)n * n * n - ret / 2);
  return 0;
}
