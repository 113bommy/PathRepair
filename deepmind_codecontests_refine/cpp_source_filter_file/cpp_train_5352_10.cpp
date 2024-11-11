#include <bits/stdc++.h>
using namespace std;
template <typename T>
void get_int(T &x) {
  char t = getchar();
  bool neg = false;
  x = 0;
  for (; (t > '9' || t < '0') && t != '-'; t = getchar())
    ;
  if (t == '-') neg = true, t = getchar();
  for (; t <= '9' && t >= '0'; t = getchar()) x = x * 10 + t - '0';
  if (neg) x = -x;
}
template <typename T>
void print_int(T x) {
  if (x < 0) putchar('-'), x = -x;
  short a[20] = {}, sz = 0;
  while (x > 0) a[sz++] = x % 10, x /= 10;
  if (sz == 0) putchar('0');
  for (int i = sz - 1; i >= 0; i--) putchar('0' + a[i]);
}
const int inf = 0x3f3f3f3f;
const long long Linf = 1ll << 61;
const double pi = acos(-1.0);
const int magic = 300;
int n, q, a[100111], ans[100111], ord[100111], ql[100111], qr[100111];
int pre[100111], nxt[100111];
int curl, curr, tot, ok, cnt[100111], dif[100111];
bool cmp(int x, int y) {
  return make_pair(ql[x] / magic, qr[x]) < make_pair(ql[y] / magic, qr[y]);
}
void addr() {
  curr++;
  cnt[a[curr]]++;
  if (cnt[a[curr]] == 1) tot++;
  if (cnt[a[curr]] == 1)
    ok++;
  else if (cnt[a[curr]] > 2 && curr - pre[curr] != pre[curr] - pre[pre[curr]]) {
    if (dif[a[curr]] == 0) ok--;
    dif[a[curr]]++;
  }
}
void addl() {
  curl--;
  cnt[a[curl]]++;
  if (cnt[a[curl]] == 1) tot++;
  if (cnt[a[curl]] == 1)
    ok++;
  else if (cnt[a[curl]] > 2 && nxt[curl] - curl != nxt[nxt[curl]] - nxt[curl]) {
    if (dif[a[curr]] == 0) ok--;
    dif[a[curl]]++;
  }
}
void delr() {
  if (cnt[a[curr]] == 1) tot--;
  if (cnt[a[curr]] == 1)
    ok--;
  else if (cnt[a[curr]] > 2 && curr - pre[curr] != pre[curr] - pre[pre[curr]]) {
    dif[a[curr]]--;
    if (dif[a[curr]] == 0) ok++;
  }
  cnt[a[curr]]--;
  curr--;
}
void dell() {
  if (cnt[a[curl]] == 1) tot--;
  if (cnt[a[curl]] == 1)
    ok--;
  else if (cnt[a[curl]] > 2 && nxt[curl] - curl != nxt[nxt[curl]] - nxt[curl]) {
    dif[a[curl]]--;
    if (dif[a[curl]] == 0) ok++;
  }
  cnt[a[curl]]--;
  curl++;
}
int main() {
  get_int(n);
  for (int i = 1; i <= n; i++) {
    get_int(a[i]);
    if (cnt[a[i]]) {
      pre[i] = cnt[a[i]];
      nxt[cnt[a[i]]] = i;
    }
    cnt[a[i]] = i;
  }
  memset(cnt, 0, sizeof(cnt));
  get_int(q);
  for (int i = 1; i <= q; i++) {
    ord[i] = i;
    get_int(ql[i]), get_int(qr[i]);
  }
  sort(ord + 1, ord + q + 1, cmp);
  for (int _ = 1; _ <= q; _++) {
    int i = ord[_];
    while (curr < qr[i]) addr();
    while (curl > ql[i]) addl();
    while (curr > qr[i]) delr();
    while (curl < ql[i]) dell();
    ans[i] = tot + (ok == 0);
  }
  for (int i = 1; i <= q; i++) print_int(ans[i]), puts("");
  return 0;
}
