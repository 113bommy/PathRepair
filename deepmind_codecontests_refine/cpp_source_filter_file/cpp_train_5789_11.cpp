#include <bits/stdc++.h>
using namespace std;
signed main(void) {
  int judge = 0;
  int road[4][4];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> road[i][j];
    }
  }
  for (int i = 0; i < 3; i++) {
    if (road[i][0] == 1 && (road[i][3] == 1 || road[(i - 1) % 4][3] == 1))
      judge = 1;
    if (road[i][1] == 1 && (road[i][3] == 1 || road[(i + 2) % 4][3] == 1))
      judge = 1;
    if (road[i][2] == 1 && (road[i][3] == 1 || road[(i + 1) % 4][3] == 1))
      judge = 1;
  }
  if (judge == 1)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
