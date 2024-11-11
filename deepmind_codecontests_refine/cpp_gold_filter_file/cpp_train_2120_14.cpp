#include <bits/stdc++.h>
using namespace std;
char a[100][100];
char b[100][100];
int ra, la, rb, lb;
int cal(int x, int y) {
  int sum = 0;
  for (int i = 0; i < ra; i++) {
    for (int j = 0; j < la; j++) {
      if (x + i >= 0 && x + i < rb && y + j >= 0 && y + j < lb)
        if (a[i][j] == '1' && b[i + x][j + y] == '1') sum++;
    }
  }
  return sum;
}
int main() {
  while (~scanf("%d%d", &ra, &la)) {
    for (int i = 0; i < ra; i++) scanf("%s", a[i]);
    scanf("%d%d", &rb, &lb);
    for (int i = 0; i < rb; i++) scanf("%s", b[i]);
    int mx = 0, my = 0;
    int Max = 0;
    for (int x = -50; x <= 50; x++)
      for (int y = -50; y <= 50; y++) {
        int r = cal(x, y);
        if (r > Max) {
          Max = r;
          mx = x;
          my = y;
        }
      }
    cout << mx << " " << my << endl;
  }
  return 0;
}
