#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10, p = 1e9 + 7;
int inc(int x, int y) {
  x += y;
  return x >= p ? x - p : x;
}
int dec(int x, int y) {
  x -= y;
  return x < 0 ? x + p : x;
}
int mul(int x, int y) { return (long long)x * y % p; }
int power(int x, int y) {
  int ans = 1;
  for (; y; y >>= 1, x = mul(x, x))
    if (y & 1) ans = mul(ans, x);
  return ans;
}
int n, k, u[N], prime[N], cnt;
bool isp[N];
void init(int n) {
  u[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!isp[i]) prime[++cnt] = i, u[i] = 1;
    for (int j = 1; j <= cnt && i * prime[j] <= n; j++) {
      int x = i * prime[j];
      isp[x] = 1;
      if (i % prime[j])
        u[x] = -u[i];
      else {
        u[x] = 0;
        break;
      }
    }
  }
  for (int i = 1; i <= n; i++)
    if (u[i] < 0) u[i] = p;
}
int ans[N], pw[N];
int calc(int m) {
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    ans = inc(ans, mul(u[i], power(m / i, n)));
  }
  return ans;
}
int main() {
  cin >> n >> k;
  init(k);
  for (int i = 1; i <= k; i++) pw[i] = power(i, n);
  for (int i = 1; i <= k; i++)
    for (int j = i; j <= k; j += i)
      ans[j] = inc(ans[j], mul(u[i], dec(pw[j / i], pw[j / i - 1])));
  for (int i = 1; i <= k; i++) ans[i] = inc(ans[i], ans[i - 1]);
  long long s = 0;
  for (int i = 1; i <= k; i++) s = ans[i] ^ i;
  cout << s % p << endl;
  return 0;
}
