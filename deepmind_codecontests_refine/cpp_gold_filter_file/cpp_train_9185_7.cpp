#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 7;
long long res, n, m, cnt, ans, a, b, sum, mx, mn, c, d;
int main() {
  long long T;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    vector<int> d(m * 2 + 2, 0);
    pair<long long, long long> v[n + 1];
    long long arr[n + 1];
    sum = ans = 0;
    for (int i = 1; i <= n; i++) {
      cin >> arr[i];
    }
    for (int i = 1; i <= n / 2; i++) {
      v[i] = {arr[i], arr[n - i + 1]};
    }
    d[1] = 2 * (n / 2);
    for (int i = 1; i <= n / 2; i++) {
      mn = min(1 + v[i].second, v[i].first + 1);
      mx = max(m + v[i].second, v[i].first + m);
      d[m * 2 + 1] -= 2;
      d[mn] -= 1, d[mx + 1] += 1;
      d[v[i].second + v[i].first] -= 1, d[v[i].second + v[i].first + 1] += 1;
    }
    sum = d[1], ans = sum;
    for (int i = 2; i <= m * 2; i++) {
      sum += d[i], ans = min(ans, sum);
    }
    cout << ans << endl;
  }
}
