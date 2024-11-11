#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, l, r;
  cin >> n >> m;
  char s[n];
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  char c1, c2;
  for (int i = 0; i < m; i++) {
    cin >> l >> r >> c1 >> c2;
    for (int i = l - 1; i < r; i++) {
      if (s[i] == c1) {
        s[i] = c2;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << s[i];
  }
}
