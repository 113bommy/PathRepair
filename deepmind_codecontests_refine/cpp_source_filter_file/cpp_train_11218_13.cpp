#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  for (int i = 0; i <= (1 << n); ++i) {
    int sum1 = 0, sum2 = 0;
    int ans = 0;
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        sum1 += v[i];
        ++ans;
      } else {
        sum2 += v[i];
      }
    }
    if (sum1 != sum2 && sum1 > 0 && sum2 > 0) {
      cout << ans << endl;
      for (int j = 0; j < n; ++j) {
        if ((i >> j) & 1) {
          cout << j + 1 << ' ';
        }
      }
      return 0;
    }
  }
  cout << -1;
}
