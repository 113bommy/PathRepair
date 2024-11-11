#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  int l, r;
  char c1, c2;
  for (int i = 0; i < m; i++) {
    cin >> l >> r >> c1 >> c2;
    for (int j = l - 1; j < n; j++) {
      if (s[j] == c1) s[j] = c2;
    }
  }
  cout << s << endl;
  return 0;
}
