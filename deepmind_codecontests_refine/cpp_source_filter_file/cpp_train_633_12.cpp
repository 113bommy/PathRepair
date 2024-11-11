#include <bits/stdc++.h>
using namespace std;
int n, ans;
int main() {
  cin >> n;
  for (int i = 2; i <= n; i++) {
    for (int j = 2 * i; j <= n; j += i) ans += j / i * 4;
  }
  cout << ans << endl;
  return 0;
}
