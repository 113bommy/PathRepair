#include <bits/stdc++.h>
using namespace std;
int n, m;
int k;
bool debug = false;
int x[5005], y[5005];
int main() {
  scanf("%d", &n);
  int a, b, minx = 1e9, miny = 1e9, maxx = -minx, maxy = -miny;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &a, &b);
    x[i] = a + b;
    y[i] = a - b;
    minx = min(minx, x[i]);
    maxx = max(maxx, x[i]);
    miny = min(miny, y[i]);
    maxy = max(maxy, y[i]);
  }
  int tmp;
  a = 0;
  b = 0;
  for (int i = 0; i < n; i++) {
    tmp = min(max(abs(minx - x[i]), abs(maxy - y[i])),
              max(abs(maxx - x[i]), abs(miny - y[i])));
    a = max(a, tmp);
    tmp = min(max(abs(minx - x[i]), abs(miny - y[i])),
              max(abs(maxx - x[i]), abs(maxy - y[i])));
    b = max(b, tmp);
  }
  int ans = min(a, b);
  int mm = 2;
  for (int i = 0; i < n; i++) {
    tmp = max(max(abs(minx - x[i]), abs(maxx - x[i])),
              max(abs(miny - y[i]), abs(maxy - y[i])));
    if (tmp <= ans) mm = mm * 2 % 1000000007;
  }
  if (a == b && minx + ans < maxx && miny + ans < maxy)
    mm = mm * 2 % 1000000007;
  printf("%d\n%d\n", ans, mm);
  return 0;
}
