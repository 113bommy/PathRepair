#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long sum[1100000];
long long res[1100000];
int lowbit(int x) { return x & (-x); }
long long query(int x) {
  long long ans = 0;
  while (x) {
    (ans += sum[x]) %= mod;
    x -= lowbit(x);
  }
  return ans;
}
void update(int x, long long k) {
  while (x <= 1000000) {
    (sum[x] += k) %= mod;
    x += lowbit(x);
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int t;
    scanf("%d", &t);
    long long tt = (query(t) * t + t) % mod;
    update(t, ((tt - res[t]) % mod + mod) % mod);
    res[t] = tt;
  }
  printf("%I64d\n", query(1000000));
  return 0;
}
