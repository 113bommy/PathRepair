#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
using pii = pair<int, int>;
const double EPS = 1e-9;
const double PI = 2 * asin(1);
const int INF = 0x3f3f3f3f;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
int g_n;
void pretreat() {}
bool input() {
  cin >> g_n;
  if (cin.eof()) return false;
  return true;
}
void solve() {
  if (g_n == 5) {
    puts("1 2 3");
    puts("1 3 3");
    puts("2 4 2");
    puts("4 5 1");
    puts("3 4");
    puts("3 5");
  } else {
    int m = g_n / 2;
    for (int i = 1; i <= m; ++i) printf("%d %d %d\n", i, i + m, 1);
    for (int i = 1; i + m < g_n; ++i)
      printf("%d %d %d\n", i + m, i + m + 1, 2 * i - 1);
    for (int i = 1; i < m; ++i) printf("%d %d\n", i, i + 1);
    puts("1 3");
  }
}
int main() {
  pretreat();
  while (input()) {
    solve();
  }
  return 0;
}
