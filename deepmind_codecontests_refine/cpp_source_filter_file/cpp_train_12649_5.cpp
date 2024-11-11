#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e6 + 123;
const long long linf = (long long)1e18 + 123;
const int inf = (int)1e9 + 123;
const double eps = 1e-6;
inline void boost() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
}
int n;
int a[200111], mn = inf;
int main() {
  boost();
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (int i = 1; i + n / 2 <= n; i++) {
    mn = min(mn, a[i + n / 2]);
  }
  cout << mn;
  return 0;
}
