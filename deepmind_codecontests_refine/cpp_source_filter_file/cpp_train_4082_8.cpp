#include <bits/stdc++.h>
using namespace std;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
template <int SZ>
struct tree {
  vector<int> adj[SZ];
  const static int LGSZ = 32 - __builtin_clz(SZ - 1);
  int ppar[SZ][LGSZ];
  int depth[SZ];
  void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  void dfs(int u, int dep) {
    depth[u] = dep;
    for (int v : adj[u])
      if (ppar[u][0] != v) {
        ppar[v][0] = u;
        dfs(v, dep + 1);
      }
  }
  void build() {
    ppar[0][0] = 0;
    for (int i = 0; i < SZ; i++) depth[i] = 0;
    dfs(0, 0);
    for (int i = 1; i < LGSZ; i++)
      for (int j = 0; j < SZ; j++) {
        ppar[j][i] = ppar[ppar[j][i - 1]][i - 1];
      }
  }
  int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = (LGSZ)-1; i >= 0; i--)
      if (depth[ppar[u][i]] >= depth[v]) u = ppar[u][i];
    if (u == v) return u;
    for (int i = (LGSZ)-1; i >= 0; i--) {
      if (ppar[u][i] != ppar[v][i]) {
        u = ppar[u][i];
        v = ppar[v][i];
      }
    }
    return ppar[u][0];
  }
  int getNode(int a, int b) {
    int ans = b;
    for (int i = (LGSZ)-1; i >= 0; i--)
      if (depth[ppar[ans][i]] >= depth[a] + 1) ans = ppar[ans][i];
    return ans;
  }
};
const long long MOD = 998244353;
template <class T, int sz>
struct BIT {
  T b[sz + 1];
  BIT() {
    for (int i = 0; i < sz + 1; i++) b[i] = 0;
  }
  void add(int k, T val) {
    k++;
    for (; k <= sz; k += (k & -k)) {
      b[k] += val;
      if (b[k] > MOD) b[k] -= MOD;
    }
  }
  T psum(int ind) {
    T ans = 0;
    ind++;
    for (; ind > 0; ind -= (ind & -ind)) {
      ans += b[ind];
      if (ans > MOD) ans -= MOD;
    }
    return ans;
  }
  void upd(int l, int r, T val) {
    add(l, val);
    if (r != sz - 1) add(r + 1, MOD - val);
  }
  long long query(int idx) { return psum(idx); }
};
const int MAX_N = 150005;
const int BLOCK_SZ = 500;
int n, q;
vector<int> adj[MAX_N];
vector<int> ch[MAX_N];
tree<MAX_N> t;
int subsz[MAX_N];
int tin[MAX_N];
int curT = 0;
int heavy[MAX_N];
pair<int, long long> heavyAcc[MAX_N];
BIT<long long, MAX_N> bit;
void dfs(int u, int p) {
  for (int v : adj[u])
    if (v != p) {
      dfs(v, u);
      ch[u].push_back(v);
    }
}
int get_subsz(int u) {
  subsz[u] = 1;
  for (int v : ch[u]) subsz[u] += get_subsz(v);
  return subsz[u];
}
void gen_euler(int u) {
  tin[u] = curT++;
  for (int v : ch[u]) gen_euler(v);
}
void addToSubtree(int u, long long d) {
  int l = tin[u];
  int r = tin[u] + subsz[u] - 1;
  bit.upd(l, r, d);
}
long long mpow(long long base, long long exp) {
  if (exp == 0) return 1;
  long long res = mpow(base, exp / 2);
  res *= res;
  res %= MOD;
  if (exp & 1) {
    res *= base;
    res %= MOD;
  }
  return res;
}
long long inv(long long k) { return mpow(k, MOD - 2); }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    t.addEdge(u, v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  t.build();
  dfs(0, -1);
  get_subsz(0);
  gen_euler(0);
  int numHeavy = 0;
  long long invn = inv(n);
  for (int i = 0; i < n; i++) {
    if ((int)ch[i].size() >= BLOCK_SZ) {
      heavyAcc[numHeavy].first = i;
      heavy[i] = numHeavy++;
    } else {
      heavy[i] = -1;
    }
  }
  for (int i = 0; i < q; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      int u;
      long long d;
      cin >> u >> d;
      u--;
      if (heavy[u] == -1) {
        long long val = d * subsz[u] % MOD;
        addToSubtree(0, val);
        addToSubtree(u, MOD - val);
        bit.upd(tin[u], tin[u], d * n % MOD);
        for (int v : ch[u]) {
          addToSubtree(v, d * (n - subsz[v]) % MOD);
        }
      } else {
        heavyAcc[heavy[u]].second += d;
        if (heavyAcc[heavy[u]].second > MOD) heavyAcc[heavy[u]].second -= MOD;
      }
    } else {
      int u;
      cin >> u;
      u--;
      long long res = bit.query(tin[u]);
      for (int i = 0; i < numHeavy; i++) {
        int v = heavyAcc[i].first;
        if (u == v) {
          res += heavyAcc[i].second * n % MOD;
          if (res > MOD) res -= MOD;
        } else {
          if (t.depth[u] <= t.depth[v] || t.lca(u, v) == v) {
            int c = t.getNode(v, u);
            res += heavyAcc[i].second * (n - subsz[c]) % MOD;
            if (res > MOD) res -= MOD;
          } else {
            res += heavyAcc[i].second * subsz[v] % MOD;
            if (res > MOD) res -= MOD;
          }
        }
      }
      cout << (res * invn) % MOD << "\n";
    }
  }
}
