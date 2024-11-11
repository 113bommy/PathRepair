#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
const int MAXM = 100005;
const double INF = 1e9;
int n, m, k, fa[MAXN];
struct Tedge {
  int x, y, num, f;
  double c;
} e[MAXM];
int get() {
  int f = 0, v = 0;
  char ch;
  while (!isdigit(ch = getchar()))
    if (ch == '-') break;
  if (ch == '-')
    f = 1;
  else
    v = ch - 48;
  while (isdigit(ch = getchar())) v = v * 10 + ch - 48;
  if (f == 1) return -v;
  return v;
}
int getf(int x) {
  if (fa[x] == x) return x;
  return fa[x] = getf(fa[x]);
}
bool cmp(Tedge a, Tedge b) { return a.c < b.c; }
int calc(double x) {
  int res = 0;
  for (int i = 1; i <= m; i++) {
    e[i].f = 0;
    if (e[i].x == 1 || e[i].y == 1) e[i].c += x;
  }
  for (int i = 1; i <= n; i++) swap(e[i], e[rand() % i + 1]);
  sort(e + 1, e + m + 1, cmp);
  for (int i = 1; i <= n; i++) fa[i] = i;
  for (int i = 1, tmp = 0; i <= m && tmp < n - 1; i++) {
    int x = getf(e[i].x), y = getf(e[i].y);
    if (x != y) {
      fa[x] = y;
      if (e[i].x == 1 || e[i].y == 1) res++;
      tmp++;
      e[i].f = 1;
    }
  }
  for (int i = 1; i <= m; i++)
    if (e[i].x == 1 || e[i].y == 1) e[i].c -= x;
  return res;
}
int main() {
  srand(2567);
  n = get(), m = get(), k = get();
  for (int i = 1; i <= m; i++)
    e[i].x = get(), e[i].y = get(), e[i].c = get(), e[i].num = i;
  for (int i = 1; i <= n; i++) fa[i] = i;
  for (int i = 1; i <= m; i++) {
    int x = getf(e[i].x), y = getf(e[i].y);
    if (x != y) fa[x] = y;
  }
  for (int i = 2; i <= n; i++)
    if (getf(i) != getf(1)) {
      printf("-1\n");
      return 0;
    }
  double l = -INF, r = INF;
  if (k > calc(l) || k < calc(r)) {
    printf("-1\n");
    return 0;
  }
  for (;;) {
    double mid = (l + r) / 2;
    int d = calc(mid);
    if (d == k) break;
    if (d < k)
      r = mid;
    else
      l = mid;
  }
  printf("%d\n", n - 1);
  for (int i = 1; i <= m; i++)
    if (e[i].f) printf("%d ", e[i].num);
  printf("\n");
  return 0;
}
