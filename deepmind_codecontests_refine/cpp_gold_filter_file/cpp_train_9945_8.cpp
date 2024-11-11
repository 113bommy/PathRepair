#include <bits/stdc++.h>
using namespace std;
const long double pi =
    3.141592653589793238462643383279502884197169399375105820974944592307816;
const long long int maxn = 2 * 1e5 + 1, inf = 1e9 + 1;
string s[4];
void shift() {
  int x, y;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      if (s[i][j] == 'X') {
        if (!i && !j)
          swap(s[i][j], s[i][j + 1]);
        else if (!i)
          swap(s[i][j], s[i + 1][j]);
        else if (!j)
          swap(s[i][j], s[i - 1][j]);
        else
          swap(s[i][j], s[i][j - 1]);
        return;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (int i = 0; i < 4; i++) cin >> s[i];
  for (int i = 0; i < 20; i++) {
    shift();
    bool b = 0;
    for (int i = 0; i < 2; i++) {
      if (s[0][i] != s[2][i] || s[1][i] != s[3][i]) {
        b = 1;
        break;
      }
    }
    if (!b) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
