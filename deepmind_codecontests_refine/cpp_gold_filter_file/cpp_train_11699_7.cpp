#include <bits/stdc++.h>
using namespace std;
mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template <typename T>
inline void chkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
inline void chkmin(T &x, T y) {
  if (x > y) x = y;
}
inline int read() {
  int x = 0;
  char c = getchar();
  while (c < 48) c = getchar();
  while (c > 47) x = x * 10 + (c ^ 48), c = getchar();
  return x;
}
int n, m, k;
void solve() {
  cin >> n >> m >> k;
  if (k + n - m < 0) {
    puts("0");
    return;
  }
  if (k - m >= 0) {
    puts("1");
    return;
  }
  long double res = 1;
  for (int i = (0), iend = (k); i <= iend; ++i) {
    res *= (long double)(m - i) / (n + i + 1);
  }
  printf("%.10lf", double(1 - res));
}
int main() {
  solve();
  return 0;
}
