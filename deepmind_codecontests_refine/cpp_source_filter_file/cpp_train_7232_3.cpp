#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const int MOD = 1000000009;
char s[N];
int sum[N];
long long inverse(long long a) {
  int b = MOD - 2;
  long long ans = 1;
  while (b != 0) {
    if (b % 2 == 1) {
      ans = (ans * a) % MOD;
    }
    a = a * a % MOD;
    b /= 2;
  }
  return ans;
}
int main(void) {
  int n, k;
  scanf("%d %d", &n, &k);
  scanf("%s", s);
  for (int i = 1; i <= n; ++i) {
    sum[i] = sum[i - 1] + s[i - 1] - '0';
  }
  long long ans = 0;
  long long p1 = 1, p2 = 1;
  for (int i = k + 1; i <= n; ++i) {
    long long tmp = p1 * sum[i - 1] + p2 * (s[i - 1] - '0');
    p1 = p1 * (i - 1) % MOD;
    p1 = p1 * inverse(i - k) % MOD;
    p2 = p2 * i % MOD;
    p2 = p2 * inverse(i - k) % MOD;
    ans = ans * 10 + tmp;
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
