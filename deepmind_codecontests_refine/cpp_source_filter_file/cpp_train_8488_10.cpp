#include <bits/stdc++.h>
using namespace std;
const int MAXB = 1e7;
char buf[MAXB], *cp = buf;
inline void rd(int &x) {
  x = 0;
  int f = 1;
  while (*cp < '0' || '9' < *cp)
    if (*cp++ == '-') f = -1;
  while ('0' <= *cp && *cp <= '9') x = (x << 3) + (x << 1) + *cp++ - 48;
  x *= f;
}
const int MAXN = 1000010;
const long long p = 1000000007LL;
int t, n, a[MAXN], g[MAXN];
int pri[MAXN], cnt;
int tag[MAXN];
long long fac[MAXN];
int c1[MAXN], c2[MAXN];
bool isnp[MAXN];
vector<int> f[MAXN];
int lx[MAXN], ly[MAXN];
void get_prime(int n) {
  cnt = 0;
  isnp[1] = true;
  for (int i = 1; i <= n; i++) tag[i] = 1;
  for (int i = 2; i <= n; i++) {
    if (!isnp[i]) {
      pri[cnt++] = i;
    }
    for (int j = 0; j < cnt && i <= n / pri[j]; j++) {
      isnp[i * pri[j]] = true;
      if (i % pri[j] == 0) break;
    }
  }
  f[1].push_back(1);
  for (int i = 0; i < cnt; i++) {
    for (int j = 1; j <= n / pri[i]; j++)
      f[pri[i] * j].push_back(pri[i]), tag[pri[i] * j] *= pri[i];
  }
}
void get_fact(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
}
int main() {
  fread(buf, MAXB, 1, stdin);
  get_prime(1000000);
  get_fact(1000000);
  memset(c1, 0, sizeof(c1));
  memset(c2, 0, sizeof(c2));
  memset(lx, 0, sizeof(lx));
  memset(ly, 0, sizeof(ly));
  rd(n);
  for (int i = 1; i <= n; i++) rd(a[i]), g[i] = n / i;
  g[1] = 1;
  bool ok = true;
  for (int i = 1; i <= n; i++)
    if (a[i]) {
      if (f[a[i]].size() != f[i].size()) {
        ok = false;
        break;
      }
      for (int j = 0; j < f[i].size(); j++) {
        int x = f[i][j], y = f[a[i]][j];
        if (g[x] != g[y]) ok = false;
        if (ly[x] && ly[x] != y || lx[y] && lx[y] != x) ok = false;
        lx[y] = x, ly[x] = y;
      }
    }
  if (!ok)
    return puts("0"), 0;
  else {
    for (int i = 1; i <= n; i++)
      if (!ly[i] && isnp[i]) c1[g[i]]++;
    for (int i = 1; i <= n; i++) c2[tag[i]]++;
    for (int i = 1; i <= n; i++) c2[tag[a[i]]]--;
    long long ans = 1;
    for (int i = 1; i <= n; i++) ans = ans * fac[c1[i]] % p * fac[c2[i]] % p;
    printf("%I64d\n", ans);
  }
  return 0;
}
