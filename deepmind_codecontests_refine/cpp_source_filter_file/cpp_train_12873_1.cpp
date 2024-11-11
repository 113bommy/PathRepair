#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int k, n, s, p, x, ans;
  cin >> k >> n >> s >> p;
  if ((k) % s == 0)
    x = n / s;
  else
    x = n / s + 1;
  int y = x * k;
  if (y % p == 0)
    ans = y / p;
  else
    ans = y / p + 1;
  cout << ans;
  return 0;
}
