#include <bits/stdc++.h>
using namespace std;
int main() {
  int a = 51, b = 51, c = 51, d = -1, e = -1, f = 51, g = -1, h = -1;
  int n, m;
  cin >> n >> m;
  char ch[52][51];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> ch[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (ch[i][j] == '*') {
        a = min(i, a);
        b = min(j, b);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = m - 1; j >= 0; j--) {
      if (ch[i][j] == '*') {
        c = min(i, c);
        d = max(d, g);
      }
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < m; j++) {
      if (ch[i][j] == '*') {
        e = max(i, e);
        f = min(j, f);
      }
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
      if (ch[i][j] == '*') {
        g = max(i, g);
        h = max(j, g);
      }
    }
  }
  for (int i = min(a, c); i <= max(e, g); i++) {
    for (int j = min(b, f); j <= max(d, h); j++) {
      cout << ch[i][j];
    }
    cout << endl;
  }
  return 0;
}
