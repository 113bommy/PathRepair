#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int count[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> count[i][j];
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int totalPressed = count[i][j];
      for (int k = 0; k < 4; k++) {
        if (((i + dx[k]) >= 0 && (i + dx[k]) <= 2) &&
            ((j + dy[k]) >= 0 && (j + dy[k]) <= 2)) {
          totalPressed += count[i + dx[k]][j + dy[k]];
        }
      }
      if (totalPressed & 1) {
        cout << "0 ";
      } else {
        cout << "1 ";
      }
    }
    cout << endl;
  }
  return 0;
}
