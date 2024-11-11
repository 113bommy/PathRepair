#include <bits/stdc++.h>
using namespace std;
long long poww(long long a, long long b) {
  long long res = 1;
  a %= 1000000007;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % 1000000007;
    a = a * a % 1000000007;
  }
  return res;
}
long long n, m, rem[1000006], arr[1000006], temp;
set<long long> s;
set<long long>::iterator it;
int main() {
  long long tc = 1, i, x, t, ans = 0, p;
  while (tc--) {
    scanf("%lld %lld", &n, &m);
    for (i = 0; i < n; i++) {
      scanf("%lld", &arr[i]);
      rem[arr[i] % m]++;
    }
    temp = n / m;
    for (i = 0; i < m; i++) {
      if (rem[i] < temp) s.insert(i);
    }
    for (i = 0; i < n; i++) {
      x = arr[i] % m;
      if (rem[x] < temp) continue;
      if (rem[x] > temp) {
        it = s.lower_bound(x);
        p = *it;
        if (it != s.end()) {
          t = p - x;
        } else {
          it = s.begin();
          p = *it;
          t = m - p - x;
        }
        rem[p]++;
        rem[x]--;
        if (rem[p] == temp) s.erase(it);
        arr[i] += t;
        ans += t;
      }
    }
    printf("%lld ", ans);
    printf("\n");
    for (i = 0; i < n; i++) printf("%lld ", arr[i]);
  }
  return 0;
}
