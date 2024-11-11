#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, x, sum = 0;
  char c, s[300005];
  cin >> n >> m >> s;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == '.')
      if (s[i + 1] == '.') sum++;
  }
  for (int i = 0; i < m; i++) {
    cin >> x >> c;
    if (c == '.') {
      if (s[x - 1] != '.') {
        if (s[x - 2] == '.') sum++;
        if (s[x] == '.') sum++;
      }
    } else {
      if (s[x] == '.') {
        if (s[x - 2] == '.') sum--;
        if (s[x] == '.') sum--;
      }
    }
    s[x - 1] = c;
    cout << sum << '\n';
  }
  return 0;
}
