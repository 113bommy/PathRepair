#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
struct compass {
  long long x, y, id, kind;
} p[maxn * 4];
long long n, q, full, a, b, x, y, c[maxn], d[maxn], ans[maxn], now;
int read() {
  int tot = 0, fh = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') fh = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    tot = tot * 10 + c - '0';
    c = getchar();
  }
  return tot * fh;
}
long long calc(long long x) {
  if (x < 0) return 0;
  return x * (x - 1) / 2;
}
int lowbit(int x) { return x & -x; }
long long sum(int x) {
  long long res = 0;
  for (int i = x; i > 0; i -= lowbit(i)) res += c[i];
  return res;
}
void update(int x, int val) {
  for (int i = x; i <= n; i += lowbit(i)) c[i] += val;
}
bool cmp(compass a, compass b) { return a.x < b.x; }
int main() {
  n = read();
  q = read();
  full = calc(n);
  for (int i = 1; i <= n; i++) d[i] = read();
  for (int i = 1; i <= q; i++) {
    a = read();
    b = read();
    x = read();
    y = read();
    ans[i] = full - calc(a - 1) - calc(b - 1) - calc(n - x) - calc(n - y);
    p[i * 4 - 3].x = a - 1;
    p[i * 4 - 3].y = b - 1;
    p[i * 4 - 3].id = i;
    p[i * 4 - 3].kind = 1;
    p[i * 4 - 2].x = a - 1;
    p[i * 4 - 2].y = y;
    p[i * 4 - 2].id = i;
    p[i * 4 - 2].kind = 2;
    p[i * 4 - 1].x = x;
    p[i * 4 - 1].y = b - 1;
    p[i * 4 - 1].id = i;
    p[i * 4 - 1].kind = 3;
    p[i * 4].x = x;
    p[i * 4].y = y;
    p[i * 4].id = i;
    p[i * 4].kind = 4;
  }
  sort(p + 1, p + q * 4 + 1, cmp);
  now = 1;
  for (int i = 1; i <= n; i++) {
    update(d[i], 1);
    while (p[now].x <= i && now <= n * 4) {
      if (p[now].kind == 1) ans[p[now].id] += calc(sum(p[now].y));
      if (p[now].kind == 2) ans[p[now].id] += calc(p[now].x - sum(p[now].y));
      if (p[now].kind == 3) ans[p[now].id] += calc(p[now].y - sum(p[now].y));
      if (p[now].kind == 4)
        ans[p[now].id] += calc(n - p[now].x - (p[now].y - sum(p[now].y)));
      now++;
    }
  }
  for (int i = 1; i <= q; i++) cout << ans[i] << endl;
  return 0;
}
