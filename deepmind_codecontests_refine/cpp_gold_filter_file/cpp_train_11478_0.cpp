#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
int n;
long long t[maxn + 5];
int sa, a[maxn + 5];
int tot;
struct Int {
  int l, r, typ;
} b[maxn + 5];
int f[maxn + 5][2], pre[maxn + 5][2];
vector<int> v[maxn + 5][2];
char ans[maxn + 5];
long long S(int tl, int tr) { return 1ll * (tl + tr) * (tr - tl + 1) / 2; }
bool check(long long s, int L, int R) {
  if (s <= 0) return s == 0 && R - L + 1 >= 0;
  if (L > R) return 0;
  int tl = 1, tr = R - L + 1, num;
  while (tl <= tr) {
    num = (tl + tr) >> 1;
    if (S(L, L + num - 1) <= s)
      tl = num + 1;
    else
      tr = num - 1;
  }
  num = tl - 1;
  return S(R - num + 1, R) >= s;
}
void make_v(vector<int> &tv, long long s, int L, int R) {
  if (s == 0) return;
  int tL = n - R + 1;
  int tl = 1, tr = R - L + 1, num;
  while (tl <= tr) {
    num = (tl + tr) >> 1;
    if (S(tL, tL + num - 1) <= s)
      tl = num + 1;
    else
      tr = num - 1;
  }
  num = tl - 1;
  for (int i = R; i >= L && num; i--)
    if (S(n - i + 2, n - i + num) <= s - n + i - 1 &&
        S(n - L - num + 3, n - L + 1) >= s - n + i - 1) {
      num--;
      s -= n - i + 1;
      tv.push_back(i);
    }
}
void update(int i, int j, int tj, int pos) {
  if (f[i][j] != -1 && f[i][j] <= pos) return;
  f[i][j] = pos;
  pre[i][j] = tj;
  v[i][j].clear();
  v[i][j].push_back(pos);
  make_v(v[i][j], t[b[i].r] + j - t[b[i - 1].r] - tj - n + pos - 1,
         f[i - 1][tj] + 1, b[i].l - 1);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &t[i]);
    if (!t[i]) continue;
    a[++sa] = i;
  }
  if (sa == 0) {
    for (int i = 1; i <= n; i++) printf("0");
    printf("\n");
    return 0;
  }
  b[0] = Int{0, 0, 0};
  b[++tot] = Int{a[1], a[1], 0};
  for (int i = 2; i <= sa; i++) {
    if (t[a[i]] == t[b[tot].r])
      b[tot].r = a[i], b[tot].typ = 1;
    else if (t[a[i]] == t[b[tot].r] - 1)
      b[tot].r = a[i], b[tot].typ = 2;
    else
      b[++tot] = Int{a[i], a[i], 0};
  }
  b[tot + 1] = Int{n + 2, n + 2, 0};
  f[0][0] = -1;
  f[0][1] = 0;
  for (int i = 1; i <= tot; i++) {
    f[i][0] = f[i][1] = -1;
    for (int j = 0; j < 2; j++) {
      if (f[i - 1][j] == -1) continue;
      if (b[i].typ == 0 || b[i].typ == 1) {
        long long tt = t[b[i].r] - t[b[i - 1].r] - j;
        int pos;
        for (pos = max(b[i].r + 1ll, n - tt + 1); pos < b[i + 1].l; pos++) {
          if (check(tt - n + pos - 1, n - b[i].l + 2, n - f[i - 1][j])) break;
        }
        if (pos < b[i + 1].l) update(i, 0, j, pos);
      }
      if (b[i].typ == 0 || b[i].typ == 2) {
        long long tt = t[b[i].r] + 1 - t[b[i - 1].r] - j - n + b[i].r - 1;
        if (check(tt, n - b[i].l + 2, n - f[i - 1][j])) update(i, 1, j, b[i].r);
      }
    }
  }
  if (f[tot][0] == -1 && f[tot][1] == -1 && b[tot].typ == 1) {
    for (int j = 0; j < 2; j++) {
      if (f[tot - 1][j] == -1) continue;
      long long tt = t[b[tot].r] - t[b[tot - 1].r] - j;
      int pos;
      for (pos = max(b[tot].l + 0ll, n - tt + 1); pos <= b[tot].r; pos++) {
        if (t[pos] != 0) continue;
        if (check(tt - n + pos - 1, n - b[tot].l + 2, n - f[tot - 1][j])) break;
      }
      if (pos <= b[tot].r) update(tot, 0, j, pos);
    }
  }
  for (int i = 1; i <= n; i++) ans[i] = '0';
  int now = (f[tot][1] != -1);
  for (int i = tot; i; i--) {
    for (int j = 0; j < v[i][now].size(); j++) ans[v[i][now][j]] = '1';
    now = pre[i][now];
  }
  for (int i = 1; i <= n; i++) printf("%c", ans[i]);
  printf("\n");
  return 0;
}
