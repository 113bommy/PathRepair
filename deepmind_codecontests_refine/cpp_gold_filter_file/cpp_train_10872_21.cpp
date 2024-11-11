#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T& s) {
  s = 0;
  static char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9')
    s = (s << 3) + (s << 1) + (c ^ 48), c = getchar();
  return;
}
const int N = 103;
int n, m, a[N], b[N];
int main() {
  scanf("%d %d", &n, &m);
  if (n == 1)
    a[1] = 1;
  else if (n == 2)
    a[1] = 3, a[2] = 4;
  else if (n & 1) {
    a[1] = 2;
    for (int i = 2; i < n; ++i) a[i] = 1;
    a[n] = n + 1 >> 1;
  } else {
    for (int i = 1; i < n; ++i) a[i] = 1;
    a[n] = n - 2 >> 1;
  }
  if (m == 1)
    b[1] = 1;
  else if (m == 2)
    b[1] = 3, b[2] = 4;
  else if (m & 1) {
    b[1] = 2;
    for (int i = 2; i < m; ++i) b[i] = 1;
    b[m] = m + 1 >> 1;
  } else {
    for (int i = 1; i < m; ++i) b[i] = 1;
    b[m] = m - 2 >> 1;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < m; ++j) printf("%d ", a[i] * b[j]);
    printf("%d\n", a[i] * b[m]);
  }
  return 0;
}
