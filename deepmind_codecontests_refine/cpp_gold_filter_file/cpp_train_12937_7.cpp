#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
int n, a[N], ans[N][3];
bool ok(int x) {
  for (int i = 0; i < x; i++) ans[i][0] = a[i];
  int id = 0, num = 0;
  for (int j = x; j < n; j++) {
    if (a[j] > ans[num][id]) {
      ans[num][id + 1] = a[j];
      num++;
      if (num >= x) num = 0, id++;
      if (id == 2) return true;
    }
  }
  return false;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  int l = 0, r = (n + 3) / 3;
  int res = 0;
  while (l <= r) {
    int m = (l + r) / 2;
    if (ok(m))
      l = m + 1, res = m;
    else
      r = m - 1;
  }
  cout << res << '\n';
  ok(res);
  for (int i = 0; i < res; i++) {
    cout << ans[i][2] << " " << ans[i][1] << " " << ans[i][0] << '\n';
  }
  return 0;
}
