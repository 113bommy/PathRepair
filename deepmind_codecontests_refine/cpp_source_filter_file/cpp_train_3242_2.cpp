#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
vector<int> e[maxn];
int par[maxn], rankk[maxn], b[maxn];
void init(int n) {
  for (int i = 1; i <= n; i++) par[i] = i, rankk[i] = 0;
}
int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }
void unit(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return;
  if (rankk[x] > rankk[y])
    swap(x, y);
  else if (rankk[x] == rankk[y])
    rankk[y]++;
  par[x] = y;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    e[x].push_back(y);
    e[y].push_back(x);
  }
  init(n);
  for (int i = 2; i <= n; i++) {
    for (auto x : e[i])
      if (x != 1) {
        unit(x, i);
      }
  }
  int cnt = 0;
  for (int i = 2; i <= n; i++)
    if (find(i) == i) cnt++;
  if (cnt > k || k > e[1].size()) return puts("NO"), 0;
  for (auto x : e[1])
    if (find(x) == find(1)) {
      unit(x, 1);
      b[x] = 1;
      k--;
    }
  for (auto x : e[1])
    if (k && !b[x]) {
      unit(x, 1);
      b[x] = 1;
      k--;
    }
  vector<pair<int, int> > ans;
  init(n);
  for (auto x : e[1])
    if (b[x]) {
      unit(x, 1);
      ans.push_back({x, 1});
    }
  for (int i = 2; i <= n; i++) {
    for (auto x : e[i])
      if (x != 1 && find(x) != find(i)) {
        unit(x, i);
        ans.push_back({x, i});
      }
  }
  cout << "YES" << '\n';
  for (auto x : ans) cout << x.first << ' ' << x.second << '\n';
  return 0;
}
