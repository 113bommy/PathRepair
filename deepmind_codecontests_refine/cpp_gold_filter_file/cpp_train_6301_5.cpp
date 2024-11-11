#include <bits/stdc++.h>
using namespace std;
string str;
int ar[100010];
int main() {
  ios::sync_with_stdio(false);
  int i, j, x, y, n, m = 0, k, a, b, c, d, e, f, wa;
  cin >> n >> k;
  cin >> str;
  for (int i = 0; i <= n - 1; i++) {
    if (str[i] == '0') ar[m] = i + 1, m++;
  }
  wa = n;
  for (int i = 0; i <= m - k - 1; i++) {
    a = ar[i];
    b = ar[i + k];
    c = (a + b) / 2;
    d = lower_bound(ar, ar + m, c) - ar;
    e = max(d--, 0);
    f = min(m - 1, d++);
    x = max(abs(ar[d] - ar[i]), abs(ar[i + k] - ar[d]));
    wa = min(wa, x);
    d = f;
    x = max(abs(ar[d] - ar[i]), abs(ar[i + k] - ar[d]));
    wa = min(wa, x);
  }
  cout << wa << '\n';
  return 0;
}
