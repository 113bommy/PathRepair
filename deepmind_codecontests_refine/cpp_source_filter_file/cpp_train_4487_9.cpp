#include <bits/stdc++.h>
#pragma GCC optimize("O3")
std::pair<int, int> DR[] = {{-1, 0}, {0, 1},   {1, 0}, {0, -1},
                            {-1, 1}, {-1, -1}, {1, 1}, {1, -1}};
using namespace std;
long long n, a[1 << 17];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cerr.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = 1; i <= 2 * n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + 2 * n);
  long long mn = (a[n] - a[1]) * (a[2 * n] - a[n + 1]);
  for (long long i = 2; i <= n; i++) {
    mn = min(mn, (a[i + n - 1] - a[i]) * (a[n] - a[1]));
  }
  return cout << mn, 0;
}
