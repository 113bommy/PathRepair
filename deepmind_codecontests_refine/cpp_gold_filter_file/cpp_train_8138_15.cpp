#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a, b;
  cin >> n >> m;
  vector<int> x(m);
  vector<long long> ans(n + 1, 0);
  for (int i = 0; i < m; i++) {
    cin >> x[i];
    if (i > 0) {
      ans[0] += abs(x[i] - x[i - 1]);
      if (x[i] < x[i - 1])
        a = x[i], b = x[i - 1];
      else if (x[i] > x[i - 1])
        a = x[i - 1], b = x[i];
      if (x[i] != x[i - 1]) {
        ans[a + 1]--;
        ans[b]++;
        ans[a] += a - 1;
        ans[a + 1] -= a - 1;
        ans[b] += a - (b - a);
        if (b < n) ans[b + 1] -= a - (b - a);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    ans[i + 1] += ans[i];
    cout << ans[i + 1] << ' ';
  }
  cout << endl;
  return 0;
}
