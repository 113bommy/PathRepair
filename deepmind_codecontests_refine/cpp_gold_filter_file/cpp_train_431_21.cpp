#include <bits/stdc++.h>
using namespace std;
int i, n, m, x, y, cnt, q;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> q;
  while (q--) {
    cin >> n >> m;
    vector<pair<int, int> > v[3 * n + 1];
    for (i = 1; i <= m; i++) {
      cin >> x >> y;
      v[x].push_back(make_pair(y, i));
      v[y].push_back(make_pair(x, i));
    }
    vector<int> vis(3 * n + 1), mat;
    for (i = 1; i <= 3 * n; i++)
      if (!vis[i]) {
        for (auto &p : v[i])
          if (!vis[p.first]) {
            mat.push_back(p.second);
            vis[i] = vis[p.first] = 1;
            break;
          }
      }
    if (mat.size() >= n) {
      cout << "Matching\n";
      for (i = 0; i < n; i++) cout << mat[i] << " ";
      cout << endl;
      continue;
    }
    cout << "IndSet\n";
    cnt = 0;
    for (i = 1; i <= 3 * n; i++)
      if (!vis[i]) {
        cout << i << " ";
        if (++cnt == n) break;
      }
    cout << endl;
  }
}
