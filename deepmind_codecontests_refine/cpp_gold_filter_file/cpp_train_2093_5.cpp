#include <bits/stdc++.h>
using namespace std;
long long int n, m, t, i, j, k, c, x, y, z;
string s, r, p, q;
map<string, long long int> mp;
int main() {
  cin >> n >> s;
  for (i = 0; i <= 9 * n; i++) {
    c = 0;
    x = 0;
    for (j = 0; j < n; j++) {
      x = x + s[j] - 48;
      if (x == i) {
        c++;
        x = 0;
      }
    }
    if (x == 0 && c > 1) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}
