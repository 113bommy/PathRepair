#include <bits/stdc++.h>
using namespace std;
const int Nmax = 1e5 + 5;
string s[Nmax];
int n;
bool found;
void autofill(int i) {
  for (int j = 0; j < s[i].size(); j++) {
    if (s[i][j] == '?') {
      s[i][j] = (j == 0) ? '1' : '0';
    }
  }
}
void fix(int i, int j, bool larger) {
  if (j == s[i].size()) {
    found = larger;
    return;
  }
  if (s[i][j] == '?') {
    if (larger)
      s[i][j] = '0', fix(i, j + 1, larger);
    else {
      s[i][j] = s[i - 1][j];
      fix(i, j + 1, larger);
      if (found) return;
      if (s[i - 1][j] == '9') {
        s[i][j] = '?';
        return;
      }
      s[i][j] = s[i - 1][j] + 1;
      fix(i, j + 1, true);
    }
  } else {
    if (larger)
      fix(i, j + 1, larger);
    else {
      if (s[i][j] < s[i - 1][j]) return;
      fix(i, j + 1, (s[i][j] > s[i - 1][j]));
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  for (int i = 1; i <= 2; i++) {
    if (s[i].size() > s[i - 1].size()) {
      autofill(i);
      continue;
    }
    if (s[i].size() < s[i - 1].size()) {
      return cout << "NO", 0;
    }
    found = false;
    fix(i, 0, 0);
    if (!found) return cout << "NO", 0;
  }
  cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    cout << s[i] << "\n";
  }
  return 0;
}
