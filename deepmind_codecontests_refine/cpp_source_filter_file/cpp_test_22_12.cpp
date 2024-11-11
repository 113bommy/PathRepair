#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  bool op = false;
  char c = getchar();
  while (!isdigit(c)) op |= (c == '-'), c = getchar();
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  return op ? -x : x;
}
const int N = 2e5 + 10;
int n, m, B;
int dif[N], d[500][500], lst[N];
struct Node {
  int x, y;
  Node() {}
  Node(int x, int y) : x(x), y(y) {}
} a[N];
void update(int t, int x, int v) {
  int p = a[x].x + a[x].y;
  int l = (t + a[x].x) % p, r = (t - 1) % p;
  if (l <= r)
    for (int i = l; i <= r; i++) d[p][i] += v;
  else {
    for (int i = 0; i <= l; i++) d[p][i] += v;
    for (int i = r; i < p; i++) d[p][i] += v;
  }
}
int main() {
  n = read();
  m = read();
  B = sqrt(m);
  for (int i = 1; i <= n; i++) {
    int x = read(), y = read();
    a[i] = Node(x, y);
  }
  int ans = 0;
  for (int t = 1; t <= m; t++) {
    int op = read(), x = read();
    if (op == 1) {
      if (a[x].x + a[x].y > B) {
        for (int i = t + a[x].x; i <= m; i += a[x].x + a[x].y) {
          dif[i]++;
          if (i + a[x].y <= m) dif[i + a[x].y]--;
        }
      } else
        update(t, x, 1);
      lst[x] = t;
    } else {
      if (a[x].x + a[x].y > B) {
        for (int i = lst[x] + a[x].x; i <= m; i += a[x].x + a[x].y) {
          dif[i]--;
          if (i + a[x].y <= m) dif[i + a[x].y]++;
          if (i < t && i + a[x].y >= t) ans--;
        }
      } else
        update(lst[x], x, -1);
    }
    int res = 0;
    ans += dif[t];
    for (int i = 1; i <= B; i++) res += d[i][t % i];
    printf("%d\n", res + ans);
  }
}
