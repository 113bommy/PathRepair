#include <bits/stdc++.h>
using namespace std;
bool chkmin(long long &x, long long y) { return x > y ? x = y, 1 : 0; }
bool chkmax(long long &x, long long y) { return x < y ? x = y, 1 : 0; }
int readint() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
struct node {
  long long x, bel, id;
  bool operator<(const node c) const { return x < c.x; }
} p[400005];
int n, m, lazy;
int mch[400005];
long long s[400005], cnt[5][400005];
queue<int> q1, q2;
int main() {
  m = readint();
  n = readint();
  for (int i = 1; i <= n; i++) p[i].x = readint(), p[i].bel = 1, p[i].id = i;
  for (int i = 1; i <= n; i++)
    p[i + n].x = readint(), p[i + n].bel = -1, p[i + n].id = i;
  sort(p + 1, p + n + n + 1);
  long long ans = 0;
  for (int i = 1; i <= n + n; i++)
    s[i] = s[i - 1] + p[i].bel, cnt[p[i].bel + 1][s[i] + n] += p[i].x;
  for (int i = 1; i <= n + n; i++) {
    if (p[i].bel * s[i] <= 0)
      ans += p[i].x;
    else
      ans -= p[i].x;
  }
  long long res = ans, opt = 0;
  for (int i = 1; i <= n + n - 1; i++) {
    cnt[p[i].bel + 1][s[i] + lazy + n] -= p[i].x;
    if (p[i].bel == 1) {
      lazy--;
      ans +=
          2 * (cnt[p[i].bel + 1][n - lazy] - cnt[-p[i].bel + 1][n - lazy - 1]) +
          m + 2 * p[i].x;
      cnt[p[i].bel + 1][n - lazy] += p[i].x + m;
    } else {
      lazy++;
      ans +=
          2 * (cnt[p[i].bel + 1][n - lazy] - cnt[-p[i].bel + 1][n - lazy + 1]) +
          m + 2 * p[i].x;
      cnt[p[i].bel + 1][n - lazy] += p[i].x + m;
    }
    if (chkmin(res, ans)) opt = i;
  }
  printf("%lld\n", res);
  for (int i = 1; i <= opt; i++) p[i].x += m;
  sort(p + 1, p + n + n + 1);
  for (int i = 1; i <= n + n; i++) {
    if (p[i].bel == 1) {
      if (q2.empty())
        q1.push(i);
      else
        mch[p[i].id] = p[q2.front()].id, q2.pop();
    } else {
      if (q1.empty())
        q2.push(i);
      else
        mch[p[q1.front()].id] = p[i].id, q1.pop();
    }
  }
  for (int i = 1; i <= n; i++) printf("%d ", mch[i]);
  return 0;
}
