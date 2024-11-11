#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int m, n, a[100009], b[100009];
long long sa, sb;
long long proca() {
  long long ans = 0;
  ans += sa;
  for (int(x) = (1); (x) < (n); ++(x)) {
    ans += min(sa, (long long)b[x]);
  }
  return ans;
}
long long procb() {
  long long ans = 0;
  ans += sb;
  for (int(x) = (1); (x) < (m); ++(x)) ans += min(sb, (long long)a[x]);
  return ans;
}
int main() {
  while (scanf("%d%d", &m, &n) == 2) {
    sa = sb = 0;
    for (int(x) = (0); (x) < (m); ++(x)) {
      scanf("%d", &a[x]);
      sa += a[x];
    }
    for (int(x) = (0); (x) < (n); ++(x)) {
      scanf("%d", &b[x]);
      sb += b[x];
    }
    sort(a, a + m);
    reverse(a, a + m);
    sort(b, b + n);
    reverse(b, b + n);
    cout << min(proca(), procb()) << '\n';
  }
  return 0;
}
