#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, tbreak, tjoy, ttake, mx = -99999999;
  cin >> n >> tbreak;
  while (n--) {
    cin >> tjoy >> ttake;
    if (ttake <= tbreak)
      mx = max(mx, tjoy);
    else
      mx = max(mx, tjoy - (ttake - tbreak));
  }
  cout << mx;
  return 0;
}
