#include <bits/stdc++.h>
using namespace std;
struct point {
  int x, y;
  char s;
} a[10005];
bool operator<(const point &a, const point &b) {
  if (a.y == b.y) return a.x < b.x;
  return a.y > b.y;
}
int n, sum;
int f[1005];
int main() {
  scanf("%d", &n);
  int x = 0, y = 1, m = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &f[i]);
    sum += f[i];
    if (i % 2 == 1) {
      y--;
      for (int j = 0; j < f[i]; j++) {
        x++;
        y++;
        a[m].x = x;
        a[m].y = y;
        a[m].s = '/';
        m++;
      }
    } else {
      y++;
      for (int j = 0; j < f[i]; j++) {
        x++;
        y--;
        a[m].x = x;
        a[m].y = y;
        a[m].s = '\\';
        m++;
      }
    }
  }
  sum = x;
  sort(a, a + m);
  int now = a[0].y;
  x = 1;
  for (int i = 0; i < m; i++)
    if (now == a[i].y) {
      for (int j = x; j < a[i].x; j++) printf(" ");
      printf("%c", a[i].s);
      x = a[i].x + 1;
    } else {
      for (int j = x; j <= sum; j++) printf(" ");
      puts("");
      now = a[i].y;
      for (int j = 1; j < a[i].x; j++) printf(" ");
      printf("%c", a[i].s);
      x = a[i].x + 1;
    }
  for (int i = x; i <= sum; i++) printf(" ");
  puts("");
  return 0;
}
