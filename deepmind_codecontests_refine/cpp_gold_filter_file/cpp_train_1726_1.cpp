#include <bits/stdc++.h>
using namespace std;
int a[200], b[200];
int main() {
  int n, j, i, L, c = 0, m, bl = 0;
  cin >> n >> L;
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < n; i++) cin >> b[i];
  for (i = 1; i <= L; i++) {
    c = 0;
    for (j = 0; j < n; j++) {
      if (a[j] == b[j]) c++;
      a[j] = a[j] + 1;
      if (a[j] >= L) {
        a[j] = a[j] % L;
        sort(a, a + n);
      }
    }
    if (c == n) {
      bl = 1;
      break;
    }
  }
  (bl == 1) ? cout << "YES" << endl : cout << "NO" << endl;
  return 0;
}
