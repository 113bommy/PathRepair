#include <bits/stdc++.h>
using namespace std;
const int N = 100005, T = 300, M = N / T + 10;
int bo[N], L[M], R[M], n, top;
struct line {
  long long k, b;
} a[N];
long long ans;
bool vis[N];
template <typename T>
void In(T& a) {
  a = 0;
  char c = getchar();
  int f = 1;
  for (; c < 48 || c > 57; c = getchar())
    if (c == '-') f = -1;
  for (; c > 47 && c < 58; c = getchar()) a = (a << 1) + (a << 3) + c - 48;
  a = a * f;
}
bool cmp(int x, int y) { return a[x].k < a[y].k; }
struct block {
  int id[T + 5], s[T + 5], mv, n, mi, top;
  long long lz, mx;
  void pr() {
    printf("n:%d mx:%lld mi:%d lz:%lld mv:%d\n", n, mx, mi, lz, mv);
    for (int i = (1), e_ = (n); i <= e_; i++)
      printf("%d(%lld*x+%lld) ", id[i], a[id[i]].k, a[id[i]].b);
    puts("id");
    for (int i = (1), e_ = (top); i <= e_; i++)
      printf("%d(%lld*x+%lld) ", s[i], a[s[i]].k, a[s[i]].b);
    puts("s");
  }
  void init() {
    for (int i = (1), e_ = (n); i <= e_; i++)
      a[id[i]].b += a[id[i]].k * mv + lz;
    mv = lz = top = 0;
    for (int i = (1), e_ = (n); i <= e_; i++)
      if (!vis[id[i]]) {
        if (top && a[s[top]].k == a[id[i]].k) {
          if (a[s[top]].b >= a[id[i]].b)
            continue;
          else
            top--;
        }
        while (top > 1 && ((a[id[i]].b - a[s[top - 1]].b) * 1.0 /
                           (a[s[top - 1]].k - a[id[i]].k)) <=
                              ((a[s[top]].b - a[s[top - 1]].b) * 1.0 /
                               (a[s[top - 1]].k - a[s[top]].k)))
          top--;
        if (top &&
            ((a[id[i]].b - a[s[top]].b) * 1.0 / (a[s[top]].k - a[id[i]].k)) < 0)
          top--;
        s[++top] = id[i];
      }
    for (mi = 1; mi < top && a[s[mi + 1]].b > a[s[mi]].b; mi++)
      ;
    mx = a[s[mi]].b;
  }
  void move() {
    mv++;
    for (; mi < top &&
           a[s[mi + 1]].k * mv + a[s[mi + 1]].b > a[s[mi]].k * mv + a[s[mi]].b;
         mi++)
      ;
    mx = a[s[mi]].k * mv + a[s[mi]].b + lz;
  }
} B[M];
int main() {
  int pos, X;
  long long now, tot = 0;
  In(n);
  for (int i = (1), e_ = (n); i <= e_; i++) {
    In(a[i].k), a[i].b = a[i].k;
    bo[i] = (i - 1) / T + 1;
    if (bo[i] != bo[i - 1]) R[bo[i - 1]] = i - 1, L[bo[i]] = i;
  }
  R[top = bo[n]] = n;
  for (int i = (1), e_ = (top); i <= e_; i++) {
    for (int j = (L[i]), e_ = (R[i]); j <= e_; j++) B[i].id[++B[i].n] = j;
    sort(B[i].id + 1, B[i].id + 1 + B[i].n, cmp);
    B[i].init();
  }
  for (int i = (1), e_ = (n); i <= e_; i++) {
    now = -1e18, pos = 0;
    for (int j = (1), e_ = (top); j <= e_; j++) {
      if (B[j].mx > now) now = B[j].mx, pos = B[j].s[B[j].mi];
    }
    tot += now;
    vis[pos] = true;
    if (ans < tot) ans = tot;
    X = bo[pos];
    for (int j = (1), e_ = (X - 1); j <= e_; j++)
      B[j].lz += a[pos].k, B[j].mx += a[pos].k;
    for (int j = (X + 1), e_ = (top); j <= e_; j++) B[j].move();
    for (int j = (L[X]), e_ = (pos - 1); j <= e_; j++) a[j].b += a[pos].k;
    for (int j = (pos + 1), e_ = (R[X]); j <= e_; j++) a[j].b += a[j].k;
    a[pos].b = -1e18;
    B[X].init();
  }
  printf("%lld", ans);
  return 0;
}
