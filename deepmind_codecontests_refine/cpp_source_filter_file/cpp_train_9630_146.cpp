#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans = 1, x = 3;
  cin >> n;
  for (int i = 4; i <= n; i++) {
    ans += x;
    x += 2;
  }
  cout << ans;
  return 0;
}
