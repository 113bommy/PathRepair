#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, i, flag = 0, j;
  cin >> n >> m;
  long long a[n], b[m];
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < m; i++) cin >> b[i];
  sort(a, a + n);
  sort(b, b + m);
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (a[i] == b[j]) {
        flag = 1;
        cout << a[i];
        return 0;
      }
    }
  }
  if (!flag) {
    cout << min(a[0], b[0]) << max(a[0], b[0]);
  }
  return 0;
}
