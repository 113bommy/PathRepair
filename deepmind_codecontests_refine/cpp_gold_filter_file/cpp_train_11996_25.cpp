#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
int a[N];
int main() {
  int n, m, inf = 1e8;
  cin >> n >> m;
  int sum = 0;
  for (int i = 0; i < n; i++) sum += i / 2;
  if (sum < m) return cout << -1, 0;
  for (int i = 0; i < n; i++) {
    if (m >= i / 2)
      cout << i + 1 << " ", m -= i / 2;
    else if (m > 0) {
      int res = i + 1, t = i;
      while (t / 2 > m) t--, res++;
      cout << res << " ", m = 0;
    } else
      cout << inf << " ", inf += 2 * N;
  }
}
