#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, ans, u, v;
  cin >> n >> m;
  if (n > m) swap(n, m);
  if (n == 1)
    ans = m;
  else if (n == 2) {
    ans = (n / 4) * 4;
    v = n % 4;
    if (v == 1)
      ans += 2;
    else if (v)
      ans += 4;
  } else
    ans = (n * m + 1) / 2;
  cout << ans << endl;
  return 0;
}
