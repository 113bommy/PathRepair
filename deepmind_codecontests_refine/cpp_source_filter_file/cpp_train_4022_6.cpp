#include <bits/stdc++.h>
using namespace std;
long long n, m, a, d, t[100005], ans, now, num;
long long work(long long x) {
  long long k = (x - now) / num;
  long long r = (x - now) % num;
  ans += k + 1;
  now = x;
  if (r == 0)
    return x * a + d;
  else
    return x * a + d - a * r;
}
int main() {
  cin >> n >> m >> a >> d;
  now = 1;
  ans = 0;
  num = (d + a - 1) / a;
  for (int i = 1; i <= m; i++) cin >> t[i];
  int pos = 1;
  long long tmp;
  for (; pos <= m;) {
    if (now > n) break;
    long long idx = t[pos] / a;
    if (idx > n) idx = n;
    if (idx < now) {
      tmp = t[pos] + d;
      ans++;
    } else {
      tmp = work(idx);
    }
    now = tmp / a + 1;
    while (pos <= m && t[pos] <= tmp) pos++;
  }
  if (now <= n)
    work(n);
  else {
    while (pos <= m) {
      tmp = t[pos] + d;
      ans++;
      while (pos <= m && t[pos] <= tmp) pos++;
    }
  }
  cout << ans << endl;
}
