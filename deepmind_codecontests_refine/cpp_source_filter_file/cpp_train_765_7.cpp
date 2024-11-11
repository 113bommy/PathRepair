#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
bool go(string s, string p) {
  int i, j, k, n, m;
  n = s.size();
  m = p.size();
  for (i = 0; i + m <= n; i++) {
    int f = 0;
    for (j = i, k = 0; j < i + m; j++, k++) {
      if (s[j] != p[k]) {
        f = 1;
        break;
      }
    }
    if (f == 0) return true;
  }
  return false;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t, i, j, n, m, l, r;
  cin >> n;
  string x, s[n + 1];
  for (i = 0; i < n; i++) cin >> s[i];
  for (i = 0; i < 26; i++) {
    x = (char)(i + 97);
    int f = 0;
    for (j = 0; j < n; j++) {
      if (go(s[j], x) == true) {
        f = 1;
        break;
      }
    }
    if (f == 0) {
      cout << x << "\n";
      return 0;
    }
  }
  for (i = 0; i < 26; i++) {
    for (j = 0; j < 26; j++) {
      int f = 0;
      x = (char)(i + 97);
      x += (char)(j + 97);
      for (l = 0; l < n; l++) {
        if (go(s[j], x) == true) {
          f = 1;
          break;
        }
      }
      if (f == 0) {
        cout << x << "\n";
        return 0;
      }
    }
  }
  for (i = 0; i < 26; i++) {
    for (j = 0; j < 26; j++) {
      for (r = 0; r < 26; r++) {
        int f = 0;
        x = (char)(i + 97);
        x += (char)(j + 97);
        x += (char)(r + 97);
        for (l = 0; l < n; l++) {
          if (go(s[j], x) == true) {
            f = 1;
            break;
          }
        }
        if (f == 0) {
          cout << x << "\n";
          return 0;
        }
      }
    }
  }
  return 0;
}
