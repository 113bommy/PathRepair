#include <bits/stdc++.h>
using namespace std;
int main() {
  int i = 0, j = 0, m = 0, n = 0, k = 0, p = 0, t = 0, pass = 0;
  string s;
  cin >> s;
  for (i = 0; i <= s.size(); i++) {
    for (j = i + 1; j <= s.size(); j++) {
      int x = 0;
      for (k = i; k <= j; k++) {
        if (s[k] != s[j - (k - i)]) x = 1;
      }
      if (x == 0) pass = max(pass, j - i + 1);
    }
  }
  cout << pass << endl;
}
