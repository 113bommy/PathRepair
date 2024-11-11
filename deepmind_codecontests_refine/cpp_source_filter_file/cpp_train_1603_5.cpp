#include <bits/stdc++.h>
#pragma GCC optimise("O3")
#pragma GCC target("sse,sse2,ssse3,sse4")
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pair<pair<int, int>, int> > sp(m);
  int a, l;
  for (int i = 0; i < m; ++i) {
    cin >> a >> l;
    sp[i] = {{a, -(a + l - 1)}, i};
  }
  sort(sp.begin(), sp.end());
  vector<bool> used(m);
  int ind = 0;
  while (ind != m) {
    int e = -sp[ind].first.second;
    used[sp[ind].second] = true;
    ++ind;
    bool fl = true;
    while (fl && ind != m) {
      fl = false;
      int mx = ind;
      while (ind != m && sp[ind].first.first <= e) {
        if (-sp[mx].first.second < -sp[ind].first.second) {
          mx = ind;
        }
        ++ind;
      }
      if (-sp[mx].first.second > e) {
        used[sp[mx].second] = true;
        e = -sp[mx].first.second;
        fl = true;
      }
    }
  }
  int cnt = 0;
  for (int i = 0; i < m; ++i) {
    if (!used[i]) {
      ++cnt;
    }
  }
  cout << cnt << endl;
  for (int i = 0; i < m; ++i) {
    if (!used[i]) {
      cout << i + 1 << " ";
    }
  }
}
