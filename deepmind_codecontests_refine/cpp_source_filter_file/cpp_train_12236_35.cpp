#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  cin.tie(0);
  int n, ans, len;
  cin >> n >> ans >> len;
  ans += len;
  ans--;
  if (ans < 0) ans += n;
  ans %= n;
  cout << ans + 1;
  return 0;
}
