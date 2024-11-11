#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  char dir[32];
  char rail[205];
  while (scanf("%d%d%d", &n, &m, &k) != EOF) {
    getchar();
    fgets(dir, 32, stdin);
    int d = dir[3] == 'h' ? -1 : 1;
    scanf("%s", rail);
    if (m == k) {
      printf("Controller 0\n");
      continue;
    }
    int controller = -1;
    for (int i = 0; rail[i]; ++i) {
      if (rail[i] == '0') {
        if (m < k) {
          if (1 < m) m -= 1;
        } else {
          if (m < n) m += 1;
        }
        if (m == k) {
          controller = i;
          break;
        }
      } else {
        if (k == 1) {
          m = n;
        } else if (2 <= k && k <= n - 1) {
          m = (d == -1 ? n : 1);
        } else {
          m = 1;
        }
      }
      if (k == 1) d = +1;
      if (k == n) d = -1;
      k += d;
      if (m == k) {
        controller = i;
        break;
      }
    }
    if (controller != -1) {
      printf("Controller %d\n", controller + 1);
    } else {
      printf("Stowaway\n");
    }
  }
  return 0;
}
