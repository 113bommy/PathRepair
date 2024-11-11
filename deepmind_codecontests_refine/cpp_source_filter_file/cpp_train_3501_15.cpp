#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  string s;
  cin >> n >> m >> s;
  for (int i = 1; i <= m; i++) {
    int x, y;
    char c1, c2;
    cin >> x >> y >> c1 >> c2;
    for (int j = x; j <= y; j++)
      if (s[j] == c1) s[j] = c2;
  }
  cout << s;
}
