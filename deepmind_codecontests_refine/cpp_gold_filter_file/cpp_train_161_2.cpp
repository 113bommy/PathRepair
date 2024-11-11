#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, i, j, k, ans;
  vector<int> c = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1, 1, 2, 0, 1, 0, 0};
  cin >> n;
  ans = 0;
  if (n == 0) ans = 1;
  while (n > 0) {
    ans += c[n % 16];
    n /= 16;
  }
  cout << ans << "\n";
  return 0;
}
