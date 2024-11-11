#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 10;
long long b[N], a[N], l, i, j, mn = N, mx = -N, ans = 0, r = 0, q = 0, c, d, k;
long long x1, x2, Y, y2;
string d1, d3;
pair<long long, long long> g[N];
char lk, kl;
int main() {
  cin >> mx >> k;
  for (i = 1; i <= min(k * 2, mx); ++i) q += i;
  cout << max(0ll, mx * min(k * 2, mx) - q);
}
