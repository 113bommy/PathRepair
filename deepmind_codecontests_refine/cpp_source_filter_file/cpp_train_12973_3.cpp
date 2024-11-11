#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, i = 1, ans;
  cin >> n;
  while (i * i <= n) {
    i++;
  }
  i--;
  ans = 4 * i;
  n %= i * i;
  if (n) {
    ans += 2 * (1 + ((n - 1) / i));
  }
  cout << ans;
  return 0;
}
