#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int cnt[1000] = {0};
  vector<pair<int, int>> f[1000];
  for (int i = 1; i <= n; i++) {
    int s, mask = 0;
    cin >> s;
    for (int d = 1; d <= s; d++) {
      int x;
      cin >> x;
      x--;
      mask |= 1 << x;
    }
    cnt[mask]++;
  }
  for (int i = 1; i <= m; i++) {
    int cost, mask = 0, s;
    cin >> cost;
    cin >> s;
    for (int d = 1; d <= s; d++) {
      int x;
      cin >> x;
      x--;
      mask |= 1 << x;
    }
    f[mask].push_back({cost, i});
  }
  int msk = 1 << 9;
  for (int i = 0; i < msk; i++) sort(f[i].begin(), f[i].end());
  int num = 0, price = 0;
  int j1, j2;
  for (int x = 0; x < msk; x++)
    for (int y = 0; y < msk; y++) {
      int per = 0, s = (x | y);
      for (int k = 0; k < msk; k++) {
        if ((s & k) == k) per += cnt[k];
      }
      if (x == y) {
        if (f[x].size() >= 2) {
          if (num < per ||
              (num == per && price > f[x][0].first + f[x][1].first)) {
            num = per;
            j1 = f[x][0].second;
            j2 = f[x][1].second;
            price = f[x][0].first + f[x][1].first;
          }
        }
      } else {
        if (f[x].size() && f[y].size()) {
          if (num < per ||
              (num == per && price > f[x][0].first + f[y][0].first)) {
            num = per;
            j1 = f[x][0].second;
            j2 = f[y][0].second;
            price = f[x][0].first + f[y][0].first;
          }
        }
      }
    }
  cout << j1 << " " << j2;
}
