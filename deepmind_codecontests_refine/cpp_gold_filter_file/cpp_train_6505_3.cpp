#include <bits/stdc++.h>
using namespace std;
const long long BIG = 100000000100000;
long long a[100001];
long long b[100001];
long long n, m;
long long max(long long a, long long b) {
  if (a > b)
    return a;
  else
    return b;
}
long long ypa(long long k) {
  for (long long i = 1; i <= n; i++) b[i] = a[i];
  long long t = n;
  long long g = m;
  long long s;
  while (g > 0 && t != 0) {
    while (b[t] == 0 && t != 0) t--;
    if (t >= k) return 0;
    g--;
    s = max(0, k - t);
    while (s != 0 && t != 0) {
      long long mn = min(s, b[t]);
      s -= mn;
      b[t] -= mn;
      while (b[t] == 0 && t != 0) t--;
    }
  }
  if (t == 0)
    return 1;
  else
    return 0;
}
int main() {
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  long long l = 1, r = BIG;
  long long mid;
  while (r - l > 1) {
    mid = (l + r) / 2;
    if (ypa(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << r << endl;
  return 0;
}
