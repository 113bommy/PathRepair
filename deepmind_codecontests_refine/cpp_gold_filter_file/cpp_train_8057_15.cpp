#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
const long long int maxn = 2e5 + 16, md = 1e9 + 7, inf = 2e16;
long long int gcd(long long int a, long long int b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int tav(long long int n, long long int k) {
  long long int res = 1;
  while (k > 0) {
    if (k & 1) {
      res *= n;
      res %= md;
    }
    n *= n;
    n %= md;
    k >>= 1;
  }
  return res;
}
long long int n, m;
long long int a[maxn], b[maxn];
bool check(long long int z) {
  long long int x = 0;
  for (long long int i = 0; i < n; i++) {
    long long int h;
    if (b[x] < a[i]) {
      if (a[i] - z > b[x]) return false;
      h = max(a[i] + (b[x] + z - a[i]) / 2ll, b[x] + z - (a[i] - b[x]));
    } else {
      h = a[i] + z;
    }
    while (b[x] <= h) x++;
  }
  return (x == m);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  b[m] = inf;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (long long int i = 0; i < m; i++) {
    cin >> b[i];
  }
  long long int l = -1, r = 2e10;
  while (l < r - 1) {
    long long int m = (r + l) >> 1;
    if (check(m)) {
      r = m;
    } else {
      l = m;
    }
  }
  cout << l + 1 << '\n';
  return 0;
}
