#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
long long a[maxn], b[maxn], tot = 0;
bool vis[maxn];
int main(void) {
  cin.tie(0);
  std::ios::sync_with_stdio(false);
  long long x0, y0, ax, ay, bx, by;
  cin >> x0 >> y0 >> ax >> ay >> bx >> by;
  long long xs, ys, t;
  cin >> xs >> ys >> t;
  tot++;
  a[tot] = x0;
  b[tot] = y0;
  while (tot <= 70) {
    ++tot;
    long long nx = ax * a[tot - 1] + bx;
    long long ny = ay * b[tot - 1] + by;
    a[tot] = nx;
    b[tot] = ny;
    if (nx > xs && ny > ys && abs(nx - xs) + abs(ny - ys) > t) break;
  }
  long long ans = 0;
  for (long long i = 1; i <= tot; i++) {
    long long temp = t;
    long long res = 0;
    if (abs(a[i] - xs) + abs(b[i] - ys) <= temp) {
      res++;
      temp -= (abs(a[i] - xs) + abs(b[i] - ys));
    } else {
      ans = max(ans, res);
      continue;
    }
    for (long long j = i; j >= 1; j--) {
      if (abs(a[j] - a[j - 1]) + abs(b[j] - b[j - 1]) <= temp) {
        res++;
        temp -= (abs(a[j] - a[j - 1]) + abs(b[j] - b[j - 1]));
      } else
        break;
    }
    for (long long j = 1; j <= tot; j++) {
      if (abs(a[j + 1] - a[j]) + abs(b[j + 1] - b[j]) <= temp) {
        temp -= (abs(a[j + 1] - a[j]) + abs(b[j + 1] - b[j]));
        if (j > i) res++;
      } else
        break;
    }
    ans = max(ans, res);
  }
  cout << ans << "\n";
  return 0;
}
