#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k, r, l, u, d;
    r = l = u = d = 0;
    char s[100005];
    cin >> s;
    n = strlen(s);
    for (int i = 0; i < n; i++) {
      if (s[i] == 'R')
        r++;
      else if (s[i] == 'L')
        l++;
      else if (s[i] == 'U')
        u++;
      else
        d++;
    }
    if ((r == 0 || l == 0) && (u != 0 && d != 0))
      cout << "2" << endl << "UD" << endl;
    else if ((u == 0 || d == 0) && (r != 0 && l != 0))
      cout << "2" << endl << "RL" << endl;
    else if ((u == 0 || d == 0) && (r == 0 || l == 0))
      cout << "0" << endl;
    else {
      m = min(r, l);
      k = min(u, d);
      cout << 2 * (m + k) << endl;
      for (int i = 1; i <= m; i++) cout << "R";
      for (int i = 1; i <= k; i++) cout << "U";
      for (int i = 1; i <= m; i++) cout << "L";
      for (int i = 1; i <= k; i++) cout << "D";
      cout << endl;
    }
  }
  return 0;
}
