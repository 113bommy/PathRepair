#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, nho, a[33], b[250000][2];
  ;
  string s;
  char chu;
  cin >> n >> m;
  cin >> s;
  for (i = 0; i < 30; i++) {
    a[i] = i;
  }
  for (i = 0; i < m; i++) {
    cin >> chu;
    b[i][0] = chu - 'a';
    cin >> chu;
    b[i][1] = chu - 'a';
  }
  for (i = m - 1; i >= 0; i--) {
    nho = a[b[i][0]];
    a[b[i][0]] = a[b[i][1]];
    a[b[i][1]] = nho;
  }
  for (i = 0; i < s.length(); i++) {
    chu = 'a' + a[s[i] - 'a'];
    cout << chu;
  }
  return 0;
}
