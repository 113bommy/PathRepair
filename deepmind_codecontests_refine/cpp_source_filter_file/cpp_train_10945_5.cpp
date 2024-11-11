#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, m;
vector<pair<int, int>> a, v, res;
int ar[N + 5];
int par[N + 5];
void makeset() {
  for (int i = 0; i < N; i++) {
    par[i] = i;
  }
}
int findpar(int x) {
  if (x == par[x]) return x;
  return par[x] = findpar(par[x]);
}
void Union(int x, int y) {
  int px = findpar(x);
  int py = findpar(y);
  par[py] = px;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  makeset();
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    v.push_back({x, y});
    ar[x]++;
    ar[y]++;
  }
  int mx = 0;
  for (int i = 0; i < N; i++) {
    mx = max(mx, ar[i]);
  }
  int mn = 0;
  for (int i = 0; i < N; i++) {
    if (ar[i] == mx) {
      mn = i;
      break;
    }
  }
  for (int i = 0; i < m; i++) {
    if (v[i].first == mn || v[i].second == mn) {
      a.push_back(v[i]);
    }
  }
  int sz = a.size();
  int ans = 0;
  for (int i = 0; i < sz; i++) {
    Union(a[i].first, a[i].second);
    res.push_back(a[i]);
    ans++;
    if (ans == n - 1) break;
  }
  for (int i = 0; i < n && ans < n - 1; i++) {
    int px = findpar(v[i].first);
    int py = findpar(v[i].second);
    if (px != py) {
      res.push_back(v[i]);
      Union(px, py);
      ans++;
    }
  }
  for (int i = 0; i < n - 1; i++) {
    cout << res[i].first << ' ' << res[i].second << '\n';
  }
  return 0;
}
