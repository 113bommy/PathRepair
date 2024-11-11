#include <bits/stdc++.h>
using namespace std;
const int N = 110000;
long long n, c, a[N], b[N];
long long f(long long x) {
  long long res = 0;
  for (int i = 0; i < n; i++) res += 1 + (x * a[i]) / b[i];
  return res;
}
int main() {
  cin >> n >> c;
  for (int i = 0; i < n; i++) scanf("%I64d%I64d", &a[i], &b[i]);
  long long l = 1, r = 1e18;
  while (r - l > 1) {
    long long m = (l + r) / 2;
    if (f(m) <= c)
      l = m;
    else
      r = m;
  }
  if (f(l) != c) {
    cout << 0;
    return 0;
  }
  long long ansmax = l;
  l = 0, r = 1e18;
  while (r - l > 1) {
    long long m = (l + r) / 2;
    if (f(m) < c)
      l = m;
    else
      r = m;
  }
  if (f(r) != c) {
    cout << 0;
    return 0;
  }
  long long ansmin = r;
  cout << ansmax - ansmin + 1;
}
