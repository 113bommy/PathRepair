#include <bits/stdc++.h>
template <class T>
inline void read(T &res) {
  char ch;
  while (ch = getchar(), !isdigit(ch))
    ;
  res = ch ^ 48;
  while (ch = getchar(), isdigit(ch)) res = res * 10 + ch - 48;
}
template <class T>
inline void put(T x) {
  if (x > 9) put(x / 10);
  putchar(x % 10 + 48);
}
const int N = 1e6 + 5;
int a[N], vis[N], nxt[N], pre[N], suf[N];
int n, m, now = 1;
inline void Fail() {
  puts("no");
  exit(0);
}
inline int Get() {
  while (vis[now]) ++now;
  if (now > n) Fail();
  vis[now] = 1;
  return now;
}
inline void Delete(int l, int r) {
  int tl = pre[l], tr = suf[r];
  suf[tl] = tr, pre[tr] = tl;
}
inline void Merge(int l, int r, int &x) {
  while (x > l && suf[suf[x]] && suf[suf[x]] <= r && !a[x] && a[suf[x]] &&
         a[suf[suf[x]]]) {
    a[x] = a[suf[suf[x]]];
    Delete(suf[x], suf[suf[x]]);
    x = pre[x] > l ? pre[pre[x]] : pre[x];
  }
  while (x > l && suf[suf[x]] && suf[suf[x]] <= r && a[x] && a[suf[x]] &&
         !a[suf[suf[x]]]) {
    a[suf[suf[x]]] = a[x];
    Delete(suf[x], suf[suf[x]]);
    x = pre[x] > l ? pre[pre[x]] : pre[x];
  }
}
inline void solve(int l, int r) {
  if (r - l & 1) Fail();
  for (int i = l; i <= r; i = suf[i])
    while (nxt[i]) {
      if (nxt[i] > r) Fail();
      solve(suf[i], pre[nxt[i]]);
      Delete(suf[i], nxt[i]);
      nxt[i] = nxt[nxt[i]];
    }
  int num1 = 0, num2 = 0, rt = a[pre[l]];
  for (int i = l; i <= r; i = suf[i]) num1 += a[i] > 0, ++num2;
  num2 = (num2 >> 1) + 1;
  if (num1 > num2) Fail();
  num2 -= num1;
  for (int i = l; num2 && i <= r; i = suf[i])
    if (!a[i]) a[i] = Get(), --num2;
  if (!a[l]) {
    for (int i = suf[l]; i <= r; i = suf[i]) Merge(l, r, i);
    Merge(l - 1, r, l);
  } else {
    for (int i = l; i <= r; i = suf[i]) Merge(l - 1, r, i);
  }
  for (int i = l; i <= r; i = suf[i])
    if (!a[i]) a[i] = rt;
}
int main() {
  read(n);
  if (n == 1) return puts("yes\n1"), 0;
  m = (n << 1) - 1;
  for (int i = 1; i <= m; ++i) read(a[i]);
  for (int i = 2; i <= m; ++i)
    if (a[i] && a[i - 1] && a[i] == a[i - 1]) Fail();
  if (a[1] && a[m] && a[1] != a[m]) Fail();
  a[1] = a[m] = a[1] | a[m];
  for (int i = 0; i <= m + 1; ++i) pre[i] = i - 1, suf[i] = i + 1;
  pre[0] = 0;
  for (int i = m; i >= 1; --i)
    if (a[i]) {
      nxt[i] = vis[a[i]];
      vis[a[i]] = i;
    }
  solve(1, m);
  puts("yes");
  for (int i = 1; i <= m; ++i) put(a[i]), putchar(' ');
  return 0;
}
