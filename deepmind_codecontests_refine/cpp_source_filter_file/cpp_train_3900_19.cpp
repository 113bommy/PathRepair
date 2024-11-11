#include <bits/stdc++.h>
using namespace std;
long long int inf = 1e9;
const long long int mod = 1e9 + 7;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n;
  cin >> n;
  vector<vector<long long int> > a(n, vector<long long int>(n));
  vector<long long int> d1(2 * n - 1, 0), d2(2 * n - 1, 0);
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < n; j++) {
      cin >> a[i][j];
      d1[i + j] += a[i][j];
      d2[i - j + n - 1] += a[i][j];
    }
  }
  long long int max1 = 0, max2 = 0;
  pair<long long int, long long int> ans1, ans2;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < n; j++) {
      if ((i + j) % 2 == 0) {
        if (max1 < d1[i + j] + d2[i - j + n - 1] - a[i][j]) {
          max1 = d1[i + j] + d2[i - j + n - 1] - a[i][j];
          ans1 = make_pair(i + 1, j + 1);
        }
      } else {
        if (max2 < d1[i + j] + d2[i - j + n - 1] - a[i][j]) {
          max2 = d1[i + j] + d2[i - j + n - 1] - a[i][j];
          ans2 = make_pair(i + 1, j + 1);
        }
      }
    }
  }
  cout << max1 + max2 << '\n';
  cout << ans1.first << " " << ans1.second << " " << ans2.first << " "
       << ans2.second << '\n';
}
