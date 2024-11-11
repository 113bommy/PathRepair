#include <bits/stdc++.h>
using namespace std;
char g[10][10];
int main() {
  for (int i = 0; i < 8; i++) scanf("%s", g[i]);
  int b = 0x3f3f3f3f, w = 0x3f3f3f3f;
  for (int i = 0; i < 8; i++) {
    int ok1 = 1, ok2 = 1;
    int bb = b;
    for (int j = 0; j < 8; j++) {
      if (g[j][i] == 'W') {
        if (ok1) {
          w = min(j, w);
        }
        bb = b;
      } else if (g[j][i] == 'B') {
        if (ok2) {
          bb = min(7 - j, bb);
        }
        ok1 = 0;
      }
    }
    b = min(bb, b);
  }
  if (w <= b)
    cout << "A";
  else
    cout << "B";
}
