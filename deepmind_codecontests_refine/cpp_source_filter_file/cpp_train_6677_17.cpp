#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const long long mod = 1e9 + 7;
const int inf = 1 << 30;
const int maxn = 600500;
const double EPS = 1e-7;
void solve() {
  int q;
  scanf("%d", &q);
  while (q--) {
    long long n;
    scanf("%lld", &n);
    int a, b;
    scanf("%d%d", &a, &b);
    if (b < a) {
      printf("%lld\n", (n / 2LL) * 1LL * b + a * (n % 2));
    } else
      printf("%lld\n", a * 1LL * n);
  }
}
int main() {
  int tc = 1;
  for (int tt = 0; tt < (int)(tc); ++tt) {
    solve();
  }
}
