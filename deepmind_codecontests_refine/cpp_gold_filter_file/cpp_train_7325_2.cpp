#include <bits/stdc++.h>
using namespace std;
vector<int> fact;
const int mod = 1e9 + 7;
int a[100004];
int n;
long long int ans;
long long int pow(int b, int p) {
  if (p == 0) return 1;
  long long int a = pow(b, p / 2);
  a = (a * a) % mod;
  if (p % 2 == 0)
    return a;
  else
    return (a * b) % mod;
}
long long int solve(int m) {
  fact.clear();
  int i;
  for (i = 1; i * i <= m; i++) {
    if (m % i == 0) {
      fact.push_back(i);
      if (i * i != m) fact.push_back(m / i);
    }
  }
  sort(fact.begin(), fact.end());
  int cur = 0, prev = 0;
  int sz = fact.size();
  long long int ret = 1;
  for (i = 0; i < sz; i++) {
    cur = lower_bound(a, a + n, fact[i]) - a;
    ret = (ret * (pow(i, cur - prev))) % mod;
    prev = cur;
  }
  ret = (ret * (pow(sz, n - prev) - pow(sz - 1, n - prev) + mod)) % mod;
  return ret;
}
int main() {
  scanf("%d", &n);
  int i;
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a, a + n);
  for (i = 1; i <= a[n - 1]; i++) {
    ans = (ans + solve(i)) % mod;
  }
  printf("%I64d\n", ans);
  return 0;
}
