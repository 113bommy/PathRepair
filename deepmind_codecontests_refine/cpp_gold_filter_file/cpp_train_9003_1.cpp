#include <bits/stdc++.h>
using namespace std;
int x, ans = 1;
int main() {
  cin >> x;
  while (x > 1) {
    ans += x % 2;
    x /= 2;
  }
  cout << ans;
  return 0;
}
