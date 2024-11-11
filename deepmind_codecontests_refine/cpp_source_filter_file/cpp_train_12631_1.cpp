#include <bits/stdc++.h>
using namespace std;
char ch[1005][1005];
int main() {
  int x, y, i, j, k;
  cin >> x >> y;
  for (i = 1; i <= y; i++)
    for (j = 1; j <= x; j++) {
      cin >> ch[i][j];
    }
  for (i = 1; i <= y - 1; i++) {
    if (ch[i][1] == ch[i + 1][1]) {
      cout << "NO";
      return 0;
    }
  }
  for (i = 1; i <= y; i++) {
    for (j = 2; j <= x; j++) {
      if (ch[i][j] != ch[i][1]) {
        cout << "NO";
        return 0;
      }
    }
  }
  cout << "YES";
  return 0;
}
