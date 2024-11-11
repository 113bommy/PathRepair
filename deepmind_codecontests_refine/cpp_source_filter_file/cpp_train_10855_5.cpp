#include <bits/stdc++.h>
using namespace std;
long long nxt() {
  long long x;
  cin >> x;
  return x;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long sum = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    if (sum % n) {
      if (n > 1)
        cout << -1 << '\n';
      else
        cout << 0 << '\n';
      continue;
    } else {
      vector<vector<int>> res;
      int eq = sum / n;
      vector<int> rem;
      for (int i = 1; i < n; i++) {
        int tar = ceil((double)a[i] / (i + 1)) * (i + 1);
        res.push_back({1, i + 1, tar - a[i]});
        a[0] -= tar - a[i];
        a[i] = tar;
        res.push_back({i + 1, i, tar / (i + 1)});
        a[0] += tar;
        a[i] = 0;
      }
      for (int i = 1; i < n; i++) {
        res.push_back({1, i + 1, eq});
        a[0] -= eq;
        a[i] += eq;
      }
      cout << res.size() << '\n';
      for (int i = 0; i < res.size(); i++) {
        cout << res[i][0] << " " << res[i][1] << " " << res[i][2] << '\n';
      }
    }
  }
  return 0;
}
