#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  string s;
  cin >> n >> m;
  cin >> s;
  for (int j = 0; j < m; j++) {
    int l, r;
    char c1, c2;
    cin >> l >> r;
    cin >> c1 >> c2;
    if (l == r)
      if (s[l - 1] == c1) s[l - 1] = c2;
    for (int i = l - 1; i < r - 1; i++) {
      if (s[i] == c1) s[i] = c2;
    }
  }
  cout << s;
  return 0;
}
