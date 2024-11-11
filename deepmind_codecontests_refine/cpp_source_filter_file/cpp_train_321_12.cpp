#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
struct Testcase {
  set<int> me, him;
  vvi g;
  vi near;
  void dfs(int from, int nearest, int p = -1) {
    if (me.count(from) != 0) {
      near[from] = from;
    } else {
      near[from] = nearest;
    }
    for (int to : g[from]) {
      if (p == to) continue;
      dfs(to, near[from], from);
    }
  }
  void solve() {
    int n;
    cin >> n;
    g.assign(n, vi());
    near.assign(n, -1);
    for (int i = 0; i < n - 1; ++i) {
      int x, y;
      cin >> x >> y;
      x--, y--;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    int k1, k2;
    cin >> k1;
    for (int i = 0; i < k1; ++i) {
      int x;
      cin >> x;
      me.insert(x - 1);
    }
    cin >> k2;
    for (int i = 0; i < k2; ++i) {
      int x;
      cin >> x;
      him.insert(x);
    }
    auto root = *me.begin();
    dfs(root, root);
    auto y1 = *him.begin();
    cout << "B " << y1 << endl;
    cout << flush;
    int x1;
    cin >> x1;
    if (me.count(x1 - 1) == 1) {
      cout << "C " << x1 << endl;
      cout << flush;
      return;
    }
    int x2 = near[x1 - 1] + 1;
    cout << "A " << x1 << endl;
    cout << flush;
    int y2;
    cin >> y2;
    if (him.count(y2) == 1) {
      cout << "C " << x2 << endl;
      cout << flush;
    } else {
      cout << "C -1" << endl;
      cout << flush;
    }
  }
};
int main() {
  int t;
  cin >> t;
  while (t--) {
    Testcase().solve();
    cerr << "SOLVED" << endl;
  }
}
