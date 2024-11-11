#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool GetMin(T &a, T b) {
  return ((a <= b) ? false : (a = b, true));
}
template <typename T>
bool GetMax(T &a, T b) {
  return ((a >= b) ? false : (a = b, true));
}
const int N = 2333;
const long double eps = 1e-8;
int n, m;
long double px[N], py[N], tx, ty, ki[N * N];
bool del[N];
bool Wow(long double x) { return x < -eps || x > eps; }
bool Judge(long double *_p) {
  static long double p[N];
  memcpy(p + 1, _p + 1, sizeof(long double) * n);
  sort(p + 1, p + n + 1);
  long double v = p[1] + p[n];
  for (int i = 1; i <= n; ++i)
    if (Wow(p[i] + p[n - i + 1] - v)) return false;
  return true;
}
bool Check(long double ki) {
  static long double p[N];
  for (int i = 1; i <= n; ++i) p[i] = ki * px[i] + py[i];
  return Judge(p);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lf%lf", px + i, py + i);
    tx += px[i];
    ty += py[i];
  }
  tx /= n;
  ty /= n;
  for (int i = 1; i <= n; ++i)
    if (!del[i])
      for (int j = i + 1; j <= n; ++j)
        if (!Wow(2 * tx - px[i] - px[j]) && !Wow(2 * ty - py[i] - py[j])) {
          del[i] = true;
          del[j] = true;
          break;
        }
  int cnt = 0;
  for (int i = 1; i <= n; ++i)
    if (!del[i]) {
      px[++cnt] = px[i];
      py[cnt] = py[i];
    }
  n = cnt;
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j) {
      long double x = py[i] + py[j] - 2 * ty, y = 2 * tx - px[i] - px[j];
      if (Wow(x) && Wow(y)) ki[++m] = x / y;
    }
  if (n <= 2) {
    puts("-1");
    return 0;
  }
  sort(ki + 1, ki + m + 1);
  int ans = Judge(px) + Judge(py);
  ki[m + 1] = 1e100;
  for (int i = 2, cnt = 1; i <= m + 1; ++i) {
    if (Wow(ki[i] - ki[i - 1])) {
      if (cnt >= (n >> 1)) ans += Check(ki[i - 1]);
      cnt = 1;
    } else
      ++cnt;
  }
  printf("%d", ans);
  return 0;
}
