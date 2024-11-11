#include <bits/stdc++.h>
using namespace std;
int t, n, k;
bool check(int k, vector<pair<int, int> > a) {
  for (int i = 0; i < n; i++)
    if (k < a[i].first)
      return 0;
    else
      k += a[i].second;
  return 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    vector<pair<int, int> > a;
    for (int i = 1; i <= n; i++) {
      cin >> k;
      int ma = 0;
      for (int j = 1; j <= k; j++) {
        int x;
        cin >> x;
        ma = max(ma, x - j + 2);
      }
      a.push_back({ma, k});
    }
    sort(a.begin(), a.end());
    int l = 1, r = 1e9;
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (check(m, a))
        r = m;
      else
        l = m;
    }
    cout << r;
    cout << "\n";
  }
  return 0;
}
