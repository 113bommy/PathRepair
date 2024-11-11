#include <bits/stdc++.h>
using namespace std;
int n, x, y;
long long get(long long t) {
  long long res = 2 * t * (t + 1) + 1;
  long long h1 = t - x;
  if (h1 > 0) res -= h1 * h1;
  long long h2 = t - n + y + 1;
  if (h2 > 0) res -= h2 * h2;
  long long h3 = t - n + x + 1;
  if (h3 > 0) res -= h3 * h3;
  long long h4 = t - y;
  if (h4 > 0) res -= h4 * h4;
  long long l12 = h1 - n + y;
  if (l12 > 0) res += l12 * (l12 + 1) / 2;
  long long l23 = h2 - n + x;
  if (l23 > 0) res += l23 * (l23 + 1) / 2;
  long long l34 = h3 - y - 1;
  if (l34 > 0) res += l34 * (l34 + 1) / 2;
  long long l41 = h1 - y - 1;
  if (l41 > 0) res += l41 * (l41 + 1) / 2;
  return res;
}
int main() {
  long long c;
  cin >> n >> x >> y >> c;
  --x, --y;
  long long l = 0, r = 3 * n;
  while (l < r) {
    long long m = (l + r) / 2;
    long long cc = get(m);
    if (cc < c)
      l = m + 1;
    else
      r = m;
  }
  cout << l << endl;
  return 0;
}
