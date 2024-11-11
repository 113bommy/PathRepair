#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
const int mod = 1e9 + 7;
int p[N], r[N];
vector<int> g[200005];
int n, m;
int ans = 0;
int get(int x) {
  if (x == p[x]) return x;
  return p[x] = get(p[x]);
}
void unite(int x, int y) {
  int yy = y;
  x = get(x);
  y = get(y);
  if (x != y) {
    if (r[x] < r[y]) {
      swap(x, y);
    }
    p[y] = x;
    if (r[x] == r[y]) r[x]++;
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  srand(time(0));
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    p[i] = i;
    r[i] = 1;
  }
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    g[x].push_back(y);
    g[y].push_back(x);
    unite(x, y);
  }
  vector<int> gg[n];
  for (int i = 0; i < n; ++i) {
    gg[get(i)].push_back(i);
  }
  for (int i = 0; i < n; ++i) {
    if (!gg[i].size()) continue;
    int f = 1;
    for (auto j : gg[i]) {
      if (g[j].size() != 2) f = 0;
    }
    if (f) ++ans;
  }
  cout << ans;
}
