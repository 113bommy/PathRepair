#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 10;
const long long INF = 1e9 + 7;
const double pi = 3.1415;
int okb[N], okr[N], ans, n, a[N];
vector<int> g[N];
void dfs(int v = 1, int pr = -1) {
  for (auto i : g[v]) {
    if (i == pr) {
      continue;
    }
    dfs(i, v);
    okr[v] += okr[i];
    okb[v] += okb[i];
  }
}
void rec(int v = 1, int pr = -1) {
  for (auto i : g[v]) {
    if (i == pr) {
      continue;
    }
    if ((okr[i] == 0 || okb[i] == 0) &&
        ((okr[1] - okr[i] == 0) || (okb[1] - okb[i] == 0))) {
      ans++;
    }
    rec(i, v);
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == 1) {
      okr[i] = 1;
    } else if (a[i] == 2) {
      okb[i] = 1;
    }
  }
  for (int i = 1, x, y; i <= n - 1; i++) {
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs();
  rec();
  cout << ans;
}
