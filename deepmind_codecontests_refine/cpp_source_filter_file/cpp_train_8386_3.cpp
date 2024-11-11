#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int fa[maxn];
bool isg[maxn];
int se[maxn], sv[maxn];
int find(int x) {
  if (fa[x] != x) fa[x] = find(fa[x]);
  return fa[x];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  int n, m, g;
  cin >> n >> m >> g;
  for (int j = 1; j <= n; ++j) {
    fa[j] = j;
    sv[j] = 1;
  }
  for (int j = 1; j <= g; ++j) {
    int x;
    cin >> x;
    isg[x] = 1;
  }
  for (int j = 1; j <= m; ++j) {
    int x, y;
    cin >> x >> y;
    int fx = find(x), fy = find(y);
    ++se[fx];
    if (fx != fy) {
      if (isg[fx]) {
        fa[fy] = fx;
        se[fx] += se[fy];
        sv[fx] += sv[fy];
      } else {
        fa[fx] = fy;
        se[fy] += se[fx];
        sv[fy] += sv[fx];
      }
    }
  }
  int sum = 0;
  int ans = 0;
  vector<int> gg;
  for (int j = 1; j <= n; ++j) {
    if (fa[j] == j) {
      if (isg[j]) {
        ans += (sv[j] * (sv[j] - 1) / 2) - se[j];
        gg.push_back(sv[j]);
      }
    }
  }
  sort(gg.begin(), gg.end());
  int ma = gg[gg.size() - 1];
  for (int j = 1; j <= n; ++j) {
    if (fa[j] == j) {
      if (!isg[j]) {
        int sho = 0;
        for (int j = 1; j <= sv[j]; ++j) {
          sho += ma;
          ++ma;
        }
        ans += sho - se[j];
      }
    }
  }
  cout << ans << endl;
  return 0;
}
