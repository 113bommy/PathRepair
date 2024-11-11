#include <bits/stdc++.h>
using namespace std;
char buf[1 << 21], *p1 = buf, *p2 = buf;
template <class T>
void read(T &x) {
  x = 0;
  int c = getchar();
  int flag = 0;
  while (c < '0' || c > '9') flag |= (c == '-'), c = getchar();
  while (c >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  if (flag) x = -x;
}
template <class T>
T _max(T a, T b) {
  return b < a ? a : b;
}
template <class T>
T _min(T a, T b) {
  return a < b ? a : b;
}
template <class T>
bool checkmax(T &a, T b) {
  return a < b ? a = b, 1 : 0;
}
template <class T>
bool checkmin(T &a, T b) {
  return b < a ? a = b, 1 : 0;
}
const double pi = acos(-1.0);
int n, m;
int x[1005], y[1006];
void init() {
  read(n);
  read(m);
}
void solve() {
  if (n == 3 && m == 3) {
    printf("0 0\n0 1\n1 1\n");
    return;
  }
  if (n == 4 && m == 3) {
    printf("0 0\n3 0\n0 3\n1 1\n");
    return;
  }
  if (n >= 5 && m == 3) {
    printf("-1\n");
    return;
  }
  int c = 1000000;
  for (int i = 1; i <= m; ++i) {
    x[i] = i;
    y[i] = i * i + c;
  }
  for (int i = 1; i <= n - m; ++i) {
    x[i + m] = -i;
    y[i + m] = -i * i - c;
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d %d\n", x[i], y[i]);
  }
}
int main() {
  init();
  solve();
  return 0;
}
