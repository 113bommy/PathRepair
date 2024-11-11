#include <bits/stdc++.h>
using namespace std;
template <typename ______>
void read(______ &__) {
  __ = 0;
  int ___ = 1;
  char ____ = getchar();
  for (; !isdigit(____); ____ = getchar())
    if (____ == '-') ___ = -1;
  for (; isdigit(____); ____ = getchar())
    __ = (__ << 1) + (__ << 3) + ____ - '0';
  __ *= ___;
}
template <typename T>
void write(T a) {
  if (a < 0) {
    a = -a;
    putchar('-');
  }
  if (a > 9) {
    write(a / 10);
  }
  putchar(a % 10 + '0');
}
const int maxn = 3e5 + 100;
int n, m;
int num, block, belong[maxn], ls[maxn], rs[maxn];
int val[maxn];
int c[maxn], maxx[maxn];
int d[1000100];
void update(int x) {
  val[x] = maxx[x] = 0;
  for (int i = ls[x]; i <= rs[x]; i++)
    val[x] += c[i], maxx[x] = max(maxx[x], c[i]);
  return;
}
void build() {
  block = sqrt(n);
  num = n % block ? block + 1 : num;
  for (int i = 1; i <= num; i++) ls[i] = (i - 1) * block + 1, rs[i] = i * block;
  rs[num] = n;
  for (int i = 1; i <= num; i++)
    for (int j = ls[i]; j <= rs[i]; j++)
      belong[j] = i, val[i] += c[j], maxx[i] = max(maxx[i], c[j]);
}
void op1() {
  int l, r;
  read(l);
  read(r);
  if (belong[l] == belong[r]) {
    if (maxx[belong[l]] > 2) {
      for (int i = l; i <= r; i++) c[i] = d[c[i]];
      update(belong[l]);
    }
    return;
  }
  if (maxx[belong[l]] > 2) {
    for (int i = l; i <= rs[belong[l]]; i++) c[i] = d[c[i]];
    update(belong[l]);
  }
  for (int i = belong[l] + 1; i < belong[r]; i++)
    if (maxx[i] > 2) {
      for (int j = ls[i]; j <= rs[i]; j++) c[j] = d[c[j]];
      update(i);
    }
  if (maxx[belong[r]] > 2) {
    for (int i = ls[belong[r]]; i <= r; i++) c[i] = d[c[i]];
    update(belong[r]);
  }
  return;
}
void op2() {
  int l, r;
  read(l);
  read(r);
  long long ans = 0;
  if (belong[l] == belong[r]) {
    for (int i = l; i <= r; i++) ans += c[i];
    write(ans);
    putchar('\n');
    return;
  }
  for (int i = l; i <= rs[belong[l]]; i++) ans += c[i];
  for (int i = belong[l] + 1; i < belong[r]; i++) ans += val[i];
  for (int i = ls[belong[r]]; i <= r; i++) ans += c[i];
  write(ans);
  putchar('\n');
  return;
}
bool vis[1000100];
int pri[1000100], minn[1000100];
void shai(int maxs) {
  int cnt = 0, now;
  d[1] = 1;
  for (int i = 2; i <= maxs; i++) {
    if (!vis[i]) {
      pri[++cnt] = i;
      minn[i] = 1;
      d[i] = 2;
    }
    for (int j = 1; j <= cnt && i * pri[j] <= maxs; j++) {
      now = i * pri[j];
      vis[now] = 1;
      if (i % pri[j] == 0) {
        minn[i * pri[j]] = minn[i] + 1;
        d[now] = d[i] / (minn[i] + 1) * (minn[i] + 2);
        break;
      } else {
        minn[now] = 1;
        d[now] = d[i] * 2;
      }
    }
  }
}
int main() {
  int maxxx = 0;
  int op, l, r, x;
  read(n);
  read(m);
  for (int i = 1; i <= n; i++) {
    read(c[i]);
    maxxx = max(maxxx, c[i]);
  }
  shai(maxxx);
  build();
  while (m--) {
    read(op);
    if (op == 1)
      op1();
    else
      op2();
  }
  return 0;
}
