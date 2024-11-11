#include <bits/stdc++.h>
using namespace std;
int a, b, c, ans;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> a >> b >> c;
  if (a != b)
    ans = 2 * c + 2 * min(a, b) + 1;
  else
    ans = a + b + 2 * c;
  cout << ans << endl;
  return 0;
}
