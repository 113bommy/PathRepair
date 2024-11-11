#include <bits/stdc++.h>
using namespace std;
int n;
int mo[25];
int pos[25];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &mo[i]);
  mo[0] = 1000;
  mo[n + 1] = 1000;
  int flag = 1, tmp = 0, cnt = 0, i;
  for (i = 1; i <= n; i++) {
    if (mo[i] <= 30) {
      if (mo[i - 1] <= 30 || mo[i + 1] <= 30) {
        flag = 0;
        break;
      }
      if (mo[i] == 29) {
        if (tmp) {
          flag = 0;
          break;
        }
        tmp = 1;
      }
      if (mo[i] < 30) pos[cnt++] = i;
    } else {
      if (mo[i - 1] == 31 && mo[i + 1] == 31) {
        flag = 0;
        break;
      }
    }
  }
  if (cnt > 2)
    flag = 0;
  else if (cnt == 2) {
    if (pos[1] - pos[0] != 12) flag = 0;
  }
  if (n / 12 > cnt) flag = 0;
  printf("%s\n", flag ? "Yes" : "No");
  return 0;
}
