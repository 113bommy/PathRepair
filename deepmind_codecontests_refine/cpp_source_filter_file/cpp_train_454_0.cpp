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
const int N = 100005;
int n, p;
int a[N], f[N];
int sta[N], top = 0;
void init() {
  read(n);
  for (int i = 1; i <= n; ++i) read(a[i]);
  p = 1;
  while (p < n && a[p] < a[p + 1]) ++p;
}
void solve() {
  int ans = 0;
  sta[++top] = p;
  for (int i = p + 1; i <= n; ++i) {
    if (a[sta[top]] > a[i]) {
      sta[++top] = i;
      f[i] = 1;
    } else {
      while (top && a[sta[top]] < a[i]) {
        checkmax(f[i], f[top] + 1);
        --top;
      }
      sta[++top] = i;
      if (top == 1) f[i] = 0;
    }
    checkmax(ans, f[i]);
  }
  printf("%d\n", ans);
}
int main() {
  init();
  solve();
  return 0;
}
