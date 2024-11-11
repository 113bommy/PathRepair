#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int l = s.length();
  int x1 = 0, x2 = 0;
  for (long long i = 0; i < l; i++) {
    if (s[i] == '0') {
      x1++;
      cout << "1 " << x1 << endl;
      if (x1 >= 4) x1 = 0;
    } else {
      x2++;
      if (x2 == 1)
        cout << "3 1" << endl;
      else
        cout << "3 3" << endl;
      if (x1 >= 2) x2 = 0;
    }
  }
  return 0;
}
