#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
vector<int> v[N];
bool vis1[N], vis2[N];
int dfs2(int x, int p) {
  if (vis1[x]) return x;
  int ans = 0;
  for (int y : v[x]) {
    if (y != p) ans = dfs2(y, x);
    if (!ans) return ans;
  }
  return 0;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x, y, z;
    cin >> n;
    for (int i = 1; i <= n; i++) v[i].clear();
    for (int i = 1; i < n; i++) {
      cin >> x >> y;
      v[x].push_back(y);
      v[y].push_back(x);
    }
    for (int i = 0; i <= n; i++) vis1[i] = vis2[i] = 0;
    int k1, k2;
    cin >> k1;
    for (int i = 1; i <= k1; i++) {
      cin >> x;
      vis1[x] = 1;
    }
    cin >> k2;
    for (int i = 1; i <= k2; i++) {
      cin >> x;
      vis2[x] = 1;
    }
    cout << "B " << x << "\n";
    flush(cout);
    cin >> y;
    z = dfs2(y, 0);
    if (z) {
      cout << "A " << z << "\n";
      flush(cout);
      cin >> y;
      if (!vis1[y]) z = 0;
    }
    if (z)
      cout << "C " << z << "\n";
    else
      cout << "C -1"
           << "\n";
    flush(cout);
  }
  return 0;
}
