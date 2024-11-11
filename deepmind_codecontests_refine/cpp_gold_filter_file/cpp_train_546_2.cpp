#include <bits/stdc++.h>
using namespace std;
int i, j, k, l, n, m;
struct Nod {
  int x, h;
  char s[1005];
} a[100005];
inline int IN() {
  int x = 0, f = 1;
  char ch;
  for (ch = (getchar()); ch > '9' || ch < '0'; ch = (getchar()))
    if (ch == '-') f = -1;
  for (; ch >= '0' && ch <= '9'; ch = (getchar())) (x *= 10) += ch - '0';
  return x * f;
}
inline bool cmp(const Nod &l, const Nod &r) { return l.x < r.x; }
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%s%d", &a[i].s, &a[i].x);
  sort(a + 1, a + n + 1, cmp);
  for (i = 1; i <= n; i++) {
    if (i - a[i].x <= 0) {
      puts("-1");
      return 0;
    }
    a[i].h = i - a[i].x;
    for (j = 1; j < i; j++)
      if (a[j].h >= a[i].h) a[j].h++;
  }
  for (i = 1; i <= n; i++) printf("%s %d\n", a[i].s, a[i].h);
}
