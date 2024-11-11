#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, ans = 0;
  cin >> n;
  int a[n + 10], b[n + 10];
  pair<int, int> cmp[2 * 100000 + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    cmp[i].first = a[i];
    cmp[i].second = b[i];
  }
  int m;
  cin >> m;
  int c[m + 10], d[m + 10];
  for (int i = 1; i <= m; i++) {
    cin >> c[i] >> d[i];
    cmp[n + i].first = c[i];
    cmp[n + i].second = d[i];
  }
  sort(cmp + 1, cmp + n + m + 1);
  for (int i = n + m; i >= 1; i--) {
    if (cmp[i].first != cmp[i - 1].first)
      ans = ans + cmp[i].second;
    else {
      ans = ans + cmp[i].second;
      i--;
    }
  }
  cout << ans;
}
