#include <bits/stdc++.h>
using namespace std;
const int MAXN = 601;
int p[MAXN][MAXN];
int main() {
  int q = 0;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int h, w;
    scanf("%d %d", &h, &w);
    for (int x = 0; x < h; x++) {
      for (int y = 0; y < w; y++) {
        scanf("%d", &p[x][y]);
      }
    }
    int a = 0;
    for (int i = 0; i < w; i++) {
      a += abs(p[h / 2 + 1][i] - p[h / 2][i]);
    }
    int b = 0;
    for (int i = 0; i < w; i++) {
      b += abs(p[0 + 1][i] - p[0][i]);
    }
    double a1 = a / w;
    double b1 = b / w;
    if (a1 > 10 || b1 > 10) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
  return 0;
}
