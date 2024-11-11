#include <bits/stdc++.h>
using namespace std;
int Rank[4000011], sa[4000011];
namespace SA {
int Cnt[4000011], *cnt = Cnt + 11, first[4000011], second[4000011],
                  buf[4000011], v[4000011];
void build(char *s, int n) {
  for (int i = 0; i < n; i++) v[i] = s[i];
  sort(v, v + n);
  int *x = unique(v, v + n);
  memset(Rank, -1, sizeof Rank);
  for (int i = 0; i < n; i++) Rank[i] = lower_bound(v, x, s[i]) - v;
  for (int t = 1; t <= n; t <<= 1) {
    for (int i = 0; i < n; i++) first[i] = Rank[i], second[i] = Rank[i + t];
    fill(cnt, cnt + n, 0);
    for (int i = 0; i < n; i++) cnt[second[i]]++;
    for (int i = 0; i < n; i++) cnt[i] += cnt[i - 1];
    for (int i = 0; i < n; i++) buf[n - 1 - --cnt[second[i]]] = i;
    fill(cnt, cnt + n, 0);
    for (int i = 0; i < n; i++) cnt[first[i]]++;
    for (int i = 0; i < n; i++) cnt[i] += cnt[i - 1];
    for (int j = 0; j < n; j++) sa[--cnt[first[buf[j]]]] = buf[j];
    bool end = 1;
    for (int j = 0, last = -1; j < n; j++) {
      int i = sa[j];
      if (last == -1)
        Rank[i] = 0;
      else if (first[i] == first[last] && second[i] == second[last])
        Rank[i] = Rank[last], end = 0;
      else
        Rank[i] = Rank[last] + 1;
      last = i;
    }
    if (end) break;
  }
}
}  // namespace SA
struct tree {
  int fv[4100001], addv[4100001];
  void build(int *a, int o, int l, int r) {
    if (l == r) {
      fv[o] = a[l];
      return;
    }
    int m = (l + r) / 2;
    build(a, o * 2, l, m);
    build(a, o * 2 + 1, m + 1, r);
    fv[o] = min(fv[o * 2], fv[o * 2 + 1]);
  }
  void pushdown(int o, int l, int r) {
    if (l == r || !addv[o]) return;
    addv[o * 2] += addv[o];
    addv[o * 2 + 1] += addv[o];
    fv[o * 2] += addv[o];
    fv[o * 2 + 1] += addv[o];
    addv[o] = 0;
  }
  void set(int x, int d, int o, int l, int r) {
    if (l == r) {
      fv[o] = d;
      return;
    }
    pushdown(o, l, r);
    int m = (l + r) / 2;
    if (x <= m)
      set(x, d, o * 2, l, m);
    else
      set(x, d, o * 2 + 1, m + 1, r);
    fv[o] = min(fv[o * 2], fv[o * 2 + 1]);
  }
  void add(int x, int y, int d, int o, int l, int r) {
    if (x <= l && r <= y) {
      fv[o] += d;
      addv[o] += d;
      return;
    }
    pushdown(o, l, r);
    int m = (l + r) / 2;
    if (x <= m) add(x, y, d, o * 2, l, m);
    if (y > m) add(x, y, d, o * 2 + 1, m + 1, r);
    fv[o] = min(fv[o * 2], fv[o * 2 + 1]);
  }
  int query(int x, int y, int o, int l, int r) {
    if (x <= l && r <= y) return fv[o];
    int m = (l + r) / 2, ans = 1 << 30;
    if (x <= m) ans = min(ans, query(x, y, o * 2, l, m));
    if (y > m) ans = min(ans, query(x, y, o * 2 + 1, m + 1, r));
    return ans;
  }
} T;
char s[1100001], t[2200001];
int a[1100001], n;
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; i++) t[i - 1] = t[n + i - 1] = s[i];
  bool flag = 1;
  for (int i = 1; i <= n; i++)
    if (s[i] != '(') {
      flag = 0;
      break;
    }
  if (flag) {
    for (int i = 1; i <= n; i++) putchar('(');
    for (int i = 1; i <= n; i++) putchar(')');
    puts("");
    exit(0);
  }
  for (int i = 1; i <= n; i++)
    if (s[i] == '(')
      a[i] = a[i - 1] + 1;
    else
      a[i] = a[i - 1] - 1;
  T.build(a, 1, 1, n);
  SA::build(t, 2 * n);
  int best = -1, val = -n - 1;
  for (int i = 1; i <= n; i++) {
    int cval = min(T.fv[1], 0);
    if (cval > val)
      val = cval, best = i;
    else if (cval == val && Rank[best - 1] > Rank[i - 1])
      best = i;
    T.add(1, n, s[i] == '(' ? -1 : 1, 1, 1, n);
    T.set(i, a[n], 1, 1, n);
  }
  for (int i = 0; i < -val; i++) putchar('(');
  for (int i = best; i <= n; i++) putchar(s[i]);
  for (int i = 1; i < best; i++) putchar(s[i]);
  for (int i = 0; i < -val + a[n]; i++) putchar(')');
  puts("");
}
