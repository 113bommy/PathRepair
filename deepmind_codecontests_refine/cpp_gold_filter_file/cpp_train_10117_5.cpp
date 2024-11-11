#include <bits/stdc++.h>
using namespace std;
const int n = 500001, sn = 707;
int q;
long a[n];
long sum[sn][sn];
void answer() {
  int t, x, y;
  cin >> t >> x >> y;
  if (t == 1) {
    a[x] += y;
    for (int i = 1; i < sn; i++) sum[i][x % i] += y;
  } else {
    if (x < sn) {
      cout << sum[x][y] << '\n';
    } else {
      long s = 0;
      for (int i = y; i < n; i += x) s += a[i];
      cout << s << '\n';
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> q;
  for (int i = 0; i < q; i++) answer();
  return 0;
}
