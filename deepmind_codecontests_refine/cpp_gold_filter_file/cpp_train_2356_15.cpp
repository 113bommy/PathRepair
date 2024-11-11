#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const long long mod = 1e9 + 7;
const long long INF = 1e18 + 1LL;
const int inf = 1e9 + 1e8;
const double PI = acos(-1.0);
const int N = 1e5 + 100;
int n, ans, a[N];
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 2; i < n; ++i) {
    if (a[i] > a[i - 1] && a[i] > a[i + 1]) ans++;
    if (a[i] < a[i - 1] && a[i] < a[i + 1]) ans++;
  }
  cout << ans << ("\n");
  return 0;
}
