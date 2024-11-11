#include <bits/stdc++.h>
using namespace std;
int const INF = (int)1e9 + 1e3;
long long const INFL = (long long)1e18 + 1e6;
mt19937 tw(9450189);
uniform_int_distribution<long long> ll_distr;
long long rnd(long long a, long long b) {
  return ll_distr(tw) % (b - a + 1) + a;
}
vector<pair<int, int>> tmp_arr(4);
pair<pair<pair<int, int>, pair<int, int>>, pair<pair<int, int>, pair<int, int>>>
f(pair<pair<pair<int, int>, pair<int, int>>,
       pair<pair<int, int>, pair<int, int>>> const& a,
  pair<pair<pair<int, int>, pair<int, int>>,
       pair<pair<int, int>, pair<int, int>>> const& b) {
  tmp_arr[0] = a.first.first;
  tmp_arr[1] = a.first.second;
  tmp_arr[2] = b.first.first;
  tmp_arr[3] = b.first.second;
  sort(tmp_arr.begin(), tmp_arr.end());
  pair<pair<int, int>, pair<int, int>> lowest = {tmp_arr[0], tmp_arr[1]};
  tmp_arr[0] = a.second.first;
  tmp_arr[1] = a.second.second;
  tmp_arr[2] = b.second.first;
  tmp_arr[3] = b.second.second;
  sort(tmp_arr.begin(), tmp_arr.end());
  pair<pair<int, int>, pair<int, int>> largest = {tmp_arr[3], tmp_arr[2]};
  return {lowest, largest};
}
void solve() {
  int n, q;
  cin >> n >> q;
  vector<vector<int>> graph(n);
  for (int i = 1; i < n; ++i) {
    int p;
    cin >> p;
    --p;
    graph[p].push_back(i);
  }
  vector<int> tin(n), tout(n);
  int t = 0;
  int bp = 0;
  while ((1 << bp) < n) {
    ++bp;
  }
  vector<vector<int>> binup(bp, vector<int>(n));
  vector<int> depth(n);
  function<void(int, int, int)> dfs = [&](int v, int p, int d) {
    binup[0][v] = p;
    for (int i = 1; i < bp; ++i) {
      binup[i][v] = binup[i - 1][binup[i - 1][v]];
    }
    depth[v] = d;
    tin[v] = t++;
    for (int to : graph[v]) {
      dfs(to, v, d + 1);
    }
    tout[v] = t;
  };
  dfs(0, 0, 0);
  function<int(int, int)> get_lca = [&](int a, int b) {
    if (depth[a] > depth[b]) {
      swap(a, b);
    }
    for (int i = bp - 1; i >= 0; --i) {
      if (depth[b] - (1 << i) >= depth[a]) {
        b = binup[i][b];
      }
    }
    if (a == b) {
      return a;
    }
    for (int i = bp - 1; i >= 0; --i) {
      if (binup[i][a] != binup[i][b]) {
        a = binup[i][a];
        b = binup[i][b];
      }
    }
    return binup[0][a];
  };
  int bpv = 1;
  while (bpv < n) {
    bpv *= 2;
  }
  vector<pair<pair<pair<int, int>, pair<int, int>>,
              pair<pair<int, int>, pair<int, int>>>>
      rmq(bpv * 2);
  for (int i = 0; i < n; ++i) {
    rmq[i + bpv] = {{{tout[i], i}, {INF, -1}}, {{tin[i], i}, {-INF, -1}}};
  }
  for (int i = bpv - 1; i; --i) {
    rmq[i] = f(rmq[i * 2], rmq[i * 2 + 1]);
  }
  function<pair<pair<pair<int, int>, pair<int, int>>,
                pair<pair<int, int>, pair<int, int>>>(int, int, int, int, int)>
      segtree_get = [&](int v, int vl, int vr, int l, int r) {
        if (vr <= l || r <= vl) {
          return make_pair(make_pair(make_pair(INF, -1), make_pair(INF, -1)),
                           make_pair(make_pair(-INF, -1), make_pair(-INF, -1)));
        }
        if (l <= vl && vr <= r) {
          return rmq[v];
        }
        int vm = (vl + vr) / 2;
        return f(segtree_get(v * 2, vl, vm, l, r),
                 segtree_get(v * 2 + 1, vm, vr, l, r));
      };
  for (int j = 0; j < q; ++j) {
    int l, r;
    cin >> l >> r;
    --l;
    auto tmp = segtree_get(1, 0, bpv, l, r);
    pair<int, int> ans = {
        depth[get_lca(tmp.first.second.second, tmp.second.first.second)],
        tmp.first.first.second};
    ans = max(ans,
              {depth[get_lca(tmp.first.first.second, tmp.second.second.second)],
               tmp.second.first.second});
    cout << ans.second + 1 << " " << ans.first << "\n";
  }
}
int main() {
  cout << setprecision(15) << fixed;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int test_count = 1;
  for (int test = 1; test <= test_count; ++test) {
    solve();
  }
}
