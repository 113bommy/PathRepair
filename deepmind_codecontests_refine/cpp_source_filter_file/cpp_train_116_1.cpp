#include <bits/stdc++.h>
using namespace std;
int main() {
  long long m, n, t, b, c, d, i, j, k, x, y, z, l, q, r;
  string s;
  while (cin >> k >> s) {
    string s1, s2;
    long long cnt = 0, cn = 1;
    n = s.size();
    for (i = 0; i < n - 1; i++) {
      if (s[i] != s[i + 1] && s[i] > s[i + 1]) {
        m = i;
        break;
      } else
        cn++;
    }
    if (cn == n)
      cnt = 0;
    else
      for (i = m; i < n - 1; i++)
        if (s[i] > s[i + 1]) {
          cnt = 1, x = i + 1;
          break;
        }
    if (cnt == 1) {
      for (i = m; i <= x; i++) s1 += s[i];
      s2 = s1;
      reverse(s2.begin(), s2.end());
    }
    if (s1 != s2 && cnt == 0)
      cout << "YES" << endl << x << " " << x + 1 << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
