#include <bits/stdc++.h>
using namespace std;
int solve(vector<pair<int, int> > v, int price) {
  if (v.size() < 2) return 0;
  vector<int> p, b;
  for (int i = 0; i < v.size(); i++)
    p.push_back(v[i].first), b.push_back(v[i].second);
  int amx[v.size()];
  amx[0] = b[0];
  for (int i = 1; i < b.size(); i++) amx[i] = max(amx[i - 1], b[i]);
  int ans = 0;
  for (int i = 0; i < v.size(); i++) {
    int id = upper_bound(p.begin(), p.begin() + i, price - p[i]) - p.begin();
    id--;
    if (id < 0 || id >= v.size()) continue;
    if (id != i) ans = max(ans, b[i] + amx[id]);
  }
  return ans;
}
int main() {
  int i, j, k;
  int n, m;
  int c, d;
  int x, y;
  char ch;
  cin >> n >> c >> d;
  int mc = 0, md = 0;
  vector<pair<int, int> > coins, diamonds;
  for (i = 0; i < n; i++) {
    cin >> x >> y >> ch;
    if (ch == 'C') {
      if (c >= y) mc = max(mc, x), coins.push_back({y, x});
    } else {
      if (d >= y) md = max(md, x), diamonds.push_back({y, x});
    }
  }
  int ans = 0;
  if (mc > 0 && md > 0) ans = mc + md;
  sort(coins.begin(), coins.end());
  sort(diamonds.begin(), diamonds.end());
  ans = max(ans, solve(coins, c));
  ans = max(ans, solve(diamonds, d));
  printf("%d ", ans);
  return 0;
}
