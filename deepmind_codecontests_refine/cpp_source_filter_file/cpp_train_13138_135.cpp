#include <bits/stdc++.h>
using namespace std;
void build_z(int z[], string s) {
  int L, R, n, k;
  L = R = 0;
  n = (int)(s.size());
  for (int i = 1; i < n; i++) {
    if (R < i) {
      L = R = i;
      while (R < n && s[R - L] == s[R]) {
        R++;
      }
      z[i] = R - L;
      R--;
    } else {
      k = i - L;
      if (k < (R - i + 1)) {
        z[i] = z[k];
      } else {
        L = i;
        while (R < n && s[R - L] == s[R]) {
          R++;
        }
        z[i] = R - L;
        R--;
      }
    }
  }
}
int main() {
  string s;
  int n;
  while (cin >> s) {
    n = (int)(s.size());
    int z[n];
    build_z(z, s);
    int maxz = 0, res = 0;
    for (int i = 1; i < n; i++) {
      if (z[i] == n - i && maxz >= n - i) {
        res = n - i;
        break;
      }
      maxz = max(maxz, z[i]);
    }
    if (res == 0)
      cout << "Just a legend" << endl;
    else
      cout << s.substr(n - res) << endl;
  }
  return 0;
}
