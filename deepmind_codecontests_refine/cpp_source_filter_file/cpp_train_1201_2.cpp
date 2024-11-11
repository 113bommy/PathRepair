#include <bits/stdc++.h>
using namespace std;
int lg(long long n) {
  assert(n > 0);
  int ans = -1;
  while (n) {
    ans++;
    n >>= 1;
  }
  return ans;
}
void solve() {
  int H, Q;
  cin >> H >> Q;
  map<int, int> tree;
  function<double(int, double, int)> trav = [&](int cur, double wei, int famx) {
    if (cur >= (1 << H)) return 0.0;
    double ans = 0;
    int curv = tree[cur];
    int lv = tree[cur << 1], rv = tree[cur << 1 | 1];
    wei /= 2;
    if (curv - lv >= lv) {
      ans += wei * max(famx, curv - lv);
    } else {
      ans += trav(cur << 1, wei, max(famx, curv - lv));
    }
    if (curv - rv >= rv) {
      ans += wei * max(famx, curv - rv);
    } else {
      ans += trav(cur << 1 | 1, wei, max(famx, curv - rv));
    }
    return ans;
  };
  while (Q--) {
    string op;
    cin >> op;
    if (op == "add") {
      int V, E;
      cin >> V >> E;
      while (V) {
        tree[V] += E;
        V >>= 1;
      }
    } else if (op == "decay") {
      cout << fixed << setprecision(10) << trav(1, 1, -1) << '\n';
    } else
      assert(false);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}
