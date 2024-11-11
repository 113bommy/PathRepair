#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const double eps = 1e-8;
inline int sgn(const double x) { return (x > eps) - (x < -eps); }
template <class T>
bool get_max(T &a, const T b) {
  return a < b ? a = b, true : false;
}
template <class T>
bool get_min(T &a, const T b) {
  return a > b ? a = b, true : false;
}
int a[110], b[110];
bool u[110];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d%d", &a[i], &b[i]);
  memset(u, false, sizeof(u));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (i != j && a[i] == b[j]) u[j] = true;
  int ans = 0;
  for (int i = 0; i < n; i++)
    if (!u[i]) ans++;
  printf("%d\n", ans);
  return 0;
}
