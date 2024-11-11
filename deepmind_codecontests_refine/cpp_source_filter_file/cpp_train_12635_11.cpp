#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, j, k, m, n, t, p = 0, c, min, s, f = 0;
  long long a[100009] = {0};
  cin >> n >> k;
  min = 99999999LL;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    j = a[i];
    if (j < 0) j = -1 * j;
    if (j < min) min = j;
  }
  c = 0;
  s = 0;
  for (i = 1; i <= n; i++) {
    if (a[i] < 0 && (c + 1) <= k) {
      s = s + (-1 * a[i]);
      c++;
    } else
      s += a[i];
  }
  if (n == 1) {
    if (k % 2 == 0)
      cout << a[1] << endl;
    else {
      cout << -a[1] << endl;
    }
  } else if (c == k)
    cout << s << endl;
  else if (c < k) {
    if ((k - c) % 2 == 0)
      cout << s << endl;
    else
      cout << s - min << endl;
  }
  return 0;
}
