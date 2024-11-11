#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long s = 0, w = 1;
  char ch = getchar();
  while (ch < 48 || ch > 57) {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= 48 && ch <= 57)
    s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
  return s * w;
}
const long long N = 2001, P = 1e9 + 7;
struct Point {
  long long x, y, step;
} q[5000005];
long long n, m, Ans, f[3005];
long long dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
long long dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
bool used[4005][4005];
signed main() {
  n = read() % P, m = read();
  for (register long long i = 1; i <= m; ++i) {
    long long x = read() + N, y = read() + N;
    used[x][y] = 1;
  }
  long long l = 1, r = 1;
  q[1] = (Point){N, N, 0};
  used[N][N] = 1;
  if (n <= 500) {
    while (l <= r) {
      Point u = q[l++], v;
      ++Ans;
      if (u.step == n) continue;
      for (register long long i = 0; i <= 7; ++i) {
        v.x = u.x + dx[i], v.y = u.y + dy[i];
        v.step = u.step + 1;
        if (!used[v.x][v.y]) used[v.x][v.y] = 1, q[++r] = v;
      }
    }
    cout << Ans << endl;
    return 0;
  }
  while (l <= r) {
    Point u = q[l++], v;
    ++f[u.step];
    if (u.step == 500) continue;
    for (register long long i = 0; i <= 7; ++i) {
      v.x = u.x + dx[i], v.y = u.y + dy[i];
      v.step = u.step + 1;
      if (!used[v.x][v.y]) used[v.x][v.y] = 1, q[++r] = v;
    }
  }
  long long d = f[500] - f[499];
  long long last = ((n - 500) * d % P + f[500]) % P;
  Ans = (f[500] + last) % P * (n - 500 + 1) % P * (long long)(500000004) % P;
  for (register long long i = 0; i <= 499; ++i) Ans = (Ans + f[i]) % P;
  cout << Ans << endl;
  return 0;
}
