#include <bits/stdc++.h>
using namespace std;
int main() {
  char sx = getchar();
  int sy;
  cin >> sy;
  getchar();
  char tx = getchar();
  int ty;
  cin >> ty;
  cout << max(abs(sx - tx), abs(sy - ty)) << endl;
  bool rl = (sx <= tx);
  bool ud = (sy <= ty);
  while (sy != ty || sx != tx) {
    if (rl && sx != tx) {
      sx++;
      cout << 'R';
    } else if (sx != tx) {
      sx--;
      cout << 'L';
    }
    if (ud && sy != ty) {
      sy++;
      cout << 'U';
    } else if (sy != ty) {
      sy--;
      cout << 'D';
    }
    cout << endl;
  }
  return 0;
}
