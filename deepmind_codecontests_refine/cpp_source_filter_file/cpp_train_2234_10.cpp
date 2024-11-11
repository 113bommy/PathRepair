#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (m > n)
    cout << -1;
  else {
    int ans = n / 2;
    int rem = ans % 2;
    if ((ans + rem) % m == 0)
      cout << ans + rem;
    else
      cout << (ans + rem) + (m - ((ans + rem) % m));
  }
  return 0;
}
