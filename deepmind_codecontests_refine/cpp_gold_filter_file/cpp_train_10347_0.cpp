#include <bits/stdc++.h>
using namespace std;
int n, v[2100000];
char a[2100000], b[2100000];
struct nodd {
  int x, y;
} p[2100000], f[2100000];
bool cmp(nodd a, nodd b) { return a.y > b.y; }
void init() {
  cin >> n;
  n <<= 1;
  scanf("%s", a + 1);
  scanf("%s", b + 1);
  for (int i = (1); i <= (n); ++i) {
    p[i].x = f[i].x = i;
    p[i].y = (a[i] == '1') * 2 + (b[i] == '1');
    f[i].y = (b[i] == '1') * 2 + (a[i] == '1');
  }
  sort(p + 1, p + n + 1, cmp);
  sort(f + 1, f + n + 1, cmp);
}
void work() {
  int x1 = 1, x2 = 1, y1, y2;
  for (int i = (1); i <= (n / 2); ++i) {
    while (v[p[x1].x]) x1++;
    v[p[x1].x] = 1;
    y1 = p[x1].y >> 1;
    while (v[f[x2].x]) x2++;
    v[f[x2].x] = 1;
    y2 = f[x2].y >> 1;
    x1++;
    x2++;
    if (y1 > y2) {
      puts("First");
      return;
    }
    if (y1 < y2) {
      puts("Second");
      return;
    }
  }
  puts("Draw");
}
int main() {
  init();
  work();
  return 0;
}
