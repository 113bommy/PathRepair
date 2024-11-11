#include <bits/stdc++.h>
using namespace std;
const int inf = 2000000000;
const int N = 51;
int cnt, mn, mx, n, a[N][N], st[N];
bool was[N], use[N];
bool dfs(int v, int pr = -1) {
  cnt++;
  was[v] = true;
  if (st[v] <= 1) mn = min(mn, v);
  if (st[v] <= 1) mx = max(mx, v);
  for (int i = 1; i <= n; i++) {
    if (a[v][i] && i != pr) {
      if (was[i]) {
        use[v] = true;
        return true;
      }
      bool first = dfs(i, v);
      if (first) {
        use[v] = true;
        return true;
      }
    }
  }
  return false;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int m;
  cin >> n >> m;
  if (n == 2 && m == 2) {
    for (int i = 1; i <= m; i++) {
      int q, w;
      cin >> q >> w;
      if (q == w) {
        cout << "NO\n";
        return 0;
      }
    }
    cout << "YES\n";
    cout << "0";
    return 0;
  }
  for (int i = 1; i <= m; i++) {
    int q, w;
    cin >> q >> w;
    if (a[q][w] == 1) {
      cout << "NO\n";
      return 0;
    }
    a[q][w] = 1;
    a[w][q] = 1;
    if (q == w) {
      if (n > 1) {
        cout << "NO\n";
        return 0;
      }
      use[i] = true;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      st[i] += a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    if (st[i] > 2) {
      cout << "NO";
      return 0;
    }
  }
  set<pair<int, int> > s;
  for (int i = 1; i <= n; i++) {
    if (!use[i] && !was[i]) {
      mn = inf;
      mx = -inf;
      cnt = 0;
      bool first = dfs(i);
      if (!first) {
        pair<int, int> q(mn, mx);
        s.insert(q);
      } else {
        if (cnt == n) {
          cout << "YES\n0";
          return 0;
        }
        cout << "NO\n";
        return 0;
      }
    }
  }
  if (s.size() == 0) {
    cout << "YES\n";
    cout << 0;
    return 0;
  }
  vector<pair<int, int> > ans;
  while (s.size() != 1) {
    pair<int, int> first = *s.begin();
    s.erase(s.begin());
    pair<int, int> second = *s.begin();
    s.erase(s.begin());
    ans.push_back(pair<int, int>(first.first, second.first));
    pair<int, int> a(min(first.second, second.second),
                     max(first.second, second.second));
    s.insert(a);
  }
  ans.push_back(*s.begin());
  cout << "YES\n";
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].first << " " << ans[i].second << "\n";
  }
}
