#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  x *= f;
}
const int maxn = 110;
int n;
int tot, res, ans;
struct bottle {
  int a, b;
  friend bool operator<(bottle a, bottle b) { return a.b > b.b; }
} bt[maxn];
int f[maxn][maxn * maxn], mx;
inline void dp() {
  memset(f, -1, sizeof(f));
  f[0][0] = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = mx; j >= bt[i].b; --j)
      for (int k = 1; k <= res; ++k)
        f[k][j] = max(f[k][j], f[k - 1][j - bt[i].b] + bt[i].a);
}
int main() {
  read(n);
  for (int i = 1; i <= n; ++i) {
    read(bt[i].a);
    tot += bt[i].a;
  }
  for (int i = 1; i <= n; ++i) {
    read(bt[i].b);
    mx += bt[i].b;
  }
  sort(bt + 1, bt + n + 1);
  ans = tot;
  for (int i = 1; i <= n; ++i) {
    if (tot > bt[i].b)
      tot -= bt[i].b;
    else {
      res = i;
      break;
    }
  }
  dp();
  int maxx = 0;
  for (int i = ans; i <= mx; ++i) maxx = max(maxx, f[res][i]);
  cout << res << ' ' << ans - maxx;
  return 0;
}
