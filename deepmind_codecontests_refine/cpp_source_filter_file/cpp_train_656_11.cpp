#include <bits/stdc++.h>
using namespace std;
int n, i, ans = 0, x;
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> x;
    ans += x * x;
  }
  cout << ans;
  return 0;
}
