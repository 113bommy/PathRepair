#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && (c != '-')) c = getchar();
  if (c == '-') f = -1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
const int N = 410;
int n, m;
pair<int, int> p[N];
pair<long long, long long> f[N][N];
inline pair<int, int> operator-(pair<int, int> a, pair<int, int> b) {
  return make_pair(a.first - b.first, a.second - b.second);
}
inline long long cross(pair<int, int> a, pair<int, int> b) {
  return 1ll * a.first * b.second - 1ll * a.second * b.first;
}
inline long long S(pair<int, int> x, pair<int, int> y, pair<int, int> z) {
  return abs(cross(y - x, z - x));
}
inline bool check(long long x) {
  for (int i = (1); i <= (n); i++)
    for (int j = (i + 2); j <= (i + n - 1); j++) f[i][j] = make_pair(0, 0);
  for (int len = (3); len <= (n); len++) {
    for (int i = (1); i <= (n); i++) {
      int j = i + len - 1;
      for (int k = (i + 1); k <= (j - 1); k++) {
        int a = f[i][k].first + f[k][j].first;
        long long b = f[i][k].second + f[k][j].second + S(p[i], p[k], p[j]);
        if (b >= x) b = 0, ++a;
        if (a > f[i][j].first || (a == f[i][j].first && b > f[i][j].second))
          f[i][j] = make_pair(a, b);
      }
    }
  }
  for (int i = (1); i <= (n); i++)
    if (f[i][i + n - 1].first >= m + 1) return 1;
  return 0;
}
int main() {
  n = read(), m = read();
  for (int i = (1); i <= (n); i++)
    p[i].first = read(), p[i].second = read(), p[i + n] = p[i];
  long long l = 1, r = 8e16, ret = 0;
  while (l <= r) {
    long long mid = l + r >> 1;
    if (check(mid))
      ret = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  printf("%lld\n", ret);
}
