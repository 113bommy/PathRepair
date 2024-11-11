#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  char ch = getchar();
  long long f = 1;
  while (!isdigit(ch)) {
    if (ch == '-') f *= -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  x *= f;
}
const long long p = 1000000007;
long long pow_mod(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) {
      res *= x;
      res %= p;
    }
    x *= x;
    x %= p;
    y >>= 1;
  }
  return res;
}
struct linearBasis {
  static const int MAXL = 60;
  long long num[MAXL + 1][2];
  long long a[MAXL + 1];
  void init() {
    memset(a, 0, sizeof(a));
    memset(num, 0, sizeof(num));
  }
  void insert(long long x) {
    for (int i = MAXL; i >= 0; --i) {
      if ((x & (1LL << i)) == 0) continue;
      if (a[i]) {
        x ^= a[i];
      } else {
        for (int j = 0; j < i; ++j) {
          if (x & (1LL << j)) x ^= a[j];
        }
        for (int j = i + 1; j <= MAXL; ++j)
          if (a[j] & (1LL << i)) a[j] ^= x;
        a[i] = x;
        break;
      }
    }
  }
  void build() {
    long long res = 500000004;
    long long sum = 0;
    for (int i = 0; i <= MAXL; ++i) {
      if (a[i]) {
        res = res * 2 % p;
        sum |= a[i];
      }
    }
    for (int i = 0; i <= MAXL; ++i) {
      if (sum & (1LL << i)) {
        num[i][0] = num[i][1] = res;
      } else {
        num[i][0] = res * 2 % p;
        num[i][1] = 0;
      }
    }
  }
  long long getMax(long long x) {
    for (int i = 0; i <= MAXL; ++i) {
      if ((x & (1LL << i)) == 0) x ^= a[i];
    }
    return x;
  }
} lb;
int n, m;
struct edge {
  int v;
  long long w;
};
vector<edge> e[100010];
bool vis[100010];
int fa[100010];
int cnt[61][2];
long long val[100010];
void dfs(int);
long long nmsl(int);
int main() {
  int x, y;
  long long z;
  long long ans = 0;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d%lld", &x, &y, &z);
    e[x].push_back({y, z});
    e[y].push_back({x, z});
  }
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      ans += nmsl(i);
      ans %= p;
    }
  }
  printf("%lld", ans);
  return 0;
}
void dfs(int x) {
  vis[x] = true;
  for (auto g : e[x]) {
    int v = g.v;
    long long w = g.w;
    if (vis[v]) {
      if (v == fa[x]) continue;
      lb.insert(val[x] ^ val[v] ^ w);
      continue;
    }
    fa[v] = x;
    val[v] = val[x] ^ w;
    dfs(v);
  }
  long long tmp = val[x];
  for (int i = 0; i <= 60; ++i, tmp >>= 1) ++cnt[i][tmp & 1];
}
long long nmsl(int x) {
  long long ans = 0;
  lb.init();
  memset(cnt, 0, sizeof(cnt));
  dfs(x);
  lb.build();
  for (int i = 0; i <= 60; ++i) {
    long long t0 = (1LL * cnt[i][0] * (cnt[i][0] - 1) / 2 +
                    1LL * cnt[i][1] * (cnt[i][1] - 1) / 2) %
                   p;
    long long t1 = 1LL * cnt[i][0] * cnt[i][1] % p;
    ans += (1LL << i) % p * (t0 * lb.num[i][1] + t1 * lb.num[i][0]) % p;
    ans %= p;
  }
  return ans;
}
