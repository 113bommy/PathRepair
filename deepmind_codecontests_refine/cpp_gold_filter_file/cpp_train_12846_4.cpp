#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 69;
int m, n;
int a[MAXN][MAXN];
int p[MAXN][MAXN];
vector<int> tmp[MAXN];
vector<int> val;
int check(int x) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      p[i][j] = 0;
    }
  }
  for (int i = 1; i <= m; i++) {
    tmp[i].clear();
    tmp[i].shrink_to_fit();
    for (int j = 1; j <= n; j++) {
      if (a[i][j] >= x) tmp[i].push_back(j);
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < tmp[i].size(); j++) {
      for (int k = j + 1; k < tmp[i].size(); k++) {
        int u = tmp[i][j];
        int v = tmp[i][k];
        if (p[u][v]) return 1;
        p[u][v] = 1;
      }
    }
  }
  return 0;
}
void bin() {
  int l = 0;
  int r = m * n - 1;
  int ans = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (mid < 0 || mid >= m * n) break;
    if (check(val[mid])) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  cout << val[ans];
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> m >> n;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
      val.push_back(a[i][j]);
    }
  }
  sort(val.begin(), val.end());
  bin();
}
