#include <bits/stdc++.h>
using namespace std;
char s[1000005];
char shu[2][1000005];
int main() {
  scanf("%s", s);
  int len = strlen(s);
  int cnt = 0;
  int d = 0;
  for (int i = 0; i < len; i++) {
    if (s[i] == '.') {
      cnt++;
      d = 0;
      continue;
    }
    shu[cnt][d++] = s[i];
  }
  int zheng = strlen(shu[0]);
  int xiao = strlen(shu[1]);
  int z = 0, x = xiao;
  for (int i = 0; i < zheng; i++) {
    if (shu[0][i] == '0')
      z++;
    else
      break;
  }
  for (int i = xiao - 1; i >= 0; i--) {
    if (shu[1][i] == '0')
      x--;
    else
      break;
  }
  if (zheng - z == 0) {
    int d = 0;
    for (int i = 0; i < x; i++) {
      if (shu[1][i] == '0')
        d++;
      else
        break;
    }
    printf("%c", shu[1][d]);
    if (x - d == 0)
      printf("E-%d", x - 1);
    else {
      printf(".");
      for (int i = d + 1; i < x; i++) printf("%c", shu[1][i]);
      printf("E-%d", d + 1);
    }
  } else if (x == 0) {
    if (zheng - z == 1)
      printf("%c", shu[0][z]);
    else {
      printf("%c", shu[0][z]);
      int z1 = zheng;
      for (int i = z1 - 1; i > z; i--) {
        if (shu[0][i] == '0')
          z1--;
        else
          break;
      }
      if (z1 - z != 1) {
        printf(".");
        for (int i = z + 1; i < z1; i++) printf("%c", shu[0][i]);
      }
      printf("E%d", zheng - z - 1);
    }
  } else {
    if (zheng - z == 1) {
      printf("%c", shu[0][z]);
      printf(".");
      for (int i = 0; i < x; i++) printf("%c", shu[1][i]);
    } else {
      printf("%c", shu[0][z]);
      printf(".");
      for (int i = z + 1; i < zheng; i++) printf("%c", shu[0][i]);
      for (int i = 0; i < x; i++) printf("%c", shu[1][i]);
      printf("E%d", zheng - z - 1);
    }
  }
  return 0;
}
