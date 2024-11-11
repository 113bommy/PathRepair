#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
const long long MOD = 1000000007;
long long exp(long long x, long long p) {
  if (p == 0) return 1;
  long long ans = exp(x, p / 2);
  ans = (ans * ans) % MOD;
  if (p % 2) {
    (ans *= x) %= MOD;
  }
  return ans % MOD;
}
vector<int> grafo[MAXN];
vector<pair<pair<int, int>, pair<long long, int> > > ops;
int tin[MAXN], tout[MAXN], T, filhos[MAXN], pai[MAXN], v[MAXN];
void dfs(int x, int p) {
  tin[x] = ++T;
  for (int v : grafo[x]) {
    if (v == p) continue;
    dfs(v, x);
  }
  tout[x] = T;
}
struct nodeseg {
  long long sumc, m, lz;
  bool haslz, flag;
  nodeseg(long long _sc = 0, long long _m = 0, long long _lz = 1, bool _h = 0,
          bool _f = 0) {
    sumc = _sc;
    m = _m;
    lz = _lz;
    haslz = _h;
    flag = _f;
  }
} seg[4 * MAXN];
void unlazy(int node, int x, int y) {
  if (seg[node].haslz) {
    seg[node].m *= seg[node].lz;
    seg[node].m %= MOD;
    seg[node].sumc %= MOD;
    seg[node].lz %= MOD;
    seg[node].sumc *= seg[node].lz;
    seg[node].sumc %= MOD;
    if (x != y) {
      seg[node << 1].haslz = 1, (seg[node << 1].lz *= seg[node].lz) %= MOD;
      seg[(node << 1) | 1].haslz = 1,
                        (seg[(node << 1) | 1].lz *= seg[node].lz) %= MOD;
    }
    seg[node].haslz = 0;
    seg[node].lz = 1;
  }
}
void update1(int node, int x, int y, int id, long long v, long long m) {
  unlazy(node, x, y);
  if (x > id || y < id) return;
  if (x == y) {
    seg[node].sumc = v * m;
    seg[node].sumc %= MOD;
    seg[node].m = m;
    return;
  }
  update1(node << 1, x, ((x + y) >> 1) + 0, id, v, m);
  update1((node << 1) | 1, ((x + y) >> 1) + 1, y, id, v, m);
  seg[node].sumc = seg[node << 1].sumc + seg[(node << 1) | 1].sumc;
  seg[node].sumc %= MOD;
}
void update2(int node, int x, int y, int l, int r, long long m) {
  unlazy(node, x, y);
  if (x > r || y < l) return;
  if (x >= l && y <= r) {
    seg[node].lz *= m;
    seg[node].haslz = 1;
    unlazy(node, x, y);
    return;
  }
  update2(node << 1, x, ((x + y) >> 1) + 0, l, r, m);
  update2((node << 1) | 1, ((x + y) >> 1) + 1, y, l, r, m);
  seg[node].sumc = seg[node << 1].sumc + seg[(node << 1) | 1].sumc;
  seg[node].sumc %= MOD;
}
long long queryc(int node, int x, int y, int l, int r) {
  unlazy(node, x, y);
  if (x > r || y < l) return 0;
  if (x >= l && y <= r) return seg[node].sumc;
  long long e = queryc(node << 1, x, ((x + y) >> 1) + 0, l, r);
  long long d = queryc((node << 1) | 1, ((x + y) >> 1) + 1, y, l, r);
  return (e + d) % MOD;
}
long long queryd(int node, int x, int y, int id) {
  unlazy(node, x, y);
  if (x > id || y < id) return 0;
  if (x == y) return seg[node].m;
  long long e = queryd(node << 1, x, ((x + y) >> 1) + 0, id);
  long long d = queryd((node << 1) | 1, ((x + y) >> 1) + 1, y, id);
  return e + d;
}
int q, n = 1;
long long v1;
int main() {
  scanf("%lld %d", &v1, &q);
  v[1] = v1;
  int qaux = q;
  while (qaux--) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int p;
      long long vv;
      scanf("%d %lld", &p, &vv);
      grafo[p].push_back(++n);
      grafo[n].push_back(p);
      pai[n] = p;
      v[n] = vv;
      ops.push_back({{p, n}, {vv, t}});
    } else {
      int x;
      scanf("%d", &x);
      ops.push_back({{x, 0}, {0, t}});
    }
  }
  dfs(1, 1);
  update1(1, 1, n, tin[1], v1, 1);
  for (int i = 0; i < q; i++) {
    int t = ops[i].second.second;
    if (t == 1) {
      int p = ops[i].first.first;
      int va = ops[i].first.second;
      long long vv = ops[i].second.first;
      long long m = queryd(1, 1, n, tin[p]);
      update1(1, 1, n, tin[va], vv, m);
      update2(1, 1, n, tin[p], tout[p],
              (filhos[p] + 2) * exp(filhos[p] + 1, MOD - 2));
      filhos[p]++;
    } else {
      int x = ops[i].first.first;
      long long ans = queryc(1, 1, n, tin[x], tout[x]) % MOD;
      ans = (ans * (filhos[x] + 1)) % MOD;
      long long aux = exp(queryd(1, 1, n, tin[x]) % MOD, MOD - 2) % MOD;
      ans = (ans * aux) % MOD;
      printf("%lld\n", ans);
    }
  }
}
