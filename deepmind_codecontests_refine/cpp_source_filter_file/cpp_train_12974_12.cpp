#include <bits/stdc++.h>
using namespace std;
;
int main() {
  int n, i, t, sum = 0, m;
  cin >> n >> t;
  for (i = 1; i <= n; i++) {
    cin >> m;
    sum += 86400 - m;
    if (sum > t) {
      cout << i;
      return 0;
    }
  }
}
