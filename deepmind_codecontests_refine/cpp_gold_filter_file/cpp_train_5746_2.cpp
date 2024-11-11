#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long powmod(long long a, long long b, long long MOD) {
  if (a == 0ll) {
    return 0ll;
  }
  a %= MOD;
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans = ans * a % MOD;
    }
    a = a * a % MOD;
    b >>= 1;
  }
  return ans;
}
long long poww(long long a, long long b) {
  if (a == 0ll) {
    return 0ll;
  }
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans = ans * a;
    }
    a = a * a;
    b >>= 1;
  }
  return ans;
}
void Pv(const vector<int> &V) {
  int Len = int(V.size());
  for (int i = 0; i < Len; ++i) {
    printf("%d", V[i]);
    if (i != Len - 1) {
      printf(" ");
    } else {
      printf("\n");
    }
  }
}
void Pvl(const vector<long long> &V) {
  int Len = int(V.size());
  for (int i = 0; i < Len; ++i) {
    printf("%lld", V[i]);
    if (i != Len - 1) {
      printf(" ");
    } else {
      printf("\n");
    }
  }
}
inline long long readll() {
  long long tmp = 0, fh = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') fh = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') tmp = tmp * 10 + c - 48, c = getchar();
  return tmp * fh;
}
inline int readint() {
  int tmp = 0, fh = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') fh = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') tmp = tmp * 10 + c - 48, c = getchar();
  return tmp * fh;
}
void pvarr_int(int *arr, int n, int strat = 1) {
  if (strat == 0) {
    n--;
  }
  for (int i = strat; i <= n; i++) {
    printf("%d%c", arr[i], i == n ? '\n' : ' ');
  }
}
void pvarr_LL(long long *arr, int n, int strat = 1) {
  if (strat == 0) {
    n--;
  }
  for (int i = strat; i <= n; i++) {
    printf("%lld%c", arr[i], i == n ? '\n' : ' ');
  }
}
const int maxn = (1 << 17);
const int inf = 0x3f3f3f3f;
int n, m;
struct edge {
  int f, t, val;
  edge() {}
  edge(int ff, int tt, int vv) {
    f = ff;
    t = tt;
    val = vv;
  }
};
std::vector<edge> e[maxn];
int vis[maxn];
int loop = 0;
std::vector<int> c[maxn];
int far[maxn];
int far_w[maxn];
int cnt = 0;
int base = 0;
void dfs(int x, int pre) {
  vis[x] = ++cnt;
  for (auto &y : e[x]) {
    if (vis[y.t] == 0) {
      far[y.t] = x;
      far_w[y.t] = y.val;
      dfs(y.t, x);
    } else if (vis[y.t] > vis[x]) {
      int now = y.t;
      loop++;
      c[loop].push_back(y.val);
      base ^= y.val;
      while (now != x) {
        c[loop].push_back(far_w[now]);
        base ^= far_w[now];
        now = far[now];
      }
    }
  }
}
long long a[maxn];
long long b[maxn];
void FWT_xor(long long *a, int N, int opt, long long MOD, long long inv2) {
  for (int i = 1; i < N; i <<= 1)
    for (int p = i << 1, j = 0; j < N; j += p)
      for (int k = 0; k < i; ++k) {
        int X = a[j + k], Y = a[i + j + k];
        a[j + k] = (X + Y) % MOD;
        a[i + j + k] = (X + MOD - Y) % MOD;
        if (opt == -1)
          a[j + k] = 1ll * a[j + k] * inv2 % MOD,
                a[i + j + k] = 1ll * a[i + j + k] * inv2 % MOD;
      }
}
const long long MOD = 1000000007;
const long long inv2 = powmod(2, MOD - 2ll, MOD);
const long long mod2 = 998244353;
const long long inv_22 = powmod(2, mod2 - 2ll, mod2);
long long yeji[maxn];
long long d[maxn];
int main() {
  n = readint();
  m = readint();
  int tot = 0;
  for (int i = 1; i <= m; i++) {
    int u = readint();
    int v = readint();
    int w = readint();
    e[u].push_back(edge(u, v, w));
    e[v].push_back(edge(v, u, w));
    base ^= w;
  }
  dfs(1, 1);
  a[base] = 1;
  d[base] = 1;
  FWT_xor(a, maxn, 1, MOD, inv2);
  FWT_xor(d, maxn, 1, mod2, inv_22);
  for (int i = 1; i <= loop; ++i) {
    int now = 0;
    for (auto &y : c[i]) {
      now ^= y;
    }
    memset((b), 0, sizeof((b)));
    memset((yeji), 0, sizeof((yeji)));
    for (auto &y : c[i]) {
      b[now ^ y]++;
      yeji[now ^ y]++;
    }
    FWT_xor(b, maxn, 1, MOD, inv2);
    FWT_xor(yeji, maxn, 1, mod2, inv_22);
    for (int j = 0; j <= maxn - 1; j++) {
      a[j] = a[j] * b[j] % MOD;
      d[j] = d[j] * yeji[j] % mod2;
    }
  }
  FWT_xor(a, maxn, -1, MOD, inv2);
  FWT_xor(d, maxn, -1, mod2, inv_22);
  for (int i = 0; i < maxn; ++i) {
    if (a[i] > 0 || d[i] > 0) {
      printf("%d %lld\n", i, a[i]);
      break;
    }
  }
  return 0;
}
