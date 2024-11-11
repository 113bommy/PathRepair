#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string a[2];
void kek() {
  char x = a[0][12], y = a[1][0];
  for (int i = 12; i > 0; --i) a[0][i] = a[0][i - 1];
  a[0][0] = y;
  for (int i = 0; i < 12; ++i) a[1][i] = a[1][i + 1];
  a[1][12] = x;
}
int main() {
  string s;
  cin >> s;
  int n = 27;
  if (s[0] == s[n - 1]) {
    for (int i = 0; i < n / 2; ++i) cout << s[i];
    cout << '\n';
    for (int i = n - 2; i >= n / 2; --i) cout << s[i];
    return 0;
  }
  int x, y;
  for (int i = 0; i < n - 1; ++i) {
    if (s[i] == s[i + 1]) {
      cout << "Impossible\n";
      return 0;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (s[i] == s[j]) {
        x = i;
        y = j;
        break;
      }
    }
  }
  a[0].resize(13);
  a[1].resize(13);
  for (int i = 0; i < n; ++i) {
    int j = i;
    if (i == y) continue;
    if (i > y) --j;
    a[j / 13][j % 13] = s[i];
  }
  reverse(a[1].begin(), a[1].end());
  int qwe = 33;
  while (qwe--) {
    bool f = false;
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 13; ++j) {
        if (a[i][j] == s[x]) {
          int r = (i + 1) & 1;
          char p = s[y - 1];
          if (i < r && j + 1 < n) {
            if (a[r][j + 1] == p) f = true;
          }
          if (i > r && j - 1 >= 0 && a[r][j - 1] == p) f = true;
          if (a[r][j] == p) f = true;
          if (f) break;
        }
      }
    }
    if (f) {
      cout << a[0] << '\n' << a[1];
      return 0;
    } else {
      kek();
    }
  }
  assert(0);
  return 0;
}
