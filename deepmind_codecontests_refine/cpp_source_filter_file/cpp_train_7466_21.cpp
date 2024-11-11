#include <bits/stdc++.h>
using namespace std;
inline int gi() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + ch - 48;
    ch = getchar();
  }
  return x * f;
}
template <typename T>
inline void Max(T &a, T b) {
  if (a < b) a = b;
}
template <typename T>
inline void Min(T &a, T b) {
  if (a > b) a = b;
}
const int N = 2e5 + 7, inf = 0x3f3f3f3f;
int n, L;
long long a[N << 1], b[N << 2];
bool check(int mid) {
  int mx = -inf;
  for (int i = 1, j1 = 1, j2 = 1; i <= 2 * n; ++i) {
    while (j1 <= 3 * n && b[j1] < a[i] - mid) ++j1;
    while (j2 <= 3 * n && b[j2] <= a[i] + mid) ++j2;
    Max(mx, j1 - i);
    if (j2 - i - 1 < mx) return 0;
  }
  return 1;
}
int main() {
  n = gi(), L = gi();
  for (int i = 1; i <= n; ++i) a[i] = gi();
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; ++i) b[i] = gi();
  sort(b + 1, b + 1 + n);
  for (int i = 1; i <= n; ++i) a[i] += L, a[i + n] = a[i] + L;
  for (int i = 1; i <= 3 * n; ++i) b[i + n] = b[i] + L;
  int l = 0, r = L / 2;
  while (l < r) {
    int mid = l + r >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  printf("%d\n", l);
  return 0;
}
