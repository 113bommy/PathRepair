#include <bits/stdc++.h>
const int maxN = 1e5 + 5;
const long double PI = atan(1.0) * 4;
using namespace std;
static int n, d, x[111], ans, f, k;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> d;
  for (int i = 1; i <= n; i++) cin >> x[i];
  sort(x + 1, x + n + 1);
  k = -1;
  for (int i = 1; i <= n; i++) {
    f = lower_bound(x + 1, x + n + 1, x[i] + d + 1) - 1 - x;
    k = max(k, f - i + 1);
  }
  cout << n - k;
}
