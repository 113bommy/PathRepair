#include <bits/stdc++.h>
using namespace std;
template <typename G>
struct triple {
  G first, second, T;
};
pair<long long, long long> query(vector<int> &v) {
  cout << "? " << v.size();
  for (auto &i : v) cout << " " << i;
  cout << '\n';
  cout.flush();
  int x, y;
  cin >> x >> y;
  if (x == -1) exit(0);
  return {x - 1, y};
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> tree(n);
    for (int i = 0; i < n - 1; i++) {
      int x, y;
      cin >> x >> y;
      --x;
      --y;
      tree[x].push_back(y);
      tree[y].push_back(x);
    }
    vector<int> q;
    for (int i = 1; i <= n; i++) q.push_back(i);
    pair<long long, long long> temp = query(q);
    int r = temp.first, d = temp.second;
    vector<int> dist(n);
    vector<int> it(n), tt(n);
    int tme = 0;
    function<void(int, int)> dfs = [&](int c, int p) {
      it[c] = tme++;
      for (auto v : tree[c])
        if (v != p) {
          dist[v] = dist[c] + 1;
          dfs(v, c);
        }
      tt[c] = tme++;
    };
    dfs(r, -1);
    int piv = r;
    int li = d / 2, ri = d;
    while (li <= ri) {
      int mid = (li + ri) / 2;
      q.clear();
      for (int i = 0; i < n; i++)
        if (it[piv] <= it[i] && tt[piv] >= tt[i] && dist[i] == mid)
          q.push_back(i + 1);
      if (q.empty())
        ri = mid - 1;
      else {
        pair<long long, long long> te = query(q);
        if (te.second == d) {
          piv = te.first;
          li = mid + 1;
        } else
          ri = mid - 1;
      }
    }
    dist[piv] = tme = 0;
    dfs(piv, -1);
    q.clear();
    for (int i = 0; i < n; i++)
      if (dist[i] == d && it[r] <= it[i] && tt[r] >= tt[i]) q.push_back(i + 1);
    int a = query(q).first;
    cout << "! " << a + 1 << " " << piv + 1 << '\n';
    cout.flush();
    string ver;
    cin >> ver;
    if (ver == "Incorrect") return 0;
  }
  return 0;
}
