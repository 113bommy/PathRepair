#include <bits/stdc++.h>
using namespace std;
const int maxn = 3010;
const long long mod = 998244353;
struct edge {
  int next, to;
} g[maxn << 3];
int head[maxn << 2], cnt;
void add(int from, int to) {
  g[++cnt].next = head[from];
  g[cnt].to = to;
  head[from] = cnt;
}
long long KSM(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
struct BCJ {
  int f[maxn << 1];
  void init() {
    for (int i = 1; i < (maxn << 1); i++) f[i] = i;
  }
  int gf(int x) {
    if (f[x] != x) f[x] = gf(f[x]);
    return f[x];
  }
  void merge(int x, int y) {
    int fx = gf(x), fy = gf(y);
    if (fx == fy) return;
    f[fy] = fx;
  }
} B;
int n;
string x;
int col[maxn << 2];
int ida[maxn], idb[maxn];
int CNT;
int S, T;
bool fail;
long long ans = 0;
void dfs(int x, int c) {
  col[x] = c;
  for (int i = head[x]; i; i = g[i].next) {
    int v = g[i].to;
    if (col[v]) {
      if (col[v] == col[x]) {
        fail = 1;
        return;
      }
      continue;
    }
    dfs(v, 3 - c);
    if (fail) return;
  }
}
int a[maxn];
int main() {
  int i, j;
  cin >> x;
  n = x.length();
  for (i = 0; i < n; i++) {
    int res = 0;
    if (x[i] == '1') res = 1;
    if (x[i] == '0') res = 0;
    if (x[i] == '?') res = 2;
    a[n - i] = res;
  }
  S = ++CNT;
  T = ++CNT;
  for (i = 1; i <= n; i++) {
    ida[i] = ++CNT;
    idb[i] = ++CNT;
  }
  for (i = 1; i < n; i++) {
    B.init();
    for (j = 1; j <= CNT; j++) {
      head[j] = 0;
      col[j] = 0;
    }
    cnt = 0;
    B.merge(T, ida[1]);
    B.merge(T, idb[1]);
    for (j = 1; j <= i; j++) {
      B.merge(ida[j], ida[i - j + 1]);
    }
    for (j = i + 1; j <= n; j++) B.merge(S, ida[j]);
    for (j = 1; j <= n; j++) {
      B.merge(idb[j], idb[n - j + 1]);
    }
    for (j = 1; j <= n; j++) {
      if (a[j] == 0) B.merge(ida[j], idb[j]);
    }
    add(B.gf(S), B.gf(T));
    add(B.gf(T), B.gf(S));
    for (j = 1; j <= n; j++) {
      if (a[j] == 1) {
        add(B.gf(ida[j]), B.gf(idb[j]));
        add(B.gf(idb[j]), B.gf(ida[j]));
      }
    }
    fail = 0;
    int res = 0;
    for (j = 1; j <= CNT; j++) {
      if (B.gf(j) == j && !col[j]) {
        col[j] = 1;
        dfs(j, 1);
        if (fail) break;
        res += 1;
      }
    }
    if (fail) continue;
    ans = (ans + KSM(2, res - 1)) % mod;
  }
  printf("%lld\n", ans);
}
