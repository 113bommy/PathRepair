#include <bits/stdc++.h>
using namespace std;
int n, m, total, i, k, mx = -1;
;
int main() {
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    cin >> k;
    if (mx <= k) mx = k;
    total += k;
  }
  if ((total - mx) >= 0)
    cout << "YES";
  else
    cout << "NO";
}
