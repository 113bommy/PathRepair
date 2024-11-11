#include <bits/stdc++.h>
using namespace std;
int main() {
  int sum, t, m, n;
  cin >> t;
  while (t > 0) {
    int scr, scr1;
    sum = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      cin >> scr;
      if (i == 0) scr1 = scr;
      sum = sum + scr;
    }
    if (sum + scr1 > m) {
      cout << m << "\n";
    } else
      cout << sum << "\n";
    t--;
  }
}
