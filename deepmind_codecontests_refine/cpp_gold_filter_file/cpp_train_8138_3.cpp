#include <bits/stdc++.h>
using namespace std;
vector<long long int> g[200010];
long long int x[200010];
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, m;
  cin >> n >> m;
  for (long long int i = 0; i < m; ++i) {
    cin >> x[i];
    g[x[i]].push_back(i);
  }
  long long int k = 0;
  for (long long int i = 1; i < m; ++i) k += abs(x[i] - x[i - 1]);
  long long int sum = 0;
  for (long long int i = 1; i <= n; ++i) {
    long long int ans = k;
    long long int l = 0, j = 0;
    for (auto e : g[i]) {
      if (e > 0 && x[e] != x[e - 1]) {
        if (x[e] < x[e - 1])
          l++;
        else if (x[e] > x[e - 1])
          j++;
        ans -= abs(x[e] - x[e - 1]) - x[e - 1];
        if (x[e - 1] > i) ans -= 1;
      }
      if (e < m - 1 && x[e + 1] != x[e]) {
        if (x[e + 1] > x[e])
          l++;
        else if (x[e + 1] < x[e])
          j++;
        ans -= abs(x[e] - x[e + 1]) - x[e + 1];
        if (x[e + 1] > i) ans -= 1;
      }
    }
    ans -= sum - j;
    sum += l - j;
    cout << ans << " ";
  }
  return 0;
}
