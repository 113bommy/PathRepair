#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, h;
  cin >> r >> h;
  int ans = h / r;
  h %= r;
  ans *= 2;
  long double value = r;
  value = sqrt(3) * value / 2;
  if ((long double)h >= value)
    ans += 3;
  else if (2 * h >= r)
    ans += 2;
  else
    ans++;
  cout << ans << endl;
  return 0;
}
