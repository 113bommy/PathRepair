#include <bits/stdc++.h>
using namespace std;
long long Getsqrnum(long long x) {
  if (x <= 0) return 0;
  long long c = sqrt(x - 1);
  while (c * c <= x) c++;
  c--;
  return c;
}
int main() {
  int n, m;
  while (cin >> n >> m) {
    long long ans = 0;
    for (long long i = 1; i <= n; i++) {
      long long t = 1;
      t = t * i * i;
      long long w;
      if (t >= m) {
        w = m - (Getsqrnum(t - 1) - Getsqrnum(t - m - 1));
      } else {
        w = t - Getsqrnum(t);
      }
      ans += w * 2;
    }
    for (long long i = 1; i <= 2 * n; i++) {
      long long t1 = (i * i + m);
      if (t1 % (2 * i) == 0)
        t1 = t1 / (2 * i);
      else
        t1 = t1 / (2 * i);
      long long t2 = (i * i + 1);
      if (t2 % (2 * i) == 0)
        t2 = t2 / (2 * i);
      else
        t2 = t2 / (2 * i) + 1;
      if (t2 > n || t1 == 0 || t1 < t2)
        continue;
      else
        ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
