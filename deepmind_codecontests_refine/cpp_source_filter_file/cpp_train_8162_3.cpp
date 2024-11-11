#include <bits/stdc++.h>
using namespace std;
int n, m;
int e = 1e5;
set<pair<int, int> > s1, s2, used1, used2;
set<int> p1[200000], p2[200000], p3[200000], p4[200000];
int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[8] = {1, -1, 1, 0, -1, 1, 0, -1};
void dfs1(int x, int y) {
  used1.insert(make_pair(x, y));
  for (int i = 0; i < 8; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (s1.count(make_pair(nx, ny)) != 0)
      if (nx >= 1 && nx <= min(n, e) && ny >= 1 && ny <= min(n, e) &&
          used1.count(make_pair(nx, ny)) == 0)
        dfs1(nx, ny);
  }
  set<int>::const_iterator it = p1[x].upper_bound(y);
  if (it != p1[x].end() && used1.count(make_pair(x, *it)) == 0) dfs1(x, *it);
  it = p1[x - 1].upper_bound(y);
  if (it != p1[x - 1].end() && used1.count(make_pair(x - 1, *it)) == 0)
    dfs1(x - 1, *it);
  it = p3[y].lower_bound(x);
  if (it != p3[y].begin()) {
    it--;
    if (used1.count(make_pair(*it, y)) == 0) dfs1(*it, y);
  }
  it = p3[y - 1].lower_bound(x);
  if (it != p3[y - 1].begin()) {
    it--;
    if (used1.count(make_pair(*it, y - 1)) == 0) dfs1(*it, y - 1);
  }
}
void dfs2(int x, int y) {
  used2.insert(make_pair(x, y));
  for (int i = 0; i < 8; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (s2.count(make_pair(nx, ny)) != 0)
      if (nx >= 1 && nx <= min(n, e) && ny >= 1 && ny <= min(n, e) &&
          used2.count(make_pair(nx, ny)) == 0)
        dfs2(nx, ny);
  }
  set<int>::const_iterator it = p2[y].upper_bound(x);
  if (it != p2[y].end() && used2.count(make_pair(*it, y)) == 0) dfs2(*it, y);
  it = p2[y + 1].upper_bound(x);
  if (it != p2[y + 1].end() && used2.count(make_pair(*it, y + 1)) == 0)
    dfs2(*it, y + 1);
  it = p4[x].lower_bound(y);
  if (it != p4[x].begin()) {
    it--;
    if (used2.count(make_pair(x, *it)) == 0) dfs2(x, *it);
  }
  it = p4[x - 1].lower_bound(y);
  if (it != p4[x - 1].begin()) {
    it--;
    if (used2.count(make_pair(x - 1, *it)) == 0) dfs2(x - 1, *it);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    if (x < e && y < e) {
      s1.insert(make_pair(x, y));
      p1[x].insert(y);
      p3[y].insert(x);
    }
    if (n - x < e && n - y < e) {
      s2.insert(make_pair(n - x + 1, n - y + 1));
      p2[n - y + 1].insert(n - x + 1);
      p4[n - x + 1].insert(n - y + 1);
    }
  }
  for (int i = 2; i <= min(n, e); i++)
    if (s1.count(make_pair(1, i)) != 0)
      if (used1.count(make_pair(1, i)) == 0) dfs1(1, i);
  for (int i = 1; i <= min(n, e); i++)
    if (s2.count(make_pair(i, 1)) != 0)
      if (used2.count(make_pair(i, 1)) == 0) dfs2(i, 1);
  for (long long i = 1; i <= min(e, n); i++)
    if (used1.count(make_pair(i, 1)) != 0 ||
        used2.count(make_pair(1, i)) != 0 ||
        used1.count(make_pair(n, i)) != 0 ||
        used2.count(make_pair(i, n)) != 0) {
      cout << "-1";
      return 0;
    }
  cout << 2 * n - 2;
}
