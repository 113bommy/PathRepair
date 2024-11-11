#include <bits/stdc++.h>
using namespace std;
void init() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}
int prevPower(int n) {
  int now = 1;
  while (now * 2 <= n) now *= 2;
  return now;
}
int main() {
  init();
  int n;
  cin >> n;
  int ans;
  if (n % 2 != 0)
    ans = (n - 1) / 2;
  else {
    ans = n - prevPower(n);
    ans /= 2;
  }
  cout << ans << "\n";
}
