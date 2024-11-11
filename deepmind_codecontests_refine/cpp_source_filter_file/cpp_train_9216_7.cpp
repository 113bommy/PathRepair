#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, b, c, d, ans, flag = 0, q, r, s, p;
  cin >> n >> a >> b >> c >> d;
  for (p = 1; p <= n; p++) {
    r = p - d + a;
    q = p - c + b;
    s = p + a + b - c - d;
    if (r <= n && q <= n && s <= n && r >= 1 && q >= 1 && s >= 1) {
      flag = 1;
      break;
    }
  }
  if (n == 1)
    cout << 1 << endl;
  else if (flag == 1) {
    long long max = p;
    if (max < r) max = r;
    if (max < q) max = q;
    if (max < s) max = s;
    ans = n - max + 1;
    cout << ans * (n - 1) << endl;
  } else
    cout << 0 << endl;
  return 0;
}
