#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  register long long x = 0, t = 1;
  register char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') t = -1, ch = getchar();
  while (ch <= '9' && ch >= '0') x = x * 10 + ch - 48, ch = getchar();
  return x * t;
}
int n, R;
long long K;
long long c[555555], a[555555];
long long mx, mn;
bool check(long long mid) {
  for (int i = 1; i <= n; ++i) c[i] = 0;
  for (int i = 1; i <= n; ++i)
    c[max(1, i - R)] += a[i], c[min(n + 1, i + R + 1)] -= a[i];
  long long ss = 0, tt = 0;
  for (int i = 1; i <= n; ++i) {
    tt += c[i];
    long long nw = tt;
    if (nw < mid) {
      ss += mid - nw;
      if (ss > K) return false;
      c[i + 1] += mid - nw;
      c[min(n + 1, i + R + 1)] += nw - mid;
    }
  }
  return ss <= K;
}
int main() {
  n = read();
  R = read();
  K = read();
  for (int i = 1; i <= n; ++i) a[i] = read();
  for (int i = 1; i <= n; ++i)
    c[max(1, i - R)] += a[i], c[min(n + 1, i + R + 1)] -= a[i];
  long long tt = 0, ans = 8e18;
  for (int i = 1; i <= n; ++i) {
    tt += c[i];
    ans = min(ans, tt);
  }
  long long l = 0, r = 8e18;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (check(mid))
      ans = max(ans, mid), l = mid + 1;
    else
      r = mid - 1;
  }
  cout << ans << endl;
  return 0;
}
