#include <bits/stdc++.h>
using namespace std;
int str[4];
int main() {
  int t;
  bool solve();
  cin >> t;
  while (t--) {
    for (int i = 0; i < 4; i++) cin >> str[i];
    sort(str, str + 2);
    if (solve())
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
bool solve() {
  bool x = false;
  int odd = 0;
  int even = 0;
  for (int i = 0; i < 4; i++) {
    if (str[i] % 2 == 0)
      even++;
    else
      odd++;
  }
  if (even >= 3)
    x = true;
  else if (even != 2 && str[0] != 0)
    x = true;
  return x;
}
