#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long n) {
  long long r = 1;
  while (n) {
    if (n % 2 == 1) r = (r * x);
    n /= 2;
    x = (x * x);
  }
  return r;
}
int main() {
  long long n;
  scanf("%lld", &n);
  long long a[n], i, j;
  map<long long, long long> mp;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]] = 1;
  }
  sort(a, a + n);
  long long ans = 0;
  long long base, po;
  for (i = 0; i < n; i++) {
    for (j = 1; a[i] + 2 * j <= 1e9; j *= 2) {
      long long count = 1;
      if (mp.find(a[i] + j) != mp.end()) {
        count++;
        if (mp.find(a[i] + (2 * j)) != mp.end()) count++;
      }
      if (ans <= count) {
        base = a[i];
        po = j;
        ans = count;
      }
    }
  }
  printf("%lld\n", ans);
  printf("%lld ", base);
  base += po;
  if (mp.find(base) != mp.end()) printf("%lld ", base);
  base += po;
  if (mp.find(base) != mp.end()) printf("%lld ", base);
  return 0;
}
