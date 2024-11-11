#include <bits/stdc++.h>
using namespace std;
struct Val {
  long long v;
  long long* pos;
  bool operator<(const Val& y) const { return v < y.v; }
} ar[200010], qs[100010];
int n, m, op[50010], tmp, num, sz, s2, nw, f[200010], de[200010], prt[50010];
long long nul, a[50010], b[50010], mp[200010];
char s[10];
vector<int> e[200010], d[200010];
void Ins(const int& x, const int& y, const int& t) {
  long long l = max(mp[x], mp[y] - (1ll << t)),
            r = min(mp[x + 1] - 1, mp[y + 1] - (1ll << t) - 1);
  if (!((l >> t) & 1) || (l >> t) != (r >> t))
    e[x].push_back(y), e[y].push_back(x);
}
int getf(const int& x) { return f[x] == x ? x : f[x] = getf(f[x]); }
void Merge(int x, int y) {
  if ((x = getf(x)) == (y = getf(y))) return;
  f[x] = y;
}
int main() {
  scanf("%d%d", &n, &m);
  ar[++sz] = (Val){0, &nul}, ar[++sz] = (Val){1ll << n, &nul};
  for (int i = 1; i <= m; ++i) {
    scanf("%s%lld%lld", s, &a[i], &b[i]), op[i] = (s[0] == 'b');
    if (op[i])
      ar[++sz] = (Val){a[i], &a[i]}, ar[++sz] = (Val){b[i] + 1, &b[i]};
    else
      qs[++s2] = (Val){a[i], &a[i]}, qs[++s2] = (Val){b[i], &b[i]};
  }
  sort(ar + 1, ar + sz + 1), ar[0].v = -1;
  for (int i = 1, ts = sz; i <= ts; ++i)
    if (ar[i - 1].v + 1 < ar[i].v) {
      for (int j = n - 1; j >= 0; --j)
        if ((ar[i - 1].v >> j) != (ar[i].v >> j)) {
          tmp = j;
          break;
        }
      ar[++sz] = (Val){ar[i].v & ((1ll << n) - (1ll << tmp + 1)), &nul};
    }
  sort(ar + 1, ar + sz + 1);
  for (int i = 1; i <= sz; ++i)
    num += (ar[i].v != ar[i - 1].v), *ar[i].pos = num, mp[num] = ar[i].v;
  sort(qs + 1, qs + s2 + 1), nw = 1;
  for (int i = 1; i <= s2; ++i) {
    while (qs[i].v >= mp[nw + 1]) ++nw;
    *qs[i].pos = nw;
  }
  for (int t = 0; t < n; ++t) {
    nw = 0;
    for (int i = 1; i < num; ++i) {
      nw = max(nw, i + 1);
      while (nw < num && mp[nw + 1] <= mp[i] + (1ll << t)) ++nw;
      while (nw < num && mp[nw + 1] <= mp[i + 1] + (1ll << t)) Ins(i, nw++, t);
      if (nw < num && mp[nw] < mp[i + 1] + (1ll << t)) Ins(i, nw, t);
    }
  }
  for (int i = 1; i <= num; ++i) f[i] = i, de[i] = 1;
  for (int i = 1; i <= m; ++i)
    if (op[i])
      for (int j = a[i]; j < b[i]; ++j) de[j] = 0;
  for (int i = 1; i < num; ++i)
    if (de[i])
      for (int j = 0; j < e[i].size(); ++j)
        if (de[e[i][j]]) Merge(i, e[i][j]);
  sz = 0;
  for (int i = m; i >= 1; --i) {
    if (op[i]) {
      for (int j = a[i]; j < b[i]; ++j) {
        de[j] = 1;
        for (int k = 0; k < e[j].size(); ++k)
          if (de[e[j][k]]) Merge(j, e[j][k]);
      }
    } else
      prt[++sz] = (getf(a[i]) == getf(b[i]));
  }
  for (int i = sz; i >= 1; --i) putchar(prt[i] + '0'), puts("");
  return 0;
}
