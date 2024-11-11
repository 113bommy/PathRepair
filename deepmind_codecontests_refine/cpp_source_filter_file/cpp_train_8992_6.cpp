#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:66777216")
using namespace std;
int a, b, c, d, n, m, k;
int main() {
  scanf("%d", &n);
  int one = 0, two = 0;
  for (int _n((n)-1), i(0); i <= _n; i++) {
    scanf("%d", &a);
    if (a == 1)
      ++one;
    else
      ++two;
  }
  int ans = 1, p = 0;
  for (int _n(one + 1), i(2); i <= _n; i++) {
    int nans = (ans + (long long)(i - 2) * p) % 1000000007;
    p = ans;
    ans = nans;
  }
  for (int _n((two)), i(1); i <= _n; i++) {
    ans = (long long)ans * (one + i) % 1000000007;
  }
  cerr << ans << endl;
}
