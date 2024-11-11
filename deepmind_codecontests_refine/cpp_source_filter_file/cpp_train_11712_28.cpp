#include <bits/stdc++.h>
using namespace std;
const int N = 1003;
int a[N], b[N];
char buf[N];
int n, m;
long long res = 0;
void calc(int q) {
  int s = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == -1) {
      s = 0;
      continue;
    }
    if (i > 0 && a[i] < a[i - 1])
      s = a[i];
    else
      s += a[i];
    if (!q)
      res += 2 * s * (m - a[i] - 1);
    else
      res += 2 * (s - a[i]) * (m - a[i] - 1);
  }
}
void solve() {
  calc(0);
  reverse(a, a + n);
  calc(1);
  for (int i = 0; i < n; ++i)
    if (a[i] != -1) a[i] = m - a[i] - 1;
  calc(0);
  reverse(a, a + n);
  calc(1);
  for (int i = 0; i < n; ++i)
    if (a[i] != -1) a[i] = m - a[i] - 1;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int j = 0; j < m; ++j) b[j] = -1;
  int c = n * m;
  for (int i = 0; i < n; ++i) {
    scanf("%s", buf);
    a[i] = -1;
    for (int j = 0; j < m; ++j)
      if (buf[j] == 'X') {
        a[i] = j;
        b[j] = i;
        --c;
        break;
      }
  }
  for (int i = 0; i < n; ++i)
    res += (long long)m * m * (i * (i + 1) / 2 + (n - i) * (n - i - 1) / 2);
  for (int j = 0; j < m; ++j)
    res += (long long)n * n * (j * (j + 1) / 2 + (m - j) * (m - j - 1) / 2);
  for (int i = 0; i < n; ++i)
    if (a[i] != -1) {
      int j = a[i];
      res -= 2 * m * (i * (i + 1) / 2 + (n - i) * (n - i - 1) / 2);
      res -= 2 * n * (j * (j + 1) / 2 + (m - j) * (m - j - 1) / 2);
      for (int j = 0; j < n; ++j)
        if (a[j] != -1) res -= abs(j - i) + abs(a[j] - a[i]);
    }
  solve();
  for (int i = 0; i < m; ++i) a[i] = b[i];
  swap(n, m);
  solve();
  printf("%lf\n", (double)res / ((long long)c * c));
  return 0;
}
