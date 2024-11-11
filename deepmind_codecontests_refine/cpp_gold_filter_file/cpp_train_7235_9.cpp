#include <bits/stdc++.h>
using namespace std;
long long n, x, a, ans;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    ans += abs(a - x);
    x = a;
  }
  return cout << ans, 0;
}
