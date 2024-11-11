#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  char ch;
  int q = 0, sum = 0, kolvo = 0, n, m, pos;
  cin >> n >> m;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == '.') sum++;
    if (i > 0 && s[i - 1] == '.' && s[i] != '.') kolvo++;
  }
  if (s[s.length() - 1] == '.') kolvo++;
  for (int i = 0; i < m; i++) {
    cin >> pos;
    cin >> ch;
    if (n == 1)
      cout << 0 << endl;
    else {
      if (ch == '.' && s[pos - 1] != '.') sum++;
      if (ch != '.' && s[pos - 1] == '.') sum--;
      if (ch == '.' && pos == 1 && s[pos] != '.' && s[pos - 1] != '.') kolvo++;
      if (ch == '.' && pos == n && s[pos - 2] != '.' && s[pos - 1] != '.')
        kolvo++;
      if (ch == '.' && pos > 1 && pos < n && s[pos] != '.' &&
          s[pos - 1] != '.' && s[pos - 2] != '.')
        kolvo++;
      if (ch == '.' && pos > 1 && pos < n && s[pos] == '.' &&
          s[pos - 1] != '.' && s[pos - 2] == '.')
        kolvo--;
      if (ch != '.' && pos == 1 && s[pos] != '.' && s[pos - 1] == '.') kolvo--;
      if (ch != '.' && pos == n && s[pos - 2] != '.' && s[pos - 1] == '.')
        kolvo--;
      if (ch != '.' && pos > 1 && pos < n && s[pos] != '.' &&
          s[pos - 1] == '.' && s[pos - 2] != '.')
        kolvo--;
      if (ch != '.' && pos > 1 && pos < n && s[pos] == '.' &&
          s[pos - 1] == '.' && s[pos - 2] == '.')
        kolvo++;
      cout << sum - kolvo << endl;
      s[pos - 1] = ch;
    }
  }
}
