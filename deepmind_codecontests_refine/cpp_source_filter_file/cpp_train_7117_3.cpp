#include <bits/stdc++.h>
using namespace std;
template <class T>
T two(T x) {
  return 1 << x;
}
template <class T>
void Min(T &x, T y) {
  if (y < x) x = y;
}
template <class T>
void Max(T &x, T y) {
  if (y > x) x = y;
}
const int maxn = 100010;
const int mod = 1000000007;
int dp[maxn], a[maxn];
long long PMD(long long a, int b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return res;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]), dp[a[i]] = 1;
  int lim = *max_element(a, a + n);
  for (int i = lim - 1; i >= 0; i--) dp[i] += dp[i + 1];
  vector<int> num;
  long long ans = 0;
  for (int i = 1; i < lim + 1; i++) {
    num.clear();
    for (int j = 1; j * j <= i; j++)
      if (i % j == 0) {
        num.push_back(j);
        if (i / j != j) num.push_back(i / j);
      }
    sort(num.begin(), num.end());
    int sz = num.size();
    long long cnt = 1;
    for (int j = 0; j < sz - 1; j++) {
      cnt = cnt * PMD(j + 1, (dp[num[j]] - dp[num[j + 1]])) % mod;
    }
    long long tmp = PMD(sz, dp[num[sz - 1]]) - PMD(sz - 1, dp[num[sz - 1]]);
    tmp = (tmp + mod) % mod;
    cnt = cnt * tmp % mod;
    ans = (ans + cnt) % mod;
  }
  printf("%I64d\n", ans);
  return 0;
}
