#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int x, ans = 0;
  for (int i = 0; i < 5; ++i) cin >> x, ans += x;
  if (ans % 5 == 0 && ans)
    cout << ans / 5;
  else
    cout << -1;
  return 0;
}
