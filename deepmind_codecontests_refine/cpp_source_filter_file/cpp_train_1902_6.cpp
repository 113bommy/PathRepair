#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, a, b, c, d, i, j, k, l, n, m, x, y;
  cin >> t;
  while (t--) {
    cin >> n;
    map<long long int, long long int> dp;
    for (i = 0; i < n; i++) {
      cin >> a;
      dp[a]++;
    }
    vector<long long int> v;
    for (i = 0; i < n + 5; i++) {
      if (dp[i] > 0) {
        b = dp[i];
        v.push_back(b);
      }
    }
    sort(v.begin(), v.end(), greater<long long int>());
    x = 0;
    y = 0;
    l = 0;
    k = 0;
    m = v[0];
    for (i = 1; i < v.size(); i++) {
      x += v[i];
      if (m - x == 1) {
        l++;
        x = 0;
      } else if (x == m) {
        x = 1;
        l++;
      } else if (x > m) {
        l++;
        x = x - (m - 1);
      }
    }
    cout << l << endl;
    dp.clear();
    v.clear();
  }
}
