#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, mx = 2000000000, mn = -2000000000, a, b;
  scanf("%d", &n);
  int ch = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &a, &b);
    if (b == 1) {
      mn = max(mn, 1900 - ch);
    } else {
      mx = min(mx, 1899 - ch);
    }
    ch += a;
  }
  if (mn >= mx)
    cout << "Impossible";
  else if (mx == 2000000000)
    cout << "Infinity";
  else
    cout << mx + ch;
}
