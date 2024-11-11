#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, mx = 0, k = 1, t;
  string y, s = "";
  cin >> y;
  s = "A" + y + "A";
  for (i = 0; i < s.size(); i++) {
    if ((s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' ||
         s[i] == 'U' || s[i] == 'Y') &&
        k == 2) {
      mx = max(mx, i - t);
      k--;
    }
    if ((s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' ||
         s[i] == 'U' || s[i] == 'Y') &&
        k == 1) {
      t = i;
      k++;
    }
  }
  cout << mx;
}
