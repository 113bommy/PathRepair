#include <bits/stdc++.h>
using namespace std;
long long n, a[1000006], l[1000006][2], r[1000006][2], dl[1000006], dr[1000006];
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) cin >> a[i];
  for (int i = 2; i <= n; i++) {
    if (a[i - 1] > 1) {
      l[i][1] = l[i - 1][1] + a[i - 1];
      if (a[i - 1] & 1) l[i][1]--, dl[i] = dl[i - 1] + 1;
    }
    l[i][0] = max(l[i - 1][1], l[i - 1][0]) + a[i - 1];
    if (!(a[i - 1] & 1)) l[i][0]--;
  }
  for (int i = n - 1; i > 0; i--) {
    if (a[i] > 1) {
      r[i][1] = r[i + 1][1] + a[i];
      if (a[i] & 1) r[i][1]--, dr[i] = dr[i + 1] + 1;
    }
    r[i][0] = max(r[i + 1][1], r[i + 1][0]) + a[i];
    if (!(a[i] & 1)) r[i][0]--;
  }
  long long res = 0;
  for (int i = 1; i <= n; i++) {
    long long x = l[i][1] + max(r[i][0], r[i][1] + dl[i]);
    long long y = r[i][1] + max(l[i][0], l[i][1] + dr[i]);
    res = max(max(x, y), res);
  }
  cout << res;
  return 0;
}
