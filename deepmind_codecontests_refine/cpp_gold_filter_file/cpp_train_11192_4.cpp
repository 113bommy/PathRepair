#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, t, i, j, k, co, f, l, m, temp, flag;
  cin >> n >> t;
  long long a[n], b[t];
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < t; i++) cin >> b[i];
  sort(a, a + n);
  for (i = 0; i < t; i++) {
    flag = 0;
    temp = b[i];
    co = 0;
    f = 0;
    l = n - 1;
    m = (f + l) / 2;
    while (f <= l) {
      if ((a[m] <= temp && a[m + 1] > temp)) {
        co = m + 1;
        break;
      } else if (a[m] <= temp)
        f = m + 1;
      else if (a[m] > temp)
        l = m;
      m = (f + l) / 2;
      if (m == 0) flag++;
      if (flag > 1) break;
    }
    cout << co << " ";
    if (i == t - 1) cout << endl;
  }
  return 0;
}
