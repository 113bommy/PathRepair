#include <bits/stdc++.h>
using namespace std;
int visited[101][101];
int movetill(int startx, int starty, int endx, int endy, int dir) {
  if (dir == 'r') {
    for (int i = starty; i <= endy; i++) printf("%d %d\n", startx, i);
  } else if (dir == 'd') {
    for (int i = startx; i <= endx; i++) printf("%d %d\n", i, starty);
  } else if (dir == 'u') {
    for (int i = startx; i >= endx; i--) printf("%d %d\n", i, starty);
  } else if (dir == 'l') {
    for (int i = starty; i >= endy; i--) printf("%d %d\n", startx, i);
  }
}
int main() {
  int n, m, i;
  cin >> n >> m;
  if (n == 1 || m == 1) {
    if (n == 1 && m == 2 || n == 2 && m == 1) {
      if (n == 1 && m == 2) {
        printf("0\n1 1\n1 2\n1 1\n");
      } else if (n == 2 && m == 1) {
        printf("0\n1 1\n2 1\n1 1\n");
      }
      return 0;
    }
    if (n == 1) {
      printf("1\n1 %d 1 1\n", m);
      for (i = 0; i < m; i++) printf("%d %d\n", 1, i + 1);
    } else if (m == 1) {
      printf("1\n%d 1 1 1\n", n);
      for (i = 0; i < n; i++) printf("%d %d\n", i + 1, 1);
    }
    cout << 1 << " " << 1 << endl;
    return 0;
  } else if (m % 2 == 0) {
    printf("0\n");
    movetill(1, 1, 1, m, 'r');
    for (i = m; i >= 1; i--) {
      if (i % 2 == 0)
        movetill(2, i, n, i, 'd');
      else
        movetill(n, i, 2, i, 'u');
    }
    printf("1 1\n");
  } else if (n % 2 == 0) {
    printf("0\n");
    movetill(1, 1, n, 1, 'd');
    for (i = n; i >= 1; i--) {
      if (i % 2 == 0)
        movetill(i, 2, i, m, 'r');
      else
        movetill(i, m, i, 2, 'l');
    }
    printf("1 1\n");
  } else {
    printf("1\n%d %d 1 1\n", n, m);
    for (i = 1; i <= n; i++) {
      if (i % 2 == 1)
        movetill(i, 1, i, m, 'r');
      else
        movetill(i, m, i, 1, 'l');
    }
    printf("1 1\n");
  }
  return 0;
}
