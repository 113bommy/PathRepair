#include <bits/stdc++.h>
using namespace std;
int main() {
  int l, a, b, n, i = 0, j;
  string s;
  cin >> l >> a >> b >> s;
  n = s.size();
  int x = n / l, r = n % l;
  if (x < a || (x == b && r) || x > b) {
    cout << "No solution";
  } else {
    while (l--) {
      j = 0;
      while (i < n && j < x + (r != 0)) {
        cout << s[i];
        i++;
        j++;
      }
      r--;
      cout << endl;
    }
  }
  return 0;
}
