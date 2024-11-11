#include <bits/stdc++.h>
using namespace std;
const long long linf = 1e18 + 5;
const int logN = 18;
const int inf = 1e9;
const int N = 80000;
int P[N], in[N][2], out[N][2], sum[N], h[N], val[N];
int X, n, m, mod, k, x, y, S, center, C, T;
vector<int> v[N];
pair<int, int> a[N], b[N];
int FE(int x, int k) {
  if (!k) return x;
  int temp = FE(x, k / 2);
  if (k & 1) return (long long)temp * temp % mod * x % mod;
  return (long long)temp * temp % mod;
}
int prep(int node, int root) {
  sum[node] = 1;
  for (__typeof(v[node].begin()) it = v[node].begin(); it != v[node].end();
       it++)
    if (*it != root && !h[*it]) sum[node] += prep(*it, node);
  return sum[node];
}
int find(int node, int root, int S) {
  for (__typeof(v[node].begin()) it = v[node].begin(); it != v[node].end();
       it++)
    if (*it != root && !h[*it] && sum[*it] > S) return *it;
  return node;
}
void dfs(int T, int node, int root, int l, int up, int down) {
  a[++C] = make_pair(((X - up) * (long long)T % mod + mod) % mod, node);
  b[C] = make_pair(down, node);
  for (__typeof(v[node].begin()) it = v[node].begin(); it != v[node].end();
       it++)
    if (*it != root && !h[*it])
      dfs(((long long)T * ::T) % mod, *it, node, l + 1,
          ((long long)up * k + val[*it]) % mod,
          (down + (long long)val[*it] * P[l + 1] % mod) % mod);
}
void calculate(int l, int r, int mul) {
  sort(a + l, a + r + 1);
  sort(b + l, b + r + 1);
  for (int i = l; i <= r; i++) {
    out[a[i].second][1] +=
        mul * (upper_bound(b + l, b + r + 1, make_pair(a[i].first, inf)) -
               lower_bound(b + l, b + r + 1, make_pair(a[i].first, 0)));
    in[b[i].second][1] +=
        mul * (upper_bound(a + l, a + r + 1, make_pair(b[i].first, inf)) -
               lower_bound(a + l, a + r + 1, make_pair(b[i].first, 0)));
  }
}
void solve(int node) {
  prep(node, 0);
  S = 0;
  int center = ::center = find(node, 0, sum[node] / 2);
  C = 0;
  h[center] = 1;
  a[++C] = make_pair(X, center);
  b[C] = make_pair(val[center] % mod, center);
  for (__typeof(v[center].begin()) it = v[center].begin();
       it != v[center].end(); it++)
    if (!h[*it]) {
      int last = C;
      dfs(T, *it, center, 1, val[*it],
          ((long long)k * val[*it] + val[center]) % mod);
      calculate(last + 1, C, -1);
    }
  calculate(1, C, 1);
  for (__typeof(v[center].begin()) it = v[center].begin();
       it != v[center].end(); it++)
    if (!h[*it]) solve(*it);
}
int main() {
  scanf("%d %d %d %d", &n, &mod, &k, &X);
  for (int i = 1; i <= n; i++) scanf("%d", &val[i]);
  for (int i = 2; i <= n; i++) {
    scanf("%d %d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  P[0] = 1;
  for (int i = 1; i <= n; i++) P[i] = (long long)k * P[i - 1] % mod;
  T = FE(k, mod - 2);
  solve(1);
  long long ans = 0;
  int all = 0;
  for (int i = 1; i <= n; i++) {
    all += in[i][1];
    all -= out[i][1];
    out[i][0] = n - out[i][1];
    in[i][0] = n - in[i][1];
    ans += 2LL * out[i][0] * out[i][1] + (long long)in[i][0] * out[i][1] +
           (long long)in[i][1] * out[i][0] + 2LL * in[i][0] * in[i][1];
  }
  assert(!all);
  cout << (long long)n * n * n - ans / 2 << '\n';
}
