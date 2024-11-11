#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> factors(200001, vector<long long>(1, 1));
void precompute() {
  for (long long i = 2; i < 200001; ++i) {
    for (long long j = i; j < 200001; j += i) {
      factors[j].push_back(i);
    }
  }
}
struct Centroid {
  long long total = 0;
  vector<long long> dead, sz, freq, ans, pre, weight, temp;
  long long subtree(long long a, long long p, vector<vector<long long>>& tree) {
    sz[a] = 1;
    for (long long& c : tree[a])
      if (c != p && !dead[c]) sz[a] += subtree(c, a, tree);
    return sz[a];
  }
  long long OneCentroid(long long a, long long p, long long s,
                        vector<vector<long long>>& tree) {
    for (long long& c : tree[a])
      if (c != p && !dead[c] && sz[c] > (s >> 1))
        return OneCentroid(c, a, s, tree);
    return a;
  }
  void change(long long a, long long p, long long ch,
              vector<vector<long long>>& tree) {
    for (long long& i : factors[pre[a]]) freq[i] += ch;
    for (long long& c : tree[a])
      if (c != p && !dead[c]) change(c, a, ch, tree);
  }
  void computeans(long long a, long long p, vector<vector<long long>>& tree) {
    for (long long& i : factors[pre[a]]) temp[i] = freq[i];
    for (auto it = factors[pre[a]].rbegin(); it != factors[pre[a]].rend();
         it++) {
      if (temp[*it] == 0) continue;
      for (long long& c : factors[*it])
        if (*it != c) temp[c] -= temp[*it];
    }
    for (long long& f : factors[pre[a]]) ans[f] += temp[f], temp[f] = 0;
    for (long long& c : tree[a])
      if (c != p && !dead[c]) computeans(c, a, tree);
  }
  long long gcd(long long a, long long b) {
    return (a == 0) ? b : gcd(b % a, a);
  }
  void compute(long long a, long long p, long long d,
               vector<vector<long long>>& tree) {
    for (long long& i : factors[pre[a] = d]) freq[i]++;
    for (long long& c : tree[a])
      if (c != p && !dead[c]) compute(c, a, gcd(d, weight[c]), tree);
  }
  void decompose(long long a, long long p, vector<vector<long long>>& tree) {
    long long cent = OneCentroid(a, p, subtree(a, p, tree), tree);
    compute(cent, -1, weight[cent], tree);
    dead[cent] = 1;
    for (long long& c : tree[cent])
      if (!dead[c]) {
        change(c, cent, -1, tree);
        computeans(c, cent, tree);
      }
    for (long long& f : factors[pre[cent]]) freq[f]--;
    ans[weight[cent]]++;
    for (long long& c : tree[cent])
      if (!dead[c]) decompose(c, cent, tree);
  }
  Centroid(vector<vector<long long>>& tree, long long N, vector<long long>& w)
      : weight(w) {
    dead.assign(N, 0);
    sz.assign(N, 0);
    pre.assign(N, 0);
    temp.assign(200001, 0);
    ans.assign(200001, 0);
    freq.assign(200001, 0);
    decompose(0, -1, tree);
    for (long long i = 0; i < 200001; ++i) {
      if (ans[i]) cout << i << ' ' << ans[i] << '\n';
    }
  }
};
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long N;
  cin >> N;
  vector<vector<long long>> tree(N);
  vector<long long> w(N);
  for (long long& i : w) cin >> i;
  for (long long i = 1, u, v; i < N; ++i) {
    cin >> u >> v;
    --u, --v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  precompute();
  Centroid ans(tree, N, w);
  return 0;
}
