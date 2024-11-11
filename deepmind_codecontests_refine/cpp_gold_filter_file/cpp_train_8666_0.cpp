#include <bits/stdc++.h>
using namespace std;
int t, n, timer, d, root;
vector<int> v[1009], v2;
vector<pair<int, int> > vv;
void dfs(int node, int p) {
  vv.push_back({++timer, node});
  for (auto i : v[node])
    if (i != p) dfs(i, node);
}
int ask(int l, int r) {
  cout << "? " << r - l + 1;
  for (int i = l; i <= r; i++) cout << " " << vv[i].second;
  cout << "\n";
  cout.flush();
  int ans;
  cin >> ans >> ans;
  return ans;
}
void dfs(int node, int p, int cur_d, bool good) {
  if (node == root) good = true;
  if (cur_d == d && good) v2.push_back(node);
  for (auto i : v[node])
    if (i != p) dfs(i, node, cur_d + 1, good);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  srand(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) v[i].clear();
    vv.clear();
    v2.clear();
    timer = 0;
    for (int i = 1; i < n; i++) {
      int x, y;
      cin >> x >> y;
      v[x].push_back(y), v[y].push_back(x);
    }
    cout << "? " << n;
    for (int i = 1; i <= n; i++) cout << " " << i;
    cout << "\n";
    cout.flush();
    cin >> root >> d;
    dfs(root, 0);
    sort(vv.begin(), vv.end());
    int x, y, low = 0, high = n - 1, m;
    int cnt = 2;
    while (low < high) {
      if (cnt) {
        m = rand() % (high - (low + high) / 2) + (low + high) / 2;
        cnt--;
      } else
        m = (low + high) / 2;
      if (ask(m + 1, high) == d)
        low = m + 1;
      else
        high = m;
    }
    x = vv[low].second;
    dfs(x, 0, 0, 0);
    cout << "? " << v2.size();
    for (auto i : v2) cout << " " << i;
    cout << "\n";
    cout.flush();
    cin >> y >> d;
    cout << "! " << x << " " << y << "\n";
    cout.flush();
    string s;
    cin >> s;
  }
}
