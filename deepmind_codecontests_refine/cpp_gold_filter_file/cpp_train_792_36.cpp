#include <bits/stdc++.h>
using namespace std;
char ch[101][101];
int n, m;
bool ok;
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> ch[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      ok = true;
      for (int k = 0; k < n; k++)
        if (ch[i][j] == ch[k][j] && k != i) {
          ok = false;
          break;
        }
      if (!ok)
        continue;
      else {
        for (int k = 0; k < m; k++)
          if (ch[i][j] == ch[i][k] && k != j) {
            ok = false;
            break;
          }
        if (ok) cout << ch[i][j];
      }
    }
  return 0;
}
