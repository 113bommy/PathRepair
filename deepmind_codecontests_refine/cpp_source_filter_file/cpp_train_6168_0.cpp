#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt, qq;
  cin >> tt;
  for (qq = 1; qq <= tt; qq++) {
    string s, a;
    long long n, i, k, x, y;
    cin >> n >> k;
    cin >> s;
    sort(s.begin(), s.end());
    if (k == 1) {
      cout << s << endl;
      continue;
    }
    if (s[0] != s[k - 1]) {
      cout << s[k - 1] << endl;
      continue;
    }
    a += s[0];
    for (i = k; i < n - 1; i++)
      if (s[i] != s[i + 1]) {
        i = -1;
        break;
      }
    if (i == -1) {
      for (i = k; i < n; i++) a += s[i];
    } else {
      x = n - k;
      x = x + (x - 1);
      x /= 2;
      for (i = 0; i < x; i++) a += s[k];
    }
    cout << a << endl;
  }
}
