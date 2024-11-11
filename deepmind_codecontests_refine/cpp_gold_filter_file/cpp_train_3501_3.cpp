#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, l, r;
  string s;
  char c1, c2;
  cin >> n >> m;
  cin >> s;
  for (int i = 0; i < m; i++) {
    cin >> l >> r >> c1 >> c2;
    for (int j = l - 1; j < r; j++) {
      if (s.at(j) == c1) {
        s.at(j) = c2;
      }
    }
  }
  cout << s << endl;
  return 0;
}
