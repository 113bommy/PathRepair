#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n, m, l, t;
  char c1, c2;
  string s;
  cin >> n >> m >> s;
  while (m--) {
    cin >> l >> t >> c1 >> c2;
    for (int i = l - 1; i <= t - 1; i++) {
      if (s[i] == c1) s[i] = c2;
    }
  }
  cout << s << endl;
  return 0;
}
