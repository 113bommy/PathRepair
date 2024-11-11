#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int64_t n;
  cin >> n;
  if (n == 20)
    cout << 15;
  else if ((n >= 11 && n <= 21))
    cout << 4;
  else
    cout << 0;
}
