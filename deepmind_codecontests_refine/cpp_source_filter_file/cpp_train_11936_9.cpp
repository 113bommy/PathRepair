#include <bits/stdc++.h>
using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;
i64 ipow(i64 x, i64 n) {
  if (n == 0) return 1ll;
  i64 half = ipow(x, n / 2);
  half = (half * half) % 1000000007;
  if (n % 2 == 0)
    return half;
  else
    return (half * x) % 1000000007;
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<i64> s1(n);
  vector<i64> s2(n);
  for (int i = 0; i < n; i++) scanf("%lld", &s1[i]);
  for (int i = 0; i < n; i++) scanf("%lld", &s2[i]);
  vector<i64> ps(n + 1);
  vector<i64> qs(n + 1);
  ps[n] = 0;
  qs[n] = 1;
  for (int i = n - 1; i >= 0; i--) {
    qs[i] = qs[i + 1];
    if (s1[i] == 0) qs[i] = (qs[i] * m) % 1000000007;
    if (s2[i] == 0) qs[i] = (qs[i] * m) % 1000000007;
  }
  for (int i = n - 1; i >= 0; i--) {
    if (s1[i] != 0 && s2[i] != 0) {
      if (s1[i] == s2[i])
        ps[i] = ps[i + 1];
      else if (s1[i] > s2[i])
        ps[i] = qs[i + 1];
      else
        ps[i] = 0;
    } else if (s1[i] == 0 && s2[i] != 0) {
      ps[i] = ps[i + 1];
      ps[i] += (qs[i + 1] * (m - s2[i])) % 1000000007;
      ps[i] %= 1000000007;
    } else if (s1[i] != 0 && s2[i] == 0) {
      ps[i] = ps[i + 1];
      ps[i] += (qs[i + 1] * (s1[i] - 1)) % 1000000007;
      ps[i] %= 1000000007;
    } else if (s1[i] == 0 && s2[i] == 0) {
      ps[i] = (m * ps[i + 1]) % 1000000007;
      i64 arg = (m * (m - 1) / 2) % 1000000007;
      ps[i] += (qs[i + 1] * arg) % 1000000007;
      ps[i] %= 1000000007;
    }
  }
  printf("%lld\n", (ps[0] * ipow(qs[0], 1000000007 - 2)) % 1000000007);
  return 0;
}
