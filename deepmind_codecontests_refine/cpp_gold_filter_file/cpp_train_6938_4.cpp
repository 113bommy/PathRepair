#include <bits/stdc++.h>
using namespace std;
const int MAXN = int(1e5) + 10;
const int MOD = int(1e9) + 7;
const int oo = INT_MAX;
int t;
long long g(long long n, long long m) { return n * n - (n / m) * (n / m); }
int main() {
  scanf("%d", &t);
  while (t--) {
    int x;
    scanf("%d", &x);
    if (x == 0) {
      puts("1 1");
      continue;
    }
    bool ok = false;
    int ans_n, ans_m;
    for (int a = 1; a * a <= x; ++a) {
      if (x % a == 0) {
        int b = x / a;
        if ((b - a) % 2 == 0) {
          int delta = (b - a) / 2;
          if (delta <= 0) continue;
          int n = a + delta;
          int m = n / delta;
          if (m <= 1 || g(n, m) != x) continue;
          ans_n = n;
          ans_m = m;
          ok = true;
        }
      }
    }
    if (!ok)
      puts("-1");
    else
      printf("%d %d\n", ans_n, ans_m);
  }
  return 0;
}
