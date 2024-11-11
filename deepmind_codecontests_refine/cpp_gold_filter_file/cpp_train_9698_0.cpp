#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2")
void done() {
  cout << -1 << "\n";
  exit(0);
}
long long a[100005];
long long b[100005];
int32_t main() {
  long long n, m;
  scanf("%lld%lld", &n, &m);
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - (((0) > (n)) << 1))
    scanf("%lld", &a[i]);
  for (__typeof(m) i = (0) - ((0) > (m)); i != (m) - ((0) > (m));
       i += 1 - (((0) > (m)) << 1))
    scanf("%lld", &b[i]);
  long long s1 = accumulate(a, a + n, 0LL);
  long long mx1 = *(max_element(a, a + n));
  long long mn2 = *(min_element(b, b + m));
  if (mn2 < mx1) done();
  s1 *= m;
  for (__typeof(m) i = (0) - ((0) > (m)); i != (m) - ((0) > (m));
       i += 1 - (((0) > (m)) << 1)) {
    s1 += b[i] - mx1;
  }
  if (mx1 == mn2) {
    cout << s1 << "\n";
  } else {
    sort(a, a + n);
    reverse(a, a + n);
    long long x = a[1];
    s1 -= mn2 - mx1;
    s1 += mn2 - x;
    cout << s1 << "\n";
  }
  return 0;
}
