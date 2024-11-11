#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int inf = 1e9;
int mod = 1e9 + 7;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int m;
    cin >> m;
    int n = 2 * m - 1;
    int a[n], b[n];
    long long int a_total = 0, b_total = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
      a_total += a[i];
      b_total += b[i];
    }
    vector<int> ans;
    int orange[n];
    for (int i = 0; i < n; i++) orange[i] = i;
    sort(orange, orange + n, [&](int x, int y) { return b[x] < b[y]; });
    long long int odd = 0, even = 0;
    for (int i = 0; i < n; i++) {
      int j = orange[i];
      if (i & 1)
        odd += a[j];
      else
        even += a[j];
    }
    if (2 * even >= b_total) {
      for (int i = 0; i < n; i += 2) {
        ans.push_back(orange[i]);
      }
    } else {
      for (int i = 1; i < n; i += 2) {
        ans.push_back(orange[i]);
      }
      ans.push_back(orange[n - 1]);
    }
    cout << "YES\n";
    for (int u : ans) {
      cout << u + 1 << " ";
    }
    cout << "\n";
  }
  return 0;
}
