#include <bits/stdc++.h>
using namespace std;
double eps = 0.0000001;
pair<double, int> ar[55];
double cups[55];
vector<vector<pair<int, double>>> res(55);
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k, m;
  cin >> n >> k >> m;
  double ans = ((double)n / m) * k;
  for (int i = 0; i < n; i++) {
    ar[i].first = k;
    ar[i].second = 0;
  }
  bool fl = false;
  if (n * 2 < m) {
    fl = true;
  }
  int cntar = 0, cntcups = 0;
  while (cntar < n) {
    if (ar[cntar].first <= ans && cups[cntcups] + ar[cntar].first <= ans) {
      res[cntcups].push_back(make_pair(cntar, ar[cntar].first));
      cups[cntcups] += ar[cntar].first;
      ar[cntar].first = 0;
      ar[cntar].second++;
      cntar++;
    } else {
      res[cntcups].push_back(make_pair(cntar, ans - cups[cntcups]));
      ar[cntar].first -= ans - cups[cntcups];
      cups[cntcups] += ans - cups[cntcups];
      ar[cntar].second++;
      cntcups++;
    }
    if (ar[cntar].second > 2) {
      fl = true;
    }
  }
  map<int, int> mp;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < res[i].size(); j++) {
      if (res[i][j].second > eps) {
        mp[res[i][j].first + 1]++;
      }
      if (mp[res[i][j].first] > 2) {
        fl = true;
      }
    }
  }
  if (fl) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < res[i].size(); j++) {
        if (res[i][j].second > eps) {
          cout << fixed << setprecision(6) << res[i][j].first + 1 << " "
               << fixed << setprecision(6) << res[i][j].second << " ";
        }
      }
      cout << endl;
    }
  }
  return 0;
}
