#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const double Exp = 1e-7;
const int maxm = 2e6 + 7;
const int maxn = 4e5 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const double pi = 3.1415926535898;
inline long long read() {
  long long a = 0;
  int f = 0;
  char p = getchar();
  while (!((p) >= '0' && (p) <= '9')) {
    f |= p == '-';
    p = getchar();
  }
  while (((p) >= '0' && (p) <= '9')) {
    a = (a << 3) + (a << 1) + (p ^ 48);
    p = getchar();
  }
  return f ? -a : a;
}
inline void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline long long qpow(long long a, long long b) {
  long long ans = 1;
  for (; b; b >>= 1, a = a * a % MOD)
    if (b & 1) ans = ans * a % MOD;
  return ans;
}
map<int, int> mp;
int top = 0, tail = 0;
int n, m, ans = inf, num[maxn], s[maxn], sum[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  cin >> n >> m;
  m *= 8;
  m /= n;
  for (int i = 0; i < n; ++i) cin >> num[i], mp[num[i]]++;
  sort(num, num + n);
  int cnt = unique(num, num + n) - num, tot = qpow(2, m), i = 0;
  for (int i = 1; i <= cnt; ++i) sum[i] = sum[i - 1] + mp[num[i - 1]];
  if (cnt <= tot) return cout << 0 << endl, 0;
  while (i < cnt) {
    s[tail++] = i++;
    if (tail - top == tot) ans = min(ans, n - sum[tail] + sum[top]);
    if (tail - top > tot) top++, ans = min(ans, n - sum[tail] + sum[top]);
  }
  return cout << ans << endl, 0;
}
