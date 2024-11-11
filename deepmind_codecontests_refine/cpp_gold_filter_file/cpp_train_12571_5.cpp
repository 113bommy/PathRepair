#include <bits/stdc++.h>
using namespace std;
int n, p[105], c[105], k, s = 0, ans = 0, a[3][20005];
void read(int &x) {
  int f = 1;
  x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  x *= f;
}
inline void park(int i) {
  ans++;
  k--;
  if (i < n)
    a[0][ans] = c[i], a[1][ans] = 1, a[2][ans] = i + 1;
  else
    a[0][ans] = c[i], a[1][ans] = 4, a[2][ans] = 2 * n - i;
  c[i] = 0;
}
inline void move(int i) {
  int o = (i + 1) % (2 * n);
  if (c[o] != 0) return;
  ans++;
  if (o < n)
    a[0][ans] = c[i], a[1][ans] = 2, a[2][ans] = o + 1;
  else
    a[0][ans] = c[i], a[1][ans] = 3, a[2][ans] = 2 * n - o;
  swap(c[i], c[o]);
}
int main() {
  scanf("%d%d", &n, &k);
  for (int q = 0; q < n; q++) read(p[q]);
  for (int q = 0; q < n; q++) read(c[q]);
  for (int q = (2 * n) - 1; q >= n; q--) read(c[q]);
  for (int q = (2 * n) - 1; q >= n; q--) read(p[q]);
  bool flag = true;
  for (int q = 0; q < 2 * n; q++) {
    if (c[q] == 0) flag = false;
    if (c[q] == p[q] && p[q] != 0) {
      flag = false;
      park(q);
    }
  }
  if (flag) {
    printf("-1");
    return 0;
  }
  while (k > 0) {
    for (; c[s] == 0 || c[(s + 1) % (2 * n)] != 0;
         s = (s + 2 * n - 1) % (2 * n))
      ;
    while (c[(s + 1) % (2 * n)] == 0 && k > 0) {
      move(s);
      s = (s + 1) % (2 * n);
      if (c[s] == p[s] && p[s] != 0) {
        park(s);
        break;
      }
    }
  }
  printf("%d\n", ans);
  for (int q = 1; q <= ans; q++)
    printf("%d %d %d\n", a[0][q], a[1][q], a[2][q]);
  return 0;
}
