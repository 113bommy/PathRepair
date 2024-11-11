#include <bits/stdc++.h>
using namespace std;
void alll(int m) {
  int x = 0;
  while (x < m) {
    printf("#");
    x++;
  }
  printf("\n");
}
void rightt(int m) {
  int y = 0;
  while (y < m - 1) {
    printf(".");
    y++;
  }
  printf("#\n");
}
void leftt(int m) {
  int z = 0;
  printf("#");
  while (z < m - 1) {
    printf(".");
    z++;
  }
  printf("\n");
}
int main() {
  int n, m, i, c = 0;
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    if (i % 2 != 0) {
      alll(m);
    } else if (i % 2 == 0 && c == 0) {
      rightt(m);
      c = 1;
    } else if (i % 2 == 0 && c == 1) {
      leftt(m);
      c = 0;
    }
  }
  return 0;
}
