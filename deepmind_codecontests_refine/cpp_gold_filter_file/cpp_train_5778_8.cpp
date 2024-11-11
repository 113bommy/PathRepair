#include <bits/stdc++.h>
using namespace std;
int up, ru, rd, dwn, lf, lu;
long long int ans, add;
int main() {
  cin >> up >> ru >> rd >> dwn >> lf >> lu;
  add = up * 2 - 1;
  for (int i = 0; i < lu + lf; i++) {
    if (i < lu)
      add++;
    else if (i > lu)
      add--;
    if (i < ru)
      add++;
    else if (i > ru)
      add--;
    ans += add;
  }
  cout << ans;
}
