#include <bits/stdc++.h>
using namespace std;
const int mo = 1000000009, mn = 101000;
int n, m, k, Q, i, j, rt;
int lg[mn], h[mn][20];
int l[mn], r[mn], le[mn], ri[mn];
pair<int, int> a[mn], f[mn];
bool cmp(int i, int j) { return a[i].second < a[j].second; }
void RMQ() {
  int i, j;
  for (i = 1; i <= n; ++i) h[i][0] = i;
  for (j = 1; j <= lg[n]; ++j)
    for (i = 1; i <= n - (1 << j) + 1; ++i)
      h[i][j] = max(h[i][j - 1], h[i + (1 << (j - 1))][j - 1], cmp);
}
int ask(int i, int j) {
  if (i > j) return -1;
  int k = lg[j - i + 1];
  return max(h[i][k], h[j - (1 << k) + 1][k], cmp);
}
int build(int x, int y) {
  if (x > y) return 0;
  int rt = ask(x, y);
  le[rt] = build(x, rt - 1);
  ri[rt] = build(rt + 1, y);
  l[rt] = a[x].first, r[rt] = a[y].first;
  int L = le[rt], R = ri[rt];
  if (!L && !R)
    f[rt].first = f[rt].second = 0;
  else if (!L)
    f[rt].first = max(f[R].first, f[R].second + 1), f[rt].second = f[R].first;
  else if (!R)
    f[rt].first = max(f[L].first, f[L].second + 1), f[rt].second = f[L].first;
  else {
    f[rt].second = f[L].first + f[R].first;
    f[rt].first = max(f[rt].second, 1 + max(f[L].first + f[R].second,
                                            f[L].second + f[R].first));
  }
  return rt;
}
pair<int, int> query(int t, int x, int y) {
  if (!t || x > r[t] || y < l[t]) return make_pair(0, -1);
  if (x <= l[t] && y >= r[t]) return f[t];
  if (y < a[t].first) return query(le[t], x, y);
  if (x > a[t].first) return query(ri[t], x, y);
  pair<int, int> res, f1 = query(le[t], x, y), f2 = query(ri[t], x, y);
  res.second = f1.first + f2.first;
  res.first = res.second;
  if (f1.second != -1) res.first = max(res.first, 1 + f1.second + f2.first);
  if (f2.second != -1) res.first = max(res.first, 1 + f1.first + f2.second);
  return res;
}
int main() {
  scanf("%d%d", &n, &k);
  for (i = 1; i <= k; ++i) scanf("%d%d", &a[i].first, &a[i].second);
  int A, B, C, D;
  scanf("%d%d%d%d", &A, &B, &C, &D);
  for (i = k + 1; i <= n; ++i) {
    a[i].first = ((long long)A * a[i - 1].first + B) % mo;
    a[i].second = ((long long)C * a[i - 1].second + D) % mo;
  }
  sort(a + 1, a + 1 + n);
  lg[1] = 0;
  for (i = 2; i <= n; ++i) lg[i] = lg[i >> 1] + 1;
  RMQ();
  rt = build(1, n);
  scanf("%d", &Q);
  while (Q--) {
    scanf("%d%d", &i, &j);
    pair<int, int> res = query(rt, i, j);
    printf("%d\n", res.first);
  }
  return 0;
}
