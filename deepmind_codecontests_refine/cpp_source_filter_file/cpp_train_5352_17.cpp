#include <bits/stdc++.h>
using namespace std;
const int N(100010);
int m, q, t;
int l[3 * N], r[3 * N], s[3 * N], rr[3 * N], del[3 * N];
int a[N], c[N], ans[N], pre[N], p[N];
bool cmp1(int x, int y) { return a[x] < a[y] || a[x] == a[y] && x < y; }
bool cmp2(int x, int y) { return l[x] < l[y] || l[x] == l[y] && x > y; }
bool cmp3(int x, int y) { return l[x] < l[y] || l[x] == l[y] && x < y; }
int low(int x) { return x & -x; }
void add(int x, int v) {
  for (; x <= m; x += low(x)) c[x] += v;
}
int sum(int x) {
  int ret = 0;
  for (; x; x -= low(x)) ret += c[x];
  return ret;
}
int main() {
  scanf("%d", &m);
  for (int i = int(1); i < int(m + 1); ++i) {
    scanf("%d", &a[i]);
    s[i] = i;
  }
  scanf("%d", &q);
  t = q;
  sort(s + 1, s + m + 1, cmp1);
  for (int i = 1, j = 1; i <= m; i = j) {
    int tt = 0;
    p[tt++] = 0;
    for (; j <= m && a[s[i]] == a[s[j]]; ++j) {
      pre[s[j]] = p[tt - 1];
      p[tt++] = s[j];
    }
    p[tt++] = m + 1;
    for (int x = 1, y = 1; x < tt - 1; ++x) {
      for (; p[x + 1] - p[x] == p[y + 1] - p[y] && y < tt - 2; ++y)
        ;
      l[t] = p[x - 1] + 1;
      r[t] = p[x];
      rr[t] = p[y + 1];
      del[t++] = 1;
      l[t] = p[x] + 1;
      r[t] = p[x];
      rr[t] = p[y + 1];
      del[t++] = -1;
    }
  }
  for (int i = int(0); i < int(q); ++i) scanf("%d%d", &l[i], &r[i]);
  for (int i = int(0); i < int(t); ++i) s[i] = i;
  sort(s, s + t, cmp2);
  int rmax = -1;
  for (int i = int(0); i < int(t); ++i)
    if (s[i] >= q) {
      add(r[s[i]], del[s[i]]);
      add(rr[s[i]] + 1, -del[s[i]]);
    } else if (sum(r[s[i]]) == 0)
      ++ans[s[i]];
  t = q;
  for (int i = int(1); i < int(m + 1); ++i) {
    l[t] = pre[i];
    r[t++] = i;
  }
  for (int i = int(0); i < int(t); ++i) s[i] = i;
  sort(s, s + t, cmp3);
  memset(c, 0, sizeof(c));
  for (int i = int(0); i < int(t); ++i)
    if (s[i] >= q)
      add(r[s[i]], 1);
    else
      ans[s[i]] += sum(r[s[i]]) - sum(l[s[i]] - 1);
  for (int i = int(0); i < int(q); ++i) printf("%d\n", ans[i]);
  return 0;
}
