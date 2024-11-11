#include <bits/stdc++.h>
using namespace std;
int xb[101], yb[101];
int main() {
  int N, M;
  char c;
  cin >> N >> M;
  for (int y = 1; y <= M; y++) {
    for (int x = 1; x <= N; x++) {
      cin >> c;
      if (c == '*') {
        xb[x]++;
        yb[y]++;
      }
    }
  }
  int x, y;
  for (y = 1; y <= M && yb[y] != 1; y++)
    ;
  cout << y << " ";
  for (x = 1; x <= N && xb[x] != 1; x++)
    ;
  cout << x;
  return 0;
}
