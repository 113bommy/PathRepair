#include <bits/stdc++.h>
using namespace std;
int n;
char c[101][101];
string s;
void solve() {
  int r = 0, k = 0, d = 0;
  for (int i = 0; i < n; i++) {
    k += s[i] == '[' ? 2 : -2;
    r = max(r, k);
  }
  for (int i = 0; i < n; i++, d++) {
    c[k][d] = '+';
    c[r][d] = '+';
    for (int j = k + 1; j < r; j++) c[j][d] = '|';
    if (s[i] == '[') {
      c[k][d + 1] = '-';
      c[r][d + 1] = '-';
      if (s[i + 1] == '[')
        k++, r--;
      else if (s[i + 1] == ']')
        d += 3;
    } else if (s[i] == ']') {
      c[k][d - 1] = '-';
      c[r][d - 1] = '-';
      if (s[i + 1] == ']') k--, r++;
    }
  }
  for (int i = 0; i <= r; i++) {
    for (int j = 0; j < d; j++) {
      cout << (c[i][j] ? c[i][j] : ' ');
    }
    cout << endl;
  }
}
int main() {
  cin >> n >> s;
  solve();
}
