#include <bits/stdc++.h>
using namespace std;
void getint(int &v) {
  char ch, fu = 0;
  for (ch = '*'; (ch < '0' || ch > '9') && ch != '-'; ch = getchar())
    ;
  if (ch == '-') fu = 1, ch = getchar();
  for (v = 0; ch >= '0' && ch <= '9'; ch = getchar()) v = v * 10 + ch - '0';
  if (fu) v = -v;
}
const int MO = 1e9 + 7;
const long long INF = 1e9 + 10;
int a[200010], n, m, stk[200010], top;
vector<pair<int, int> > q[200010];
long long p2[200010], r[200010], ans[200010], v[200010], V[200010], s[200010],
    P2[200010];
int gm(long long x) {
  if (x > INF) x = INF;
  if (x < -INF) x = -INF;
  return (int)x;
}
long long gt(int x, int y) { return (r[x] - r[y + 1] * P2[y - x + 1]) % MO; }
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) getint(a[i]);
  for (int i = 1; i <= m; ++i) {
    int l, r;
    getint(l), getint(r);
    ans[i] = a[l];
    ++l;
    if (l <= r) q[r].push_back(make_pair(l, i));
  }
  r[n] = a[n] * 2 % MO;
  for (int i = n - 1; i >= 1; --i) r[i] = (r[i + 1] * 2 + a[i] * 2) % MO;
  stk[top = 1] = 1;
  v[1] = gm(a[1] * 2);
  V[1] = a[1] * 2 % MO;
  s[1] = V[1];
  p2[0] = 1;
  for (int i = 1; i <= n; ++i) p2[i] = gm(p2[i - 1] * 2);
  P2[0] = 1;
  for (int i = 1; i <= n; ++i) P2[i] = P2[i - 1] * 2 % MO;
  for (int i = 2; i <= n; ++i) {
    stk[++top] = i;
    v[top] = gm(a[i] * 2);
    V[top] = a[i] * 2 % MO;
    s[top] = (s[top - 1] + V[top]) % MO;
    while (top > 1 && v[top] >= 0) {
      v[top - 1] =
          gm((long long)v[top] * p2[stk[top - 1] - stk[top - 2]] + v[top - 1]);
      V[top - 1] =
          ((long long)V[top] * P2[stk[top - 1] - stk[top - 2]] + V[top - 1]) %
          MO;
      stk[--top] = i;
      s[top] = (s[top - 1] + V[top]) % MO;
    }
    for (int j = 0; j < q[i].size(); ++j) {
      int x = q[i][j].first, id = q[i][j].second;
      int w = lower_bound(stk + 1, stk + top + 1, x) - stk;
      (ans[id] += s[top] - s[w] + gt(x, stk[w])) %= MO;
    }
  }
  for (int i = 1; i <= m; ++i) printf("%lld\n", (ans[i] + MO) % MO);
  return 0;
}
