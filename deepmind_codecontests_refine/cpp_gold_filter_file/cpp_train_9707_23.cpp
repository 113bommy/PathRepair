#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  if (c == '-') f = -1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return f * x;
}
const int maxn = 3e5 + 7;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int n;
long long k;
int a[maxn], b[maxn], c[maxn];
bool check(long long x) {
  long long cnt = 0;
  for (int i = 1; i <= n; ++i) {
    c[i] = 0;
    long long l = 0, r = a[i];
    while (l < r) {
      long long mid = (l + r + 1) / 2;
      if (a[i] - 3 * mid * mid + 3 * mid - 1 > x)
        l = mid;
      else
        r = mid - 1;
    }
    b[i] = l;
    cnt += l;
    if (l < a[i] && a[i] - 3 * (l + 1) * (l + 1) + 3 * (l + 1) - 1 == x)
      c[i] = 1, cnt++;
  }
  return cnt >= k;
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) a[i] = read();
  long long l = -3e18, r = 1e9;
  while (l < r) {
    long long mid = l + (r - l + 1) / 2;
    if (check(mid))
      l = mid;
    else
      r = mid - 1;
  }
  check(l);
  for (int i = 1; i <= n; ++i) k -= b[i];
  for (int i = 1; i <= n; ++i) {
    if (k && c[i]) k--, b[i]++;
  }
  for (int i = 1; i <= n; ++i) printf("%d%c", b[i], " \n"[i == n]);
}
