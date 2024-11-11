#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7fffffff;
int tim = 100;
const double pi = acos(-1.0);
inline int read() {
  int x = 0, f = 1;
  char ch;
  ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = 0;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch & 15);
    ch = getchar();
  }
  if (f)
    return x;
  else
    return -x;
}
const int N = 60;
int n;
struct Point {
  double a, b;
} A[N];
inline bool operator<(const Point &a, const Point &b) { return a.a > b.a; };
double l = 0.0, r = 1e8;
double x, f[N][N][N];
bool used[N][N][N];
double F(int a, int b, int c) {
  if (a == n) return 0;
  if (used[a][b][c]) return f[a][b][c];
  used[a][b][c] = 1;
  double mn = inf;
  if (a < n - 1 && A[a].a == A[a + 1].a) {
    if (b) mn = min(mn, F(a + 1, b - 1, c));
    mn = min(mn, F(a + 1, b, c + 1) + A[a].a - x * A[a].b);
  } else if (A[a].a != A[a + 1].a || a == n - 1) {
    if (b) mn = min(mn, F(a + 1, b + c - 1, 0));
    mn = min(mn, F(a + 1, b + c + 1, 0) + A[a].a - x * A[a].b);
  }
  return f[a][b][c] = mn;
}
bool cheak(double v) {
  x = v;
  memset(f, 0, sizeof(f));
  memset(used, 0, sizeof(used));
  return F(0, 0, 0) <= 0;
}
int main() {
  n = read();
  for (int i = 0; i < n; i++) A[i].a = read();
  for (int i = 0; i < n; i++) A[i].b = read();
  sort(A, A + n);
  while (tim--) {
    double mid = (l + r) / 2.0;
    if (cheak(mid))
      r = mid;
    else
      l = mid;
  }
  int ans = (ceil)(l * 1000);
  cout << ans << endl;
  return 0;
}
