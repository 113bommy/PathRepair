#include <bits/stdc++.h>
using namespace std;
int const N = 100 + 20;
int n, a[N], ans;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  if (n % 2 == 0 || n == 1 || n == 2) return cout << "-1\n", 0;
  for (int i = n; i > 1; i--) {
    int y = max(0, a[i]);
    a[i >> 1] -= y;
    a[i ^ 1] -= y;
    a[i] -= y;
    ans += y;
  }
  ans += max(0, a[1]);
  cout << ans << '\n';
}
