#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const double pi = acos(-1.0);
const int maxn = 2000006;
const int mod = 1000000007;
void task() {
  int n;
  cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int mn_p = 1, mx_p = 1;
  for (int i = 2; i <= n; i++) {
    if ((a[i] >= a[mx_p] and mx_p < mn_p) or
        (a[i] <= a[mn_p] and mn_p < mx_p) or
        (a[i] > a[mn_p] and a[i] < a[mx_p])) {
      cout << 3 << "\n";
      cout << min(mx_p, mn_p) << ' ' << max(mx_p, mn_p) << ' ' << i << "\n";
      return;
    }
    if (a[i] > a[mx_p]) {
      mx_p = i;
    }
    if (a[i] < a[mn_p]) {
      mn_p = i;
    }
  }
  cout << 0 << "\n";
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  for (int __ = 1; __ <= T; __++) {
    task();
  }
  return 0;
}
