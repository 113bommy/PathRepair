#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e15;
class LazySegmentTree {
 private:
  int n;
  vector<pair<long long, int>> node;
  vector<long long> lazy;

 public:
  LazySegmentTree(vector<long long> v) {
    n = 1;
    while (n < v.size()) n *= 2;
    node.resize(2 * n - 1, make_pair(-INF, 0));
    lazy.resize(2 * n - 1, 0);
    for (int i = 0; i < v.size(); i++) node[i + n - 1] = make_pair(v[i], i);
    for (int i = n - 2; i >= 0; i--)
      node[i] = max(node[2 * i + 1], node[2 * i + 2]);
  }
  void eval(int k, int l, int r) {
    if (lazy[k] != 0) {
      node[k].first += lazy[k];
      if (r - l > 1) {
        lazy[2 * k + 1] += lazy[k];
        lazy[2 * k + 2] += lazy[k];
      }
      lazy[k] = 0;
    }
  }
  void add(int a, int b, long long x, int k = 0, int l = 0, int r = -1) {
    if (r < 0) r = n;
    eval(k, l, r);
    if (b <= l || r <= a) return;
    if (a <= l && r <= b) {
      lazy[k] += x;
      eval(k, l, r);
    } else {
      add(a, b, x, 2 * k + 1, l, (r + l) / 2);
      add(a, b, x, 2 * k + 2, (r + l) / 2, r);
      node[k] = max(node[2 * k + 1], node[2 * k + 2]);
    }
  }
  pair<long long, int> getMax(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r < 0) r = n;
    eval(k, l, r);
    if (b <= l || r <= a) return make_pair(-INF, 0);
    if (a <= l && r <= b) {
      return node[k];
    }
    pair<long long, int> vl, vr;
    vl = getMax(a, b, 2 * k + 1, l, (l + r) / 2);
    vr = getMax(a, b, 2 * k + 2, (l + r) / 2, r);
    return max(vl, vr);
  }
};
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<long long> X(N), Y(N), C(N);
  for (int i = 0; i < (N); ++i) cin >> X[i] >> Y[i] >> C[i];
  vector<long long> v;
  map<long long, int> mp;
  map<int, long long> rev;
  for (int i = 0; i < N; i++) {
    v.push_back(X[i]);
    v.push_back(Y[i]);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  for (int i = 0; i < v.size(); i++) {
    mp[v[i]] = i;
    rev[i] = v[i];
  }
  int V = v.size();
  vector<vector<int>> rig(V), lef(V);
  for (int i = 0; i < N; i++) {
    lef[mp[min(X[i], Y[i])]].push_back(i);
    rig[mp[max(X[i], Y[i])]].push_back(i);
  }
  vector<long long> input(V, 0);
  for (int i = 0; i < (N); ++i) input[V - 1] += C[i];
  for (int i = V - 2; i >= 0; i--) {
    input[i] = input[i + 1];
    for (auto ng : rig[i + 1]) input[i] -= C[ng];
  }
  for (int i = 0; i < V; i++) input[i] -= rev[i];
  LazySegmentTree seg(input);
  vector<int> del(N, 0);
  long long ans = 0;
  int x = 2000000000;
  int y = x;
  for (int i = 0; i < V; i++) {
    auto f = seg.getMax(i, V);
    long long val = f.first;
    if (ans < val + rev[i]) {
      ans = val + rev[i];
      x = rev[i];
      y = rev[f.second];
    }
    for (auto n : lef[i]) {
      if (del[n]) continue;
      del[n] = 1;
      seg.add(mp[max(X[n], Y[n])], V, -C[n]);
    }
  }
  cout << ans << endl;
  cout << min(x, y) << " " << min(x, y) << " " << max(y, x) << " " << max(y, x)
       << endl;
  return 0;
}
