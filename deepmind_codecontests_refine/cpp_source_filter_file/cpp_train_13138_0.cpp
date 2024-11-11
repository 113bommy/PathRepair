#include <bits/stdc++.h>
using namespace std;
string s;
void comp_z(vector<long> &z) {
  long n = z.size();
  z[0] = n;
  long L = -1, R = -1;
  for (int i = 1; i < n; i++) {
    if (R < i) {
      L = R = i;
      while (R < n && s[R] == s[R - L]) R++;
      z[i] = R - L;
      R--;
    } else {
      long k = i - L;
      if (z[k] < (R - i + 1)) {
        z[i] = z[k];
      } else {
        L = i;
        while (R < n && s[R] == s[R - L]) R++;
        z[i] = R - L;
        R--;
      }
    }
  }
}
int main(void) {
  cin >> s;
  int n = s.length();
  vector<long> z(n, 0);
  comp_z(z);
  long mx = 0, res = 0;
  long i;
  for (i = 1; i < n; i++) {
    if (z[i] == (n - i) && mx >= (n - i)) {
      res = n - i;
      break;
    }
    mx = max(mx, z[i]);
  }
  if (res)
    cout << s.substr(0, res);
  else
    cout << "Just a Legend";
}
