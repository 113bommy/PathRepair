#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int res = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -f;
    ch = getchar();
  }
  while (isdigit(ch)) {
    res = res * 10 + ch - '0';
    ch = getchar();
  }
  return res * f;
}
namespace qiqi {
const int N = 4e5 + 5;
int n, m, a[N], v[N], c[N], p[N], k;
vector<int> q[N];
void main() {
  n = read();
  for (int i = (1); i <= (n); ++i) a[i] = read();
  sort(a + 1, a + n + 1);
  for (int i = (1); i <= (n); ++i) {
    if (a[i] != a[i - 1]) v[++m] = a[i];
    ++c[m];
  }
  int mx = 0, x, s;
  for (int i = (1); i <= (sqrt(n)); ++i) {
    s = 0;
    for (int j = (1); j <= (m); ++j) s += min(c[j], i);
    if (s - s % i > mx && s >= i * i) {
      mx = s - s % i;
      x = i;
    }
  }
  for (int i = (1); i <= (m); ++i)
    if (x <= c[i])
      for (int j = (1); j <= (x); ++j) p[++k] = v[i];
  for (int i = (1); i <= (m); ++i)
    if (x > c[i])
      for (int j = (1); j <= (c[i]); ++j) p[++k] = v[i];
  k -= k % x;
  printf("%d\n%d %d\n", k, x, s = k / x);
  for (int i = (1); i <= (x); ++i) q[i].reserve(s + 5);
  k = 0;
  for (int i = (0); i <= (s - 1); ++i)
    for (int j = (1); j <= (x); ++j) q[j][(i + j - 1) % s + 1] = p[++k];
  for (int i = (1); i <= (x); ++i) {
    for (int j = (1); j <= (s); ++j) printf("%d ", q[i][j]);
    puts("");
  }
}
}  // namespace qiqi
int main() {
  qiqi::main();
  return 0;
}
