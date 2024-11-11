#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, ans = 1, x = 3;
  cin >> n;
  for (int i = 4; i <= n; i++) {
    ans += x;
    x += 2;
  }
  cout << ans;
  return 0;
}
