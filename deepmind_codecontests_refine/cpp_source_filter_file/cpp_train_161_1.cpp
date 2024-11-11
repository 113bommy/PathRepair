#include <bits/stdc++.h>
using namespace std;
int a[16] = {1, 0, 0, 0, 0, 0, 1, 0, 2, 1, 1, 2, 0, 1, 0, 0};
int main() {
  ios::sync_with_stdio(0);
  int n, ans = 0;
  cin >> n;
  if (n == 0) ans++;
  while (n) {
    ans += a[n % 16];
    n /= 16;
  }
  cout << ans << endl;
  return 0;
}
