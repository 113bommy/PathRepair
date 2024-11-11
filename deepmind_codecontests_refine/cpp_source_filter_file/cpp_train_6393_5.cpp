#include <bits/stdc++.h>
using namespace std;
long long a[100010], sum, sum1, b, cnt;
multiset<long long> s;
int binpow(long long a, long long n) {
  int res = 1;
  while (n)
    if (n & 1) {
      res *= a;
      res %= 1000000007;
      --n;
    } else {
      a *= a;
      a %= 1000000007;
      n >>= 1;
    }
  return res;
}
int main() {
  int n, x;
  cin >> n >> x;
  for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
  reverse(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) s.insert(a[1] - a[i]);
  sum1 = sum - a[1];
  while (true) {
    b = *s.begin();
    cnt = s.size();
    s.erase(b);
    cnt = cnt - s.size();
    if (cnt % x == 0) {
      for (int i = 1; i <= cnt / x; i++) s.insert(b + 1);
    } else {
      sum1 += b;
      break;
    }
  }
  cout << binpow(x, min(sum1, sum));
  return 0;
}
