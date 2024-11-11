#include <bits/stdc++.h>
using namespace std;
map<pair<long long, long long>, int> mp;
long long x[2005], y[2005], bot[2005];
int n;
long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }
pair<long long, long long> work(long long a, long long b) {
  if (a < 0) a = -a, b = -b;
  long long tmp = gcd(a, b);
  return pair<long long, long long>(a / tmp, b / tmp);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    x[i] = a * c;
    y[i] = b * c;
    bot[i] = a * a + b * b;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    map<pair<long long, long long>, int> mp;
    mp.clear();
    for (int j = i + 1; j <= n; j++) {
      long long u = x[i] * bot[j] - x[j] * bot[i];
      long long v = y[i] * bot[j] - y[j] * bot[i];
      if (!u && !v)
        ans += n - 1 - i;
      else
        ans += (mp[work(u, v)]++);
    }
  }
  printf("%d", ans);
}
