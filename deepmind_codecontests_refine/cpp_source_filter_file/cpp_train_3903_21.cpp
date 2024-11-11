#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans = 0;
  cin >> n;
  for (int i = 1; n; n = n / 10) {
    if (n % 10 == 4)
      ans = ans + i;
    else
      ans = ans + (2 * i);
    i = 2 * 1;
  }
  cout << ans << endl;
  return 0;
}
