#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e15;
const int MOD = 1e9 + 7;
const double EPS = 1e-7;
const double PI = acos(-1.0);
const int N = 3e5 + 5;
long long n, a[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  long long ans = 0, left = 0;
  for (int i = 0; i < n; ++i) {
    if (i) {
      ans += min(a[i] / 2, left);
      long long tmp = left;
      left -= min(a[i] / 2, left);
      a[i] -= min(a[i] / 2 * 2, tmp * 2);
    }
    ans += a[i] / 3;
    a[i] -= a[i] / 3;
    left += a[i];
  }
  cout << ans << '\n';
}
