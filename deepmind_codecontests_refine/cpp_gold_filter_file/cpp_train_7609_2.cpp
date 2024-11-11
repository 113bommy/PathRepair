#include <bits/stdc++.h>
using namespace std;
long long n, m, sum, a[111111], mx, mn = 99999999999;
bool used[111111];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    mx = max(mx, a[i]);
    mn = min(mn, a[i]);
  }
  cout << (mx - mn) - n + 1;
}
