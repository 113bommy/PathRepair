#include <bits/stdc++.h>
using namespace std;
long long n, totalsum, sum, a[500000], i, l, r, m, ans;
vector<int> c, g;
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i], totalsum += a[i];
  if (totalsum % 3 != 0) {
    cout << 0 << endl;
    return 0;
  }
  totalsum /= 3;
  for (i = 1; i <= n; i++) {
    sum = sum + a[i];
    if (sum == totalsum) g.push_back(i);
  }
  sum = 0;
  for (i = n; i >= 1; i--) {
    sum = sum + a[i];
    if (sum == totalsum) c.push_back(i);
  }
  sort(c.begin(), c.end());
  for (i = 0; i < g.size(); i++) {
    l = 0;
    r = c.size() - 1;
    while (l + 1 < r) {
      m = (l + r) / 2;
      if (c[m] > g[i] + 1)
        r = m;
      else
        l = m + 1;
    }
    if (c[l] > g[i] + 1)
      ans += c.size() - l;
    else if (c[r] > g[i] + 1)
      ans += c.size() - r;
  }
  cout << ans << endl;
}
