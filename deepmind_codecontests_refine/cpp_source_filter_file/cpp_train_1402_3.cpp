#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
const long long N = 1e5 + 7;
int main() {
  long long l, r;
  cin >> l >> r;
  if ((r - l + 1 < 3) || (r - l + 1 == 3 && l % 2 == 1))
    cout << -1;
  else if (l % 2 == 1)
    cout << l << " " << l + 1 << " " << l + 3;
  else
    cout << l << " " << l + 1 << " " << l + 2;
}
