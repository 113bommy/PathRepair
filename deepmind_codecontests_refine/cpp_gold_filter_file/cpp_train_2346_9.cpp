#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const int N = 1e5 + 10;
vector<pair<int, string> > a[N];
int32_t main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int x, v;
    cin >> x >> v;
    a[x].push_back({v, s});
  }
  for (int i = 1; i <= m; i++) {
    sort(a[i].begin(), a[i].end());
    reverse(a[i].begin(), a[i].end());
    if (a[i].size() == 2) {
      cout << a[i][0].second << " " << a[i][1].second << endl;
    } else {
      if (a[i][1].first == a[i][2].first) {
        cout << '?' << endl;
      } else {
        cout << a[i][0].second << " " << a[i][1].second << endl;
      }
    }
  }
}
