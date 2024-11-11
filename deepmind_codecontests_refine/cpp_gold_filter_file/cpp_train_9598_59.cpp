#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, a, b, front, back, ans = 0;
  cin >> n >> a >> b;
  front = 0;
  back = n - 1;
  for (int i = 1; i <= n; i++) {
    if (a <= front and b >= back) ans++;
    front++;
    back--;
  }
  cout << ans << "\n";
  return 0;
}
