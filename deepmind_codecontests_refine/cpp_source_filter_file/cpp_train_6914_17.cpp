#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j;
  int money[302] = {0};
  cin >> n;
  string ans = "";
  for (i = 0; i < n; i++) cin >> money[i];
  for (i = 0; i < n; i++) {
  mark1:
    if (money[i] <= 0 && i < n - 1)
      ans = ans + "R";
    else if (money[i] > 0 && i < n - 1) {
      money[i] -= 1;
      if (money[i + 1] > 0) {
        money[i + 1] -= 1;
        ans = ans + "PRPL";
        goto mark1;
      } else {
        ans = ans + "PRL";
        goto mark1;
      }
    } else if (money[i] > 0 && i == n - 1) {
      money[i] -= 1;
      ans = ans + "PL";
      goto mark1;
    }
  }
  cout << ans;
  return 0;
}
