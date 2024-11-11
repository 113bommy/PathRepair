#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p, k, i;
  cin >> n >> p >> k;
  if ((1 <= p <= n) && (1 <= k <= n)) {
    if ((p - k) > 1) cout << "<< ";
    for (i = p - k; i <= p + k; i++) {
      if (i == p)
        cout << " (" << p << ")";
      else if (i > n)
        break;
      else if (i < 1)
        continue;
      else
        cout << " " << i;
    }
    if (i < n) cout << " >>";
  }
  return (0);
}
