#include <bits/stdc++.h>
using namespace std;
char ch[105][105];
int main() {
  int x, y, i, j, k;
  cin >> x >> y;
  for (i = 0; i < y; i++) cin >> ch[i];
  for (i = 0; i < y - 1; i++) {
    for (j = 0; j < x - 1; j++)
      if (ch[i][j] != ch[i][j + 1]) {
        cout << "NO";
        return 0;
      }
    if (ch[i][0] == ch[i + 1][0]) {
      cout << "NO";
      return 0;
    }
  }
  for (j = 0; j < x - 1; j++)
    if (ch[y - 1][j] != ch[y - 1][j + 1]) {
      cout << "NO";
      return 0;
    }
  cout << "YES";
  return 0;
}
