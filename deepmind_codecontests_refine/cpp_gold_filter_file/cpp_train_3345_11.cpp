#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long add(long long a, long long b) {
  a += b;
  if (a >= mod) return a - mod;
  return a;
}
long long mul(long long a, long long b) {
  a *= b;
  if (a >= mod) return a % mod;
  return a;
}
long long power(long long a, long long b) {
  long long p = 1;
  while (b) {
    if (b & 1) p = mul(p, a);
    a = mul(a, a);
    b /= 2;
  }
  return p;
}
struct FenwickTree {
  int n;
  vector<long long> t;
  FenwickTree(int nn) {
    n = nn;
    t.resize(n + 1);
  }
  void update(int idx, long long delta) {
    while (idx <= n) {
      t[idx] += delta;
      idx += (idx & -idx);
    }
  }
  long long sum(int idx) {
    long long res = 0;
    while (idx > 0) {
      res += t[idx];
      idx -= (idx & -idx);
    }
    return res;
  }
  int firstIndexOfGE(long long val) {
    int step = (1 << 30);
    int i = 0;
    long long now = 0;
    while (step > 0) {
      if (i + step <= n && now + t[i + step] < val) {
        now += t[i + step];
        i += step;
      }
      step /= 2;
    }
    return i;
  }
  void debug() {
    for (int i = 1; i <= n; i++) {
      cerr << sum(i) - sum(i - 1) << " ";
    }
    cerr << '\n';
  }
};
const int N = 1234567;
long long T;
int n;
long long x[N];
long long t[N];
vector<pair<int, long long> > g[N];
long long f[N];
long long dp[N];
FenwickTree ft1(N);
FenwickTree ft2(N);
long long get(long long ti) {
  if (ti == 0) return 0;
  int idx = ft1.firstIndexOfGE(ti);
  long long res = ft2.sum(idx);
  if (idx == N) return res;
  long long rem = ti - ft1.sum(idx);
  idx++;
  return res + rem / idx;
}
void dfs(int u, int p, long long sum) {
  ft1.update(t[u], t[u] * x[u]);
  ft2.update(t[u], x[u]);
  f[u] = get(max(0LL, T - 2 * sum));
  for (auto e : g[u]) {
    if (e.first == p) continue;
    dfs(e.first, u, sum + e.second);
  }
  ft1.update(t[u], -t[u] * x[u]);
  ft2.update(t[u], -x[u]);
}
void dfs(int u, int p) {
  multiset<long long> st;
  st.insert(0);
  st.insert(0);
  for (auto e : g[u]) {
    if (e.first == p) continue;
    dfs(e.first, u);
    st.insert(dp[e.first]);
    if (((int)(st.size())) > 2) st.erase(st.begin());
  }
  if (u == 1)
    dp[u] = max(f[u], *st.rbegin());
  else
    dp[u] = max(f[u], *st.begin());
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> T;
  for (int i = 1; i <= n; i++) cin >> x[i];
  for (int i = 1; i <= n; i++) cin >> t[i];
  for (int i = 2; i <= n; i++) {
    int p, l;
    cin >> p >> l;
    g[p].push_back({i, l});
    g[i].push_back({p, l});
  }
  dfs(1, 0, 0);
  dfs(1, 0);
  cout << dp[1] << '\n';
  return 0;
}
