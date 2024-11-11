#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 30;
const long long INF = 1ll << 60;
const double Inf = 1e20;
const double eps = 1e-9;
void gmax(int &a, int b) { a = (a > b ? a : b); }
void gmin(int &a, int b) { a = (a < b ? a : b); }
int n, m, c, x;
int ans[1005];
int main() {
  scanf("%d%d%d", &n, &m, &c);
  int mid = (c + 1) >> 1;
  while (cin >> x) {
    if (x > mid) {
      for (int i = n; i >= 1; --i)
        if (!ans[i] || ans[i] < x) {
          cout << i << endl;
          fflush(stdout);
          ans[i] = x;
          goto whatever;
        }
      cout << 1 << endl;
      ans[1] = x;
      fflush(stdout);
    whatever:;
    } else {
      for (int i = 1; i <= n; ++i)
        if (!ans[i] || ans[i] > x) {
          cout << i << endl;
          fflush(stdout);
          ans[i] = x;
          goto gg;
        }
      cout << n << endl;
      ans[n] = x;
      fflush(stdout);
    gg:;
    }
    for (int i = 1; i <= n; ++i)
      if (!ans[i]) goto loop;
    break;
  loop:;
  }
  return 0;
}
