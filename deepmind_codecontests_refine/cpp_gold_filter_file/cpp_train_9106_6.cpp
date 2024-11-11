#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  string a;
  int i, j, k, n;
  while (cin >> s) {
    cin >> k;
    n = s.length();
    if (n == k) {
      cout << "YES" << endl;
      continue;
    }
    if (n % k != 0) {
      cout << "NO" << endl;
      continue;
    }
    n = n / k;
    j = 0;
    for (i = 1; i <= k; i++) {
      string b(&s[(i - 1) * n], &s[i * n]);
      a = b;
      reverse(b.begin(), b.end());
      if (a == b)
        continue;
      else {
        j = 1;
        break;
      }
    }
    if (j == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
