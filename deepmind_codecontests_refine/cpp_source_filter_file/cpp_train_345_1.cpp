#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
struct node {
  int c, f, l, i;
} a[maxn], b[maxn];
bool cmp1(node a, node b) { return a.f < b.f; }
bool cmp2(node a, node b) { return a.c > b.c; }
int main() {
  int n, d, s;
  scanf("%d%d%d", &n, &d, &s);
  int nn = n;
  int m = 0;
  int ss = s;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", &a[i].c, &a[i].f, &a[i].l);
    a[i].i = i;
    b[i] = a[i];
    if (a[i].c != 0 && a[i].l >= d) {
      if (m == 0 || a[m].f > a[i].f) m = i;
    }
  }
  int ansf = 0;
  int ansc = 0;
  if (m != 0 && a[m].f <= s) {
    s = s - a[m].f;
    sort(a + 1, a + 1 + n, cmp2);
    int sumc = a[1].c;
    int sum = 1;
    for (int i = 2; i <= n; i++) {
      sum++;
      sumc = sumc - 1 + a[i].c;
      if (sumc == 0) break;
    }
    int j = 0;
    for (int i = 1; i <= n; i++)
      if (a[i].c == 0 && a[i].l >= d) {
        a[++j] = a[i];
      }
    n = j;
    sort(a + 1, a + 1 + n, cmp1);
    for (int i = 1; i <= n; i++) {
      if (sum == nn) break;
      if (s >= a[i].f) {
        sum++;
        s -= a[i].f;
      } else
        break;
    }
    ansf = ss - s;
    ansc = sum;
  }
  n = nn;
  for (int i = 1; i <= n; i++) a[i] = b[i];
  s = ss;
  int sumc = 0;
  int j = 0;
  for (int i = 1; i <= n; i++)
    if (a[i].c == 0 && a[i].l >= d) {
      a[++j] = a[i];
    }
  n = j;
  sort(a + 1, a + 1 + n, cmp1);
  for (int i = 1; i <= n; i++) {
    if (s >= a[i].f) {
      sumc++;
      s -= a[i].f;
    } else
      break;
  }
  if (ansc < sumc) {
    ansf = ss - s;
    ansc = sumc;
  } else if (ansc == sumc && ansf > ss - s) {
    ansf = ss - s;
    ansc = sumc;
  }
  printf("%d %d\n", ansc, ansf);
  return 0;
}
