#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, l, r;
  char c1, c2;
  string s;
  cin >> n >> m;
  cin >> s;
  while (m--) {
    cin >> l >> r >> c1 >> c2;
    for (int i = (l - 1); i < (min(n, r + 1)); ++i) {
      if (s[i] == c1) s[i] = c2;
    }
  }
  cout << s << endl;
  return 0;
}
