#include <bits/stdc++.h>
using namespace std;
int get() {
  char ch;
  while (ch = getchar(), (ch < '0' || ch > '9') && ch != '-')
    ;
  if (ch == '-') {
    int s = 0;
    while (ch = getchar(), ch >= '0' && ch <= '9') s = s * 10 + ch - '0';
    return -s;
  }
  int s = ch - '0';
  while (ch = getchar(), ch >= '0' && ch <= '9') s = s * 10 + ch - '0';
  return s;
}
const int N = 25;
const int L = (1 << 22) + 5;
const long long INF = 1e18;
long long f[L];
struct pass {
  int tim, x;
  pass(const int Tim = 0, const int X = 0) {
    tim = Tim;
    x = X;
  }
} lst[L];
int n, P;
struct Trip {
  int s, len, t;
} a[N], tmp[N];
int cnt[L];
bool cmp(Trip a, Trip b) { return a.s < b.s; }
bool cmp0(int x, int y) { return a[x].s < a[y].s; }
bool cmp1(int x, int y) { return a[x].t < a[y].t; }
int num[N];
int key[N], k;
int st[N];
int per[N];
int ans[N][2];
int nxt[N];
int main() {
  n = get();
  P = get();
  for (int i = 1; i <= n; i++) {
    a[i].s = get();
    a[i].len = get();
    a[i].t = get();
    tmp[i] = a[i];
    per[i] = i;
  }
  sort(per + 1, per + 1 + n, cmp0);
  for (int i = 1; i <= n; i++) a[i] = tmp[per[i]];
  for (int i = 1; i <= n - 1; i++)
    if (a[i].s + a[i].len - 1 >= a[i + 1].s) return printf("NO\n"), 0;
  for (int i = 1; i <= n; i++) num[i] = i;
  sort(num + 1, num + 1 + n, cmp1);
  for (int i = 0; i <= (1 << n) - 1; i++) f[i] = INF;
  f[0] = 0;
  for (int i = 1; i <= (1 << n) - 1; i++) cnt[i] = cnt[i - (i & -i)] + 1;
  for (int i = 0; i <= (1 << n) - 1; i++)
    if (f[i] < INF) {
      k = 0;
      for (int x = 1; x <= n; x++)
        if (((1 << (num[x] - 1)) & i) == 0) key[++k] = num[x];
      for (int x = n; x >= 1; x--) {
        if ((i & (1 << (x - 1))) > 0)
          nxt[x] = x;
        else
          nxt[x] = nxt[x + 1];
      }
      for (int x = 1; x <= n; x++)
        if (f[i] > a[x].s && f[i] < a[x].s + a[x].len - 1) {
          f[i] = a[x].s + a[x].len - 1;
          break;
        }
      int w = 1;
      for (int x = 1; x <= n; x++)
        if (a[x].s > f[i]) {
          long long st = f[i] + 1;
          if (st < a[x].s)
            while (w <= k && (!nxt[x] || st + a[key[w]].t < a[nxt[x]].s)) {
              if (st + a[key[w]].t < a[key[w]].s) {
                if (st + a[key[w]].t - 1 < f[i | (1 << (key[w] - 1))]) {
                  f[i | (1 << (key[w] - 1))] = st + a[key[w]].t - 1;
                  lst[i | (1 << (key[w] - 1))] = pass(st, key[w]);
                }
              }
              w++;
            }
          f[i] = a[x].s + a[x].len - 1;
        }
    }
  if (P == 1) {
    if (f[(1 << n) - 1] == INF) return printf("NO\n"), 0;
    printf("YES\n");
    for (int now = (1 << n) - 1; now; now = now ^ (1 << (lst[now].x - 1)))
      st[lst[now].x] = lst[now].tim;
    for (int i = 1; i <= n; i++) ans[i][0] = 1;
    for (int i = 1; i <= n; i++) ans[per[i]][1] = st[i];
  } else {
    bool pd = 0;
    for (int i = 0; i <= (1 << n) - 1; i++)
      if (f[i] < INF && f[((1 << n) - 1) ^ i] < INF) {
        pd = 1;
        for (int now = i; now; now = now ^ (1 << (lst[now].x - 1))) {
          ans[per[lst[now].x]][1] = lst[now].tim;
          ans[per[lst[now].x]][0] = 1;
        }
        for (int now = ((1 << n) - 1) ^ i; now;
             now = now ^ (1 << (lst[now].x - 1))) {
          ans[per[lst[now].x]][1] = lst[now].tim;
          ans[per[lst[now].x]][0] = 2;
        }
        break;
      }
    if (!pd) return printf("NO\n"), 0;
    printf("YES\n");
  }
  for (int i = 1; i <= n; i++) printf("%d %d\n", ans[i][0], ans[i][1]);
  return 0;
}
