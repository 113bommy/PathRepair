#include <bits/stdc++.h>
using namespace std;
inline int read() {
  bool ok = 0;
  int res = 0;
  char c;
  while (((c = getchar()) < '0' || c > '9') && c != '-')
    ;
  if (c == '-')
    ok = 1;
  else
    res = c - 48;
  while ((c = getchar()) >= '0' && c <= '9')
    res = (res << 3) + (res << 1) + (c - 48);
  return ok ? ~res + 1 : res;
}
int cn3(int n) {
  if (n < 3) return 0;
  return n * (n - 1) * (n - 2) / 6;
}
int cn2(int n) {
  if (n < 2) return 0;
  return n * (n - 1) / 2;
}
int main() {
  int n;
  double p;
  cin >> n >> p;
  for (int a = 0; a <= n; ++a) {
    double ans = 0;
    if (a >= 3) ans += 1.0 * cn3(a) / cn3(n);
    if (n - a >= 1) ans += 1.0 * cn2(a) * (n - a) / cn3(n);
    if (n - a >= 2) ans += 1.0 * a * cn2(n - a) / cn3(n) * 0.5;
    if (ans > p || (abs(ans - p) < 1e-6)) {
      cout << a << endl;
      break;
    }
  }
  return 0;
}
