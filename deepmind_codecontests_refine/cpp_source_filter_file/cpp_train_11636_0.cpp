#include <bits/stdc++.h>
using namespace std;
namespace Base {
const int inf = 0x3f3f3f3f, INF = 0x7fffffff;
const long long infll = 0x3f3f3f3f3f3f3f3fll, INFll = 0x7fffffffffffffffll;
template <typename T>
void read(T &x) {
  x = 0;
  int fh = 1;
  double num = 1.0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') fh = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  if (ch == '.') {
    ch = getchar();
    while (isdigit(ch)) {
      num /= 10;
      x = x + num * (ch - '0');
      ch = getchar();
    }
  }
  x = x * fh;
}
template <typename T>
void chmax(T &x, T y) {
  x = x < y ? y : x;
}
template <typename T>
void chmin(T &x, T y) {
  x = x > y ? y : x;
}
}  // namespace Base
using namespace Base;
const int P = 998244353, G = 3, N = 500010;
struct Edge {
  int data, next;
} e[N * 2];
int a[N], b[N], c[N], num[N], nxt[N], p[N], size[N], dad[N], head[N], place, k,
    mul[N], inv[N], n, s[N], ans;
map<int, int> mp[N];
int power(int x, int y) {
  int i = x;
  x = 1;
  while (y > 0) {
    if (y % 2 == 1) x = 1ll * i * x % P;
    i = 1ll * i * i % P;
    y /= 2;
  }
  return x;
}
int C(int n, int m) {
  if (m > n) return 0;
  return 1ll * mul[n] * inv[n - m] % P;
}
void update(int &x, int y) {
  x += y;
  x = (x >= P) ? x - P : x;
}
void build(int u, int v) {
  e[++place].data = v;
  e[place].next = head[u];
  head[u] = place;
}
void NTT(int *a, int l, int tag) {
  for (int i = 0, j = 0; i < l; i++) {
    if (i > j) swap(a[i], a[j]);
    for (int k = (l >> 1); (j ^= k) < k; k >>= 1)
      ;
  }
  for (int i = 1; i < l; i <<= 1) {
    int wn = power(G, (P - 1) / (i * 2));
    if (tag == -1) wn = power(wn, P - 2);
    for (int j = 0; j < l; j += i + i) {
      int w = 1;
      for (int k = 0; k < i; k++, w = 1ll * w * wn % P) {
        int x = a[k + j], y = 1ll * w * a[k + j + i] % P;
        a[k + j] = (x + y) % P, a[k + j + i] = (x - y + P) % P;
      }
    }
  }
  if (tag == -1) {
    int in = power(l, P - 2);
    for (int i = 0; i < l; i++) a[i] = 1ll * a[i] * in % P;
  }
}
void doit(int *t1, int *t2, int *c, int l) {
  for (int i = 0; i < l; i++) a[i] = t1[i], b[i] = t2[i];
  for (int i = l; i < 2 * l; i++) a[i] = b[i] = 0;
  for (int i = 0; i < 2 * l; i++) c[i] = 0;
  NTT(a, l * 2, 1);
  NTT(b, l * 2, 1);
  for (int i = 0; i < 2 * l; i++) c[i] = 1ll * a[i] * b[i] % P;
  NTT(c, l * 2, -1);
}
void dfs(int x, int fa) {
  size[x] = 1;
  dad[x] = fa;
  int id = 0;
  for (int ed = head[x]; ed != 0; ed = e[ed].next)
    if (e[ed].data != fa) {
      dfs(e[ed].data, x);
      size[x] += size[e[ed].data];
      update(s[x], s[e[ed].data]);
    }
  for (int ed = head[x]; ed != 0; ed = e[ed].next)
    if (e[ed].data != fa) {
      num[id] = 1, num[id + 1] = size[e[ed].data];
      id += 2;
    }
  int tmp = 1;
  while (tmp < id) tmp <<= 1;
  for (int i = id; i < tmp; i += 2) num[i] = 1, num[i + 1] = 0;
  id = tmp;
  for (int i = 2; i < tmp; i <<= 1) {
    for (int k = 0; k < tmp; k += 2 * i) {
      doit(num + k, num + k + i, nxt, i);
      for (int t = 0; t < 2 * i; t++) num[k + t] = nxt[t];
    }
  }
  for (int i = 0; i <= min(k, id - 1); i++)
    update(p[x], 1ll * num[i] * C(k, i) % P);
  for (int i = 0; i < id + 2; i++) nxt[i] = 0;
  for (int i = 0; i < id; i++) {
    update(nxt[i], num[i]);
    update(nxt[i + 1], 1ll * num[i] * (n - size[x]) % P);
  }
  id += 2;
  for (int i = 0; i < id; i++) num[i] = nxt[i];
  for (int ed = head[x]; ed != 0; ed = e[ed].next)
    if (e[ed].data != fa) {
      if (mp[x].find(size[e[ed].data]) == mp[x].end()) {
        for (int i = 0; i < id; i++) nxt[i] = 0;
        int in = power(size[e[ed].data], P - 2), las = 0;
        for (int i = id - 1; i >= 1; i--) {
          las = 1ll * (num[i] - las + P) % P * in % P;
          nxt[i - 1] = las;
        }
        tmp = 0;
        for (int i = 0; i <= min(k, id - 1); i++)
          update(tmp, 1ll * nxt[i] * C(k, i) % P);
        mp[x][size[e[ed].data]] = tmp;
      }
    }
  update(s[x], p[x]);
}
void solve(int x, int fa, int sum) {
  ans = (ans + 1ll * sum * p[x]) % P;
  int now = 0;
  for (int ed = head[x]; ed != 0; ed = e[ed].next) {
    if (e[ed].data == fa) continue;
    update(ans, 1ll * mp[x][size[e[ed].data]] * s[e[ed].data] % P);
    update(now, s[e[ed].data]);
  }
  for (int ed = head[x]; ed != 0; ed = e[ed].next) {
    if (e[ed].data == fa) continue;
    solve(e[ed].data, x,
          (1ll * sum + mp[x][size[e[ed].data]] + now - s[e[ed].data] + P) % P);
  }
}
int main() {
  read(n), read(k);
  if (k == 1) {
    cout << (1ll * n * (n - 1) / 2) << endl;
    return 0;
  }
  mul[0] = 1;
  for (int i = 1; i <= k; i++) mul[i] = 1ll * mul[i - 1] * i % P;
  inv[k] = power(mul[k], P - 2);
  for (int i = k - 1; i >= 0; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % P;
  for (int i = 1; i < n; i++) {
    int u = 1, v = i + 1;
    read(u);
    read(v);
    build(u, v);
    build(v, u);
  }
  dfs(1, 0);
  solve(1, 0, 0);
  ans = 1ll * ans * power(2, P - 2) % P;
  printf("%d\n", ans);
  return 0;
}
