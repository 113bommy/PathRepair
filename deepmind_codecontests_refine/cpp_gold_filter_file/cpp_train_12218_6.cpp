#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<string> room;
char buff[20];
void solve() {
  int result = 0;
  for (int x1 = 0; x1 < m; x1++)
    for (int y1 = 0; y1 < n; y1++)
      for (int x2 = x1; x2 < m; x2++)
        for (int y2 = y1; y2 < n; y2++) {
          int ok = 1;
          for (int i = x1; i <= x2 && ok == 1; i++)
            for (int j = y1; j <= y2; j++)
              if (room[j][i] == '1') {
                ok = 0;
                break;
              } else if (i == x2 && j == y2)
                result = max(result, x2 - x1 + 1 + y2 - y1 + 1);
        }
  printf("%d", 2 * result);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", buff);
    room.push_back((string)buff);
  }
  solve();
  return 0;
}
