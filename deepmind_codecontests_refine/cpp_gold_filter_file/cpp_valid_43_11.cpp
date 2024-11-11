#include <bits/stdc++.h>
using namespace std;
const long long maxn = 3e5;
long long pr[maxn];
vector<long long> g[maxn];
long long tin[maxn];
long long tout[maxn];
long long timer = 0;
const long long mx = 20;
long long pred[maxn][mx];
bool used[maxn];
vector<long long> euler;
pair<long long, long long> t[maxn * 4 * 2];
void make_set(long long n) {
  for (long long i = 0; i < n; ++i) {
    pr[i] = i;
  }
}
long long find_set(long long v) {
  if (pr[v] == v) return v;
  return pr[v] = find_set(pr[v]);
}
void unic(long long a, long long b) {
  a = find_set(a);
  b = find_set(b);
  pr[a] = b;
}
void dfs(long long v, long long p) {
  euler.push_back(v);
  tin[v] = timer++;
  pred[v][0] = p;
  used[v] = true;
  for (long long j = 1; j < mx; ++j) {
    pred[v][j] = pred[pred[v][j - 1]][j - 1];
  }
  for (long long i = 0; i < g[v].size(); ++i) {
    long long to = g[v][i];
    if (to == p) continue;
    dfs(to, v);
  }
  tout[v] = timer++;
  euler.push_back(v);
}
bool ispredok(long long fath, long long son) {
  return tin[fath] <= tin[son] && tout[fath] >= tout[son];
}
long long lca(long long a, long long b) {
  if (ispredok(a, b)) return a;
  if (ispredok(b, a)) return b;
  for (long long i = mx - 1; i >= 0; --i) {
    if (!ispredok(pred[a][i], b)) {
      a = pred[a][i];
    }
  }
  return pred[a][0];
}
void upd(long long v, long long tl, long long tr, long long pos,
         pair<long long, long long> val) {
  if (tl == tr) {
    t[v].first += val.first;
    t[v].second += val.second;
  } else {
    long long tm = (tl + tr) / 2;
    if (pos <= tm) {
      upd(v * 2, tl, tm, pos, val);
    } else {
      upd(v * 2 + 1, tm + 1, tr, pos, val);
    }
    t[v] = {t[v * 2].first + t[v * 2 + 1].first,
            t[v * 2].second + t[v * 2 + 1].second};
  }
}
pair<long long, long long> get(long long v, long long tl, long long tr,
                               long long l, long long r) {
  if (tl > r || tr < l) {
    return {0, 0};
  }
  if (l <= tl && tr <= r) {
    return t[v];
  }
  long long tm = (tl + tr) / 2;
  auto a1 = get(v * 2, tl, tm, l, r);
  auto a2 = get(v * 2 + 1, tm + 1, tr, l, r);
  return {a1.first + a2.first, a1.second + a2.second};
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  long long n, q;
  cin >> n >> q;
  make_set(n);
  vector<pair<pair<long long, long long>, long long>> qw(q);
  for (long long i = 0; i < q; ++i) {
    long long u, v, x;
    cin >> u >> v >> x;
    u--;
    v--;
    qw[i] = {{u, v}, x};
    if (find_set(u) == find_set(v)) {
      continue;
    } else {
      g[u].push_back(v);
      g[v].push_back(u);
      unic(u, v);
    }
  }
  for (long long k = 0; k < n; ++k) {
    if (used[k]) continue;
    dfs(k, k);
  }
  for (long long j = 0; j < q; ++j) {
    long long u = qw[j].first.first;
    long long v = qw[j].first.second;
    long long x = qw[j].second;
    long long l = lca(u, v);
    if (pred[u][0] == v) {
      cout << "YES\n";
      long long tmp = 1;
      if (x == 0) tmp = 0;
      upd(1, 0, 2 * n - 1, tin[u], {tmp, 0});
      upd(1, 0, 2 * n - 1, tout[u], {-tmp, 0});
      continue;
    }
    if (pred[v][0] == u) {
      cout << "YES\n";
      long long tmp = 1;
      if (x == 0) tmp = 0;
      upd(1, 0, 2 * n - 1, tin[v], {tmp, 0});
      upd(1, 0, 2 * n - 1, tout[v], {-tmp, 0});
      continue;
    }
    auto o1 = get(1, 0, 2 * n - 1, 0, tin[u]);
    auto o2 = get(1, 0, 2 * n - 1, 0, tin[v]);
    auto o3 = get(1, 0, 2 * n - 1, 0, tin[l]);
    long long s1 = o1.first + o2.first - o3.first * 2;
    long long s2 = o1.second + o2.second - o3.second * 2;
    if ((s1 + x) % 2 == 0) {
      cout << "NO\n";
      continue;
    }
    if (s2 > 0) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    while (v != l) {
      long long tmp = 1;
      upd(1, 0, 2 * n - 1, tin[v], {0, tmp});
      upd(1, 0, 2 * n - 1, tout[v], {0, -tmp});
      v = pred[v][0];
    }
    while (u != l) {
      long long tmp = 1;
      upd(1, 0, 2 * n - 1, tin[u], {0, tmp});
      upd(1, 0, 2 * n - 1, tout[u], {0, -tmp});
      u = pred[u][0];
    }
  }
}
