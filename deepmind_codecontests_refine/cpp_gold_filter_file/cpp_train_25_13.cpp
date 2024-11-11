#include <bits/stdc++.h>
using namespace std;
int main() {
  long long q = 1, i, j, test;
  cin >> q;
  for (test = 1; test < (q + 1); test++) {
    long long n;
    cin >> n;
    char a[n][n];
    for (i = 0; i < (n); i++)
      for (j = 0; j < (n); j++) cin >> a[i][j];
    vector<pair<int, int> > v;
    int ans = 0;
    if (a[0][1] == a[1][0]) {
      if (a[n - 1][n - 2] == a[0][1]) ans++, v.push_back({n, n - 1});
      if (a[n - 2][n - 1] == a[0][1]) ans++, v.push_back({n - 1, n});
    } else if (a[n - 1][n - 2] == a[n - 2][n - 1]) {
      if (a[n - 1][n - 2] == a[0][1]) ans++, v.push_back({1, 2});
      if (a[n - 2][n - 1] == a[1][0]) ans++, v.push_back({2, 1});
    } else {
      if (a[n - 1][n - 2] == '0') ans++, v.push_back({n, n - 1});
      if (a[n - 2][n - 1] == '0') ans++, v.push_back({n - 1, n});
      if ('1' == a[0][1]) ans++, v.push_back({1, 2});
      if ('1' == a[1][0]) ans++, v.push_back({2, 1});
    }
    cout << ans << '\n';
    for (i = 0; i < (ans); i++)
      cout << v[i].first << " " << v[i].second << '\n';
  }
}
