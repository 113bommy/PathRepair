#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const double eps = 1e-6;
int modpow(int x, int y, int md) {
  if (y == 0) return 1;
  int ret = modpow(x, y >> 1, md);
  ret = (long long)ret * ret % md;
  if (y & 1) ret = (long long)ret * x % md;
  return ret;
}
int n, q, mod;
int pws[10][1000001];
long long euclid(long long x, long long y, long long &k, long long &l) {
  if (y == 0) {
    k = 1;
    l = 0;
    return x;
  }
  long long g = euclid(y, x % y, l, k);
  l -= k * (x / y);
  return g;
}
long long rev(long long x) {
  long long k, l;
  if (euclid(x, mod, k, l) != 1) throw;
  k %= mod;
  if (k < 0) k += mod;
  return k;
}
int pr[10], cnt = 0;
struct Num {
  int a[10] = {};
  int val = 0;
  Num operator*(Num b) {
    Num ret;
    ret.val = (long long)val * b.val % mod;
    for (int i = 0; i < cnt; i++) ret.a[i] = a[i] + b.a[i];
    return ret;
  }
  Num operator+(Num b) {
    if (val == -1) return b;
    if (b.val == -1) return *this;
    Num ret;
    ret.val = 0;
    int v2 = val, v1 = b.val;
    for (int i = 0; i < cnt; i++) {
      ret.a[i] = min(a[i], b.a[i]);
      v2 = (long long)v2 * pws[i][a[i] - ret.a[i]] % mod;
      v1 = (long long)v1 * pws[i][b.a[i] - ret.a[i]] % mod;
    }
    ret.val = (v1 + v2) % mod;
    return ret;
  }
  Num inv() {
    Num ret;
    ret.val = rev(val);
    for (int i = 0; i < cnt; i++) {
      ret.a[i] = -a[i];
    }
    return ret;
  }
  int getreallyvalue() {
    int ret = val;
    for (int i = 0; i < cnt; i++) ret = (long long)ret * pws[i][a[i]] % mod;
    return ret;
  }
};
Num sjctxdy(int x) {
  Num ret;
  if (x == 0) {
    ret.val = 0;
    return ret;
  }
  for (int i = 0; i < 10; i++) ret.a[i] = 0;
  for (int i = 0; i < cnt; i++) {
    if (x % pr[i] == 0) {
      while (x % pr[i] == 0) {
        ret.a[i]++;
        x /= pr[i];
      }
    }
  }
  ret.val = x;
  return ret;
}
struct mod_sjc {
  Num v, mul;
  void print() {
    printf("v: %d", v.val);
    printf(" array:");
    for (int i = 0; i < cnt; i++)
      printf("%d%c", v.a[i], i == cnt - 1 ? '\n' : ' ');
    printf("mul: %d", mul.val);
    printf(" array:");
    for (int i = 0; i < cnt; i++)
      printf("%d%c", mul.a[i], i == cnt - 1 ? '\n' : ' ');
  }
} node[131072 * 2];
int sjctql[131072];
struct sjcakioi {
  void build() {
    for (int i = 131072; i < 131072 + 131072; i++)
      node[i] = (mod_sjc){sjctxdy(sjctql[i - 131072]), sjctxdy(1)};
    for (int i = 131072 - 1; i >= 1; i--)
      node[i].v = node[i + i + 1].v + node[i + i].v, node[i].mul = sjctxdy(1);
  }
  void pushup(int v) { node[v].v = node[v + v].v + node[v + v + 1].v; }
  void pushdown(int v) {
    if (node[v + v + 1].v.val != -1) {
      node[v + v + 1].mul = node[v + v + 1].mul * node[v].mul;
      node[v + v + 1].v = node[v + v + 1].v * node[v].mul;
    }
    if (node[v + v].v.val != -1) {
      node[v + v].mul = node[v + v].mul * node[v].mul;
      node[v + v].v = node[v + v].v * node[v].mul;
    }
    node[v].mul = sjctxdy(1);
  }
  void AK_init(int k, int l, int r, Num v, int a = 0, int b = 131072 - 1) {
    if (r < a || b < l) return;
    if (l <= a && b <= r) {
      node[k].v = node[k].v * v;
      node[k].mul = node[k].mul * v;
      return;
    }
    pushdown(k);
    AK_init(k + k, l, r, v, a, (a + b) >> 1);
    AK_init(k + k + 1, l, r, v, ((a + b) >> 1) + 1, b);
    pushup(k);
  }
  Num AK(int k, int l, int r, int a = 0, int b = 131072 - 1) {
    if (r < a || b < l) return sjctxdy(-1);
    if (l <= a && b <= r) {
      return node[k].v;
    }
    pushdown(k);
    Num ret = AK(k + k, l, r, a, a + b >> 1) +
              AK(k + k + 1, l, r, (a + b >> 1) + 1, b);
    return ret;
  }
} orzsjc;
int main() {
  scanf("%d%d", &n, &mod);
  int t = mod;
  for (int i = 2; i * i <= mod; i++) {
    if (t % i == 0) {
      pr[cnt++] = i;
      while (t % i == 0) t /= i;
    }
  }
  if (t != 1) pr[cnt++] = t;
  for (int i = 0; i < cnt; i++)
    for (int j = 0; j < 1000000; j++) {
      pws[i][j] = (j == 0 ? 1 : (long long)pws[i][j - 1] * pr[i] % mod);
    }
  for (int i = 0; i < n; i++) scanf("%d", sjctql + i);
  orzsjc.build();
  scanf("%d", &q);
  while (q--) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int l, r, x;
      scanf("%d%d%d", &l, &r, &x);
      orzsjc.AK_init(1, l - 1, r - 1, sjctxdy(x));
    } else if (type == 2) {
      int p, x;
      scanf("%d%d", &p, &x);
      orzsjc.AK_init(1, p - 1, p - 1, sjctxdy(x).inv());
    } else if (type == 3) {
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%d\n", orzsjc.AK(1, l - 1, r - 1).getreallyvalue());
    }
  }
  return 0;
}
