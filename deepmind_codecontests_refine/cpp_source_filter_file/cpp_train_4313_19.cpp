#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const long long INF = 1e18;
const int N = 250010;
int n, b[N], l[N], r[N], id[N];
long double ans;
int Write[20];
int read() {
  int d = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') d = (d << 3) + (d << 1) + c - 48, c = getchar();
  return d * f;
}
void write(int x) {
  int t = 0;
  if (x < 0) putchar('-'), x = -x;
  for (; x; x /= 10) Write[++t] = x % 10;
  if (!t) putchar('0');
  for (int i = t; i >= 1; i--) putchar((char)(Write[i] + 48));
}
void judge() {
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
}
bool cmp(int x, int y) { return b[x] < b[y]; }
int main() {
  n = read();
  for (int i = 1; i <= n; i++)
    b[i] = read(), l[i] = i - 1, r[i] = i + 1, id[i] = i;
  sort(id + 1, id + 1 + n, cmp);
  for (int pjy = 1; pjy <= n; pjy++) {
    int i = id[pjy], x = i, y = i;
    long double L = 0, R = 0, z = 1;
    for (int j = 1; j <= 100; j++) {
      if (x) {
        L += (x - l[x]) * z;
        x = l[x];
      }
      if (y <= n) {
        R += (r[y] - y) * z;
        y = r[y];
      }
      z /= 2;
    }
    l[r[i]] = l[i];
    r[l[i]] = r[i];
    ans += L * R * b[i] / 2;
  }
  ans = ans / n / n;
  double x = ans;
  printf("%.10lf", x);
  return 0;
}
