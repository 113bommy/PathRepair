#include <bits/stdc++.h>
using namespace std;
const int maxx = 1e9;
int a[1005], i, j;
int main() {
  int n;
  int ma = -maxx, mi = maxx, k = maxx, d;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (i = 0; i <= 20005; i++) {
    ma = -maxx, mi = maxx;
    for (j = 1; j <= n; j++) {
      ma = max(ma, a[j] - (j - 1) * i);
      mi = min(mi, a[j] - (j - 1) * i);
    }
    if ((ma - mi + 1) / 2 < k) {
      k = (ma - mi + 1) / 2;
      a[0] = k + mi;
      d = i;
    }
  }
  cout << k << endl << a[0] << " " << d << endl;
  return 0;
}
