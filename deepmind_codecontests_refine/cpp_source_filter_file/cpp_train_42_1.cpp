#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
long long n;
vector<long long> cordX[N], cordY[N];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = 1; i <= n; ++i) {
    long long x, y;
    cin >> x >> y;
    cordX[x].push_back(y);
    cordY[y].push_back(x);
  }
  for (long long i = 0; i <= 100000; ++i) {
    sort(cordX[i].begin(), cordX[i].end());
    sort(cordY[i].begin(), cordY[i].end());
  }
  long long ans = 0;
  for (long long i = 0; i <= 100000; ++i) {
    for (long long j = 0; j < (long long)cordX[i].size(); ++j) {
      long long x = i, y = cordX[i][j];
      long long idx1 = j + 1;
      long long idx2 =
          upper_bound(cordY[y].begin(), cordY[y].end(), x) - cordY[y].begin();
      while (idx1 < (long long)cordX[x].size() &&
             idx2 < (long long)cordY[y].size()) {
        long long y1 = cordX[x][idx1];
        long long x1 = cordY[y][idx2];
        if (y1 - y > x1 - x) {
          ++idx2;
        } else if (y1 - y < x1 - x) {
          ++idx1;
        } else {
          ans += binary_search(cordX[y1].begin(), cordX[y1].end(), x1);
          ++idx1;
          ++idx2;
        }
      }
    }
  }
  cout << ans;
}
