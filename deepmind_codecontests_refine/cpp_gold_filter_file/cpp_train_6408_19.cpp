#include <bits/stdc++.h>
using namespace std;
namespace Base {
const int inf = 0x3f3f3f3f, INF = 0x7fffffff;
const long long infll = 0x3f3f3f3f3f3f3f3fll, INFll = 0x7fffffffffffffffll;
template <typename T>
void read(T &x) {
  x = 0;
  int fh = 1;
  double num = 1.0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') fh = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  if (ch == '.') {
    ch = getchar();
    while (isdigit(ch)) {
      num /= 10;
      x = x + num * (ch - '0');
      ch = getchar();
    }
  }
  x = x * fh;
}
template <typename T>
void chmax(T &x, T y) {
  x = x < y ? y : x;
}
template <typename T>
void chmin(T &x, T y) {
  x = x > y ? y : x;
}
}  // namespace Base
using namespace Base;
const int N = 500010;
int n, m, a[N], b[N], f[N][2];
bool check(int x) {
  for (int i = 0; i <= m; i++) f[i][0] = f[i][1] = -inf;
  f[0][0] = -x;
  for (int i = 0; i < m; i++) {
    int tmp = b[i + 1] - b[i];
    if (f[i][0] >= 0) chmax(f[i][1], x + 1);
    if (f[i][0] >= -x) chmax(f[i][1], 1);
    if (f[i][0] - tmp >= -x) chmax(f[i + 1][1], x - tmp + 1);
    chmax(f[i + 1][0], f[i][1] - tmp);
  }
  if (f[m][0] >= -x) return true;
  for (int i = 0; i <= m; i++) f[i][0] = f[i][1] = -inf;
  f[0][0] = -x + (b[1] - b[0]);
  for (int i = 0; i < m; i++) {
    int tmp = b[i + 1] - b[i];
    if (f[i][0] >= 0) chmax(f[i][1], x + 1);
    if (f[i][0] >= -x) chmax(f[i][1], 1);
    if (f[i][0] - tmp >= -x) chmax(f[i + 1][1], x - tmp + 1);
    chmax(f[i + 1][0], f[i][1] - tmp);
  }
  if (f[m][0] >= -x + (b[1] - b[0])) return true;
  return false;
}
int main() {
  read(n);
  read(m);
  for (int i = 1; i <= m; i++) read(a[i]);
  for (int i = 1; i <= m; i++) a[m + i] = a[i] + n;
  a[m + m + 1] = a[1] + n + n;
  int mx = 0, mxi;
  for (int i = 1; i <= m; i++)
    if (a[i + 1] - a[i] > mx) {
      mx = a[i + 1] - a[i];
      mxi = i + 1;
    }
  for (int i = 1; i <= m; i++) b[i] = a[mxi + i] - a[mxi];
  int pl = 1, pr = mx - 1, ans = pr;
  while (pl <= pr) {
    int mid = (pl + pr) / 2;
    if (check(mid) == true)
      ans = mid, pr = mid - 1;
    else
      pl = mid + 1;
  }
  printf("%d\n", ans);
  return 0;
}
