#include <bits/stdc++.h>
using namespace std;
int a[110][110];
void paint(int x1, int y1, int x2, int y2, int k) {
  for (int i = x1; i <= x2; i++) {
    for (int j = y1; j <= y2; j++) {
      a[i][j]++;
    }
  }
}
int main() {
  int n;
  int x1, y1, x2, y2;
  while (~scanf("%d", &n)) {
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++) {
      scanf("%d%d%d%d", &y1, &x1, &y2, &x2);
      paint(x1, y1, x2, y2, i);
    }
    int sum = 0;
    for (int i = 1; i <= 100; i++) {
      for (int j = 1; j <= 100; j++) {
        sum += a[i][j];
      }
    }
    printf("%d\n", sum);
  }
  return 0;
}
