#include <bits/stdc++.h>
using namespace std;
const int MAX = 4040;
const int MAXQ = 20020;
struct query {
  int a, q, id;
  friend bool operator<(const query &a, const query &b) { return a.a < b.a; }
};
struct item {
  int c, h, t;
  friend bool operator<(const item &a, const item &b) { return a.t < b.t; }
};
query r[MAXQ];
item a[MAX];
int ans[MAXQ];
int fl[MAX][MAX];
int fr[MAX][MAX];
int n, p;
void solve(int lo, int hi, int loq, int hiq) {
  int mid = (lo + hi) / 2;
  if (lo >= hi || loq >= hiq) return;
  int hiqleft = loq;
  while (hiqleft < hiq && r[hiqleft].a < a[mid].t) hiqleft++;
  int loqright = hiq;
  while (loqright > loq && r[loqright - 1].a >= a[mid].t + p) loqright--;
  solve(mid + 1, hi, loqright, hiq);
  solve(lo, mid, loq, hiqleft);
  for (int i = (mid); i < (hi + 1); ++i)
    for (int j = (0); j < (MAX); ++j) fr[i][j] = 0;
  for (int i = (mid); i < (hi); ++i)
    for (int j = (0); j < (MAX); ++j) {
      fr[i + 1][j] = max(fr[i + 1][j], fr[i][j]);
      if (j + a[i].c < MAX)
        fr[i + 1][j + a[i].c] = max(fr[i + 1][j + a[i].c], fr[i][j] + a[i].h);
    }
  for (int i = (lo - 1); i < (mid); ++i)
    for (int j = (0); j < (MAX); ++j) fl[i][j] = 0;
  for (int i = mid - 1; i >= lo; --i)
    for (int j = (0); j < (MAX); ++j) {
      fl[i - 1][j] = max(fl[i - 1][j], fl[i][j]);
      if (j + a[i].c < MAX)
        fl[i - 1][j + a[i].c] = max(fl[i - 1][j + a[i].c], fl[i][j] + a[i].h);
    }
  for (int i = hiqleft; i < loqright; ++i) {
    int lb = mid, rb = mid;
    while (rb < hi && a[rb].t <= r[i].a && r[i].a <= a[rb].t + p) rb++;
    while (lb >= lo && a[lb].t <= r[i].a && r[i].a <= a[lb].t + p) lb--;
    int id = r[i].id;
    for (int j = (0); j < (r[i].q + 1); ++j)
      ans[id] = max(ans[id], fl[lb][j] + fr[rb][r[i].q - j]);
  }
}
int main(void) {
  scanf("%d %d", &n, &p);
  for (int i = (1); i < (n + 1); ++i)
    scanf("%d %d %d", &a[i].c, &a[i].h, &a[i].t);
  int q;
  scanf("%d", &q);
  for (int i = (0); i < (q); ++i) {
    int a, qq;
    scanf("%d %d", &a, &qq);
    r[i] = {a, qq, i};
  }
  sort(a + 1, a + n + 1);
  sort(r, r + q);
  solve(1, n + 1, 0, q);
  for (int i = (0); i < (q); ++i) printf("%d\n", ans[i]);
  return 0;
}
