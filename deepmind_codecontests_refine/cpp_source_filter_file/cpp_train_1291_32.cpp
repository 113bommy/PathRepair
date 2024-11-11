#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int h, r;
  cin >> h >> r;
  int res = (h / r) * 2;
  int t = h % r;
  if (t >= sqrt((double)3.0) * r / 2.0)
    res += 3;
  else if (2 * t >= r)
    res += 2;
  else
    res += 1;
  cout << res << endl;
  return 0;
}
