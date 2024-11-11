#include <bits/stdc++.h>
using namespace std;
int k(string s) {
  for (int i = 9; i; i--) {
    bool y = 0;
    for (int j = 0; j < (1 << i); j++) {
      string t;
      for (int l = 0; l < i; l++) {
        if (j & (1 << l))
          t += '1';
        else
          t += '0';
      }
      if (s.find(t) == string::npos) {
        y = 1;
        break;
      }
    }
    if (!y) return i;
  }
  return 0;
}
int main() {
  int n, m, a, b, z[202] = {};
  string s[202] = {};
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> s[i];
  cin >> m;
  for (int i = n + 1; i <= n + m; i++) {
    cin >> a >> b;
    s[i] = s[a] + s[b];
    int L = 510;
    if (s[i].length() > L + L) {
      string t = s[i].substr(0, L) + s[i].substr(s[i].length() - L, L);
      s[i] = t;
    }
    z[i] = max({z[a], z[b], k(s[i])});
    cout << z[i] << '\n';
  }
}
