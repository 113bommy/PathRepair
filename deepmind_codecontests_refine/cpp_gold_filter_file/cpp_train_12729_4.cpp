#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string a, b, c;
  cin >> a >> b >> c;
  string w = a + b;
  for (int i = 0; i < c.size(); i++) {
    for (int j = 0; j < w.size(); j++) {
      if (c[i] == w[j]) {
        w[j] = '*';
        c[i] = '*';
        break;
      }
    }
  }
  for (int i = 0; i < c.size(); i++) {
    if (c[i] != '*' || w[i] != '*') {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
}
