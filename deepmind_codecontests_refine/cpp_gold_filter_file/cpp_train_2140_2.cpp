#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, j;
  long long ans = 0;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  for (int i = 0; i < n; i++) {
    long long t;
    j = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    if (j == 0)
      t = abs(b[j] - a[i]);
    else if (j < m)
      t = min(abs(b[j] - a[i]), abs(a[i] - b[j - 1]));
    else
      t = abs(a[i] - b[m - 1]);
    ans = max(ans, t);
  }
  cout << ans;
  return 0;
}
