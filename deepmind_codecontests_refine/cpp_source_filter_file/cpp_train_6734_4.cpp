#include <bits/stdc++.h>
using namespace std;
int n, k, l, m, id, mi, ma, mid, a[100005];
long long res = 0;
int main() {
  int i, j;
  scanf("%d", &n), scanf("%d", &k), scanf("%d", &l);
  m = n * k;
  for (i = 1; i <= m; i++) {
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + m + 1);
  if (a[n] - a[1] > l) {
    cout << 0 << endl;
    return 0;
  }
  res = a[1];
  if (n == 1) {
    cout << res << '\n';
    return 0;
  }
  id = (n - 1) * k + 1;
  mi = 1, ma = m;
  id = a[1] + l;
  while (mi != ma) {
    mid = (mi + ma + 1) >> 1;
    if (a[mid] <= id)
      mi = mid;
    else
      ma = mid - 1;
  }
  id = mi;
  id = min(id, (n - 1) * k + 1);
  res += a[id];
  int rr = k;
  for (i = 2; i < n; i++) {
    rr += k;
    id = min(id - 1, m - 2 * k + 1);
    res += a[id];
  }
  cout << res << endl;
}
