#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 5;
long long n, kai[N], mi[N], ma[N], hu1[N], hu2[N], hu3[N], gong1[N << 3],
    gong2[N << 3], gong3[N << 3];
long long ans;
inline long long read() {
  char c = getchar();
  long long fu = 1, x = 0;
  while (!isdigit(c)) {
    if (c == '-') fu = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 3) + (x << 1) + c - '0';
    c = getchar();
  }
  return fu * x;
}
inline void solve(long long l, long long r) {
  if (l == r) {
    ans++;
    return;
  }
  long long mid = (l + r) >> 1;
  long long d1 = mid + 1, d2 = mid + 1, mi1 = n, ma1 = 1;
  mi[mid] = n;
  ma[mid] = 1;
  for (long long i = mid + 1; i <= r; i++) {
    mi[i] = min(mi[i - 1], kai[i]);
    ma[i] = max(ma[i - 1], kai[i]);
    hu1[i] = mi[i] + i;
    hu2[i] = ma[i] - i;
    hu3[i] = ma[i] - mi[i] - i;
    gong3[hu3[i] + N]++;
  }
  for (long long i = mid; i >= l; i--) {
    mi1 = min(mi1, kai[i]);
    ma1 = max(ma1, kai[i]);
    while (d1 <= r && mi[d1] > mi1) {
      gong1[N + hu1[d1]]--;
      gong2[N + hu2[d1]]++;
      if (d1 == max(d1, d2)) gong3[N + hu3[d1]]--;
      d1++;
    }
    while (d2 <= r && ma[d2] < ma1) {
      gong2[N + hu2[d2]]--;
      gong1[N + hu1[d2]]++;
      if (d2 == max(d1, d2)) gong3[N + hu3[d2]]--;
      d2++;
    }
    if (min(d1, d2) != mid + 1) {
      long long hu = min(d1, d2) - 1;
      long long ga = ma1 - mi1 + i;
      if (ga >= mid && ga <= hu) ans++;
    }
    if (d1 != d2) {
      if (d1 < d2)
        ans += gong1[N + ma1 + i];
      else
        ans += gong2[N + mi1 - i];
    }
    if (max(d1, d2) != r + 1) {
      ans += gong3[N - i];
    }
  }
  for (long long i = mid + 1; i <= r; i++) {
    mi[i] = min(mi[i - 1], kai[i]);
    ma[i] = max(ma[i - 1], kai[i]);
    hu1[i] = mi[i] + i;
    hu2[i] = ma[i] - i;
    hu3[i] = ma[i] - mi[i] - i;
    gong3[hu3[i] + N] = 0;
    gong1[hu1[i] + N] = 0;
    gong2[hu2[i] + N] = 0;
  }
  solve(l, mid);
  solve(mid + 1, r);
}
signed main() {
  n = read();
  for (long long i = 1, x, y; i <= n; i++) {
    x = read();
    y = read();
    kai[x] = y;
  }
  solve(1, n);
  cout << ans;
}
