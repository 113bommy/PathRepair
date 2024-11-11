#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1, c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f ^= 1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  return f ? x : -x;
}
struct BIT {
  long long sum[200005];
  void upd(int x, int v) {
    for (; x < 200005; x += x & -x) sum[x] += v;
  }
  long long qry(int x) {
    long long ans = 0;
    for (; x; x -= x & -x) ans += sum[x];
    return ans;
  }
} bit;
int n;
long long s[200005];
int ans[200005];
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) scanf("%lld", s + i);
  for (int i = 1; i <= n; ++i) bit.upd(i, i);
  for (int i = n; i; --i) {
    int lb = 1, rb = n;
    while (lb < rb) {
      int md = (lb + rb + 1) >> 1;
      if (bit.qry(md - 1) <= s[i])
        lb = md;
      else
        rb = md - 1;
    }
    ans[i] = lb;
    bit.upd(ans[i], -ans[i]);
  }
  for (int i = 1; i <= n; ++i) printf("%d%c", ans[i], i == n ? 10 : 32);
  return 0;
}
