#include <bits/stdc++.h>
using namespace std;
const int off = 1 << 18;
const int MOD = 1e9 + 7;
int q, n = 1;
int st[off << 1] = {}, sp[off], st2[off << 1];
vector<int> g[200001];
int qt[200000], qv[200000], qval[200000], ch[200001] = {};
int tin[200001], tout[200001], timer = -1, par[200001];
void dfs(int v) {
  tin[v] = ++timer;
  for (int to : g[v]) {
    dfs(to);
  }
  tout[v] = timer;
}
void stBuild() {
  for (int i = off - 1; i >= 1; --i) {
    st[i] = st[2 * i] + st[2 * i + 1];
    sp[i] = 1;
  }
  for (int i = 0; i < (int)(2 * off); ++i) st2[i] = 1;
}
void stPush(int v) {
  for (int i = 2 * v; i <= 2 * v + 1; ++i) {
    st[i] = (long long)st[i] * sp[v] % MOD;
    if (i < off) {
      sp[i] = (long long)sp[i] * sp[v] % MOD;
    }
  }
  sp[v] = 1;
}
int mul;
void stMul(int v, int L, int R, int l, int r) {
  if (L == l && R == r) {
    st[v] = (long long)st[v] * mul % MOD;
    if (L != R) sp[v] = (long long)sp[v] * mul % MOD;
    return;
  }
  int mid = (L + R) >> 1;
  if (sp[v] != 1) {
    stPush(v);
  }
  if (l <= mid) stMul(2 * v, L, mid, l, min(r, mid));
  if (r > mid) stMul(2 * v + 1, mid + 1, R, max(l, mid + 1), r);
  st[v] = st[2 * v] + st[2 * v + 1];
  if (st[v] >= MOD) st[v] -= MOD;
}
int pos, val;
void stAssign(int v, int L, int R) {
  if (L == R) {
    st[v] = val;
    return;
  }
  int mid = (L + R) >> 1;
  if (sp[v] != 1) {
    stPush(v);
  }
  if (pos <= mid)
    stAssign(2 * v, L, mid);
  else
    stAssign(2 * v + 1, mid + 1, R);
  st[v] = st[2 * v] + st[2 * v + 1];
  if (st[v] >= MOD) st[v] -= MOD;
}
int stGet(int v, int L, int R, int l, int r) {
  if (l > r) return 0;
  if (L == l && R == r) {
    return st[v];
  }
  int mid = (L + R) >> 1;
  if (sp[v] != 1) {
    stPush(v);
  }
  int res = stGet(2 * v, L, mid, l, min(r, mid)) +
            stGet(2 * v + 1, mid + 1, R, max(l, mid + 1), r);
  if (res >= MOD) res -= MOD;
  return res;
}
void st2Mul(int v, int L, int R, int l, int r) {
  if (L == l && R == r) {
    st2[v] = (long long)st2[v] * mul % MOD;
    return;
  }
  int mid = (L + R) >> 1;
  if (l <= mid) st2Mul(2 * v, L, mid, l, min(r, mid));
  if (r > mid) st2Mul(2 * v + 1, mid + 1, R, max(l, mid + 1), r);
}
int st2Get(int pos) {
  int res = 1;
  for (pos += off; pos >= 1; pos >>= 1) {
    res = (long long)res * st2[pos] % MOD;
  }
  return res;
}
int binPow(long long x, int p) {
  long long res = 1;
  while (p) {
    if (p & 1) res = res * x % MOD;
    p >>= 1;
    if (p) x = x * x % MOD;
  }
  return (int)res;
}
int main() {
  scanf("%d%d", st + off, &q);
  for (int i = 0; i < (int)(q); ++i) {
    scanf("%d%d", qt + i, qv + i), --qv[i];
    if (qt[i] == 1) {
      scanf("%d", qval + i);
      g[qv[i]].push_back(n);
      par[n++] = qv[i];
    }
  }
  dfs(0);
  stBuild();
  n = 1;
  for (int i = 0; i < (int)(q); ++i) {
    if (qt[i] == 1) {
      val = (long long)st2Get(tin[qv[i]]) * qval[i] % MOD;
      pos = tin[n++];
      stAssign(1, 0, off - 1);
      mul = (long long)(ch[qv[i]] + 2) * binPow(ch[qv[i]] + 1, MOD - 2) % MOD;
      ++ch[qv[i]];
      stMul(1, 0, off - 1, tin[qv[i]], tout[qv[i]]);
      st2Mul(1, 0, off - 1, tin[qv[i]], tout[qv[i]]);
    } else {
      int res = stGet(1, 0, off - 1, tin[qv[i]], tout[qv[i]]);
      if (qv[i] != 0) {
        res = (long long)res * binPow(st2Get(par[qv[i]]), MOD - 2) % MOD;
      }
      printf("%d\n", res);
    }
  }
  return 0;
}
