#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long w = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch <= '9' && ch >= '0') {
    w = (w << 3) + (w << 1) + (ch ^ 48);
    ch = getchar();
  }
  return w;
}
long long n, c[100100 << 1], ans, ans2, l[100100], r[100100];
struct QAQ {
  int x, y, id;
} a[100100];
inline bool cmp1(QAQ x, QAQ y) { return x.x < y.x; }
inline bool cmp2(QAQ x, QAQ y) { return x.y > y.y; }
inline int lowbit(int x) { return x & (-x); }
inline void add(int x) {
  for (int i = x; i <= n * 2; i += lowbit(i)) c[i] += 1;
}
inline long long ask(int x) {
  long long res = 0;
  for (int i = x; i >= 1; i -= lowbit(i)) res += c[i];
  return res;
}
int main() {
  n = read();
  ans = n * (n - 1) * (n - 2) / 6;
  for (int i = 1; i <= n; i++) {
    int x = read(), y = read();
    if (x > y) swap(x, y);
    a[i] = (QAQ){x, y, i};
  }
  sort(a + 1, a + n + 1, cmp1);
  for (int i = 1; i <= n; i++) {
    l[a[i].id] += ask(a[i].x) + ask(n * 2) - ask(a[i].y);
    add(a[i].y);
  }
  memset(c, 0, sizeof(c));
  for (int i = n; i >= 1; i--) {
    r[a[i].id] += ask(a[i].y) - ask(a[i].x);
    add(a[i].y);
  }
  memset(c, 0, sizeof(c));
  sort(a + 1, a + n + 1, cmp2);
  for (int i = 1; i <= n; i++) {
    l[a[i].id] += ask(n * 2) - ask(a[i].y);
    add(a[i].x);
  }
  for (int i = 1; i <= n; i++) {
    ans -= l[i] * r[i];
    ans2 += (l[i] + r[i]) * (n - l[i] - r[i] - 1);
  }
  printf("%lld", ans - ans2 / 2);
  return 0;
}
