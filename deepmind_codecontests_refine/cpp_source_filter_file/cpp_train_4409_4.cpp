#include <bits/stdc++.h>
using namespace std;
bool is_mid(int p[], int q[], int r[]) {
  return (p[0] == q[0] && p[1] == r[1]) || (p[0] == q[0] && p[1] == r[1]);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int m, n;
  cin >> m >> n;
  int cord[3][2];
  int k = 0;
  char c;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> c;
      if (c == '*') {
        cord[k][0] = i;
        cord[k][1] = j;
        k++;
      }
    }
  }
  int x, y;
  if (is_mid(cord[0], cord[1], cord[2])) {
    x = cord[1][0] + cord[2][0] - cord[0][0];
    y = cord[1][1] + cord[2][1] - cord[0][1];
  } else if (is_mid(cord[1], cord[0], cord[2])) {
    x = cord[0][0] + cord[2][0] - cord[1][0];
    y = cord[0][1] + cord[2][1] - cord[1][1];
  } else {
    x = cord[0][0] + cord[1][0] - cord[2][0];
    y = cord[0][1] + cord[1][1] - cord[2][1];
  }
  x++;
  y++;
  cout << x << " " << y << "\n";
}
