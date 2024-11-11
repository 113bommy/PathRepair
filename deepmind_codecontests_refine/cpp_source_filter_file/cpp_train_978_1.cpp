#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000 + 100;
int n, t;
long long a[maxn];
long long dv[100000];
int cnt[100000];
long long gcd(long long x, long long y) {
  while (x) {
    long long tmp = x;
    x = y % x;
    y = x;
  }
  return y;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0, _n = (int)(n); i < _n; i++) cin >> a[i];
  random_shuffle(a, a + n);
  random_shuffle(a, a + n);
  long long ans = 0;
  for (int z = 0, _n = (int)(min(n, 13)); z < _n; z++) {
    long long x = a[z];
    t = 0;
    for (long long i = 1; i * i <= x; i++)
      if (x % i == 0) dv[t++] = i, (i * i != x ? dv[t++] = x / i : 0);
    sort(dv, dv + t);
    memset(cnt, 0, t * sizeof(cnt[0]));
    for (int i = 0, _n = (int)(n); i < _n; i++)
      cnt[lower_bound(dv, dv + t, gcd(a[z], a[i])) - dv]++;
    for (int i = 0, _n = (int)(t); i < _n; i++)
      for (int j = 0, _n = (int)(i); j < _n; j++)
        if (dv[i] % dv[j] == 0) cnt[j] += cnt[i];
    for (int i = 0, _n = (int)(t); i < _n; i++)
      if (cnt[i] * 2 >= n) ans = max(ans, dv[i]);
  }
  cout << ans << endl;
  {
    int _;
    cin >> _;
    return 0;
  }
}
