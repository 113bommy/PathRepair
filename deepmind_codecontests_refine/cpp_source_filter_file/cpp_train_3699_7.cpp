#include <bits/stdc++.h>
using namespace std;
int n, ex[3];
char st[210];
int main() {
  scanf("%d", &n);
  scanf("%s", st + 1);
  for (int i = 1; i <= (n); i++) {
    if (st[i] == 'R') ex[0]++;
    if (st[i] == 'G') ex[1]++;
    if (st[i] == 'B') ex[2]++;
  }
  if ((ex[0] > 0) + (ex[1] > 0) + (ex[2] > 0) == 3)
    printf("BGR\n");
  else if ((ex[0] > 0) + (ex[1] > 0) + (ex[2] > 0) == 1) {
    if (ex[0]) printf("R\n");
    if (ex[1]) printf("G\n");
    if (ex[2]) printf("B\n");
  } else {
    if (ex[0] == 0) {
      if (ex[1] == 1 && ex[2] == 1) printf("R\n");
      if (ex[1] > 1 && ex[2] > 1) printf("BGR\n");
      if (ex[1] == 1 && ex[2] > 1) printf("BR\n");
      if (ex[1] > 1 && ex[2] == 1) printf("BG\n");
    }
    if (ex[1] == 0) {
      if (ex[0] == 1 && ex[2] == 1) printf("G\n");
      if (ex[0] > 1 && ex[2] > 1) printf("BGR\n");
      if (ex[0] == 1 && ex[2] > 1) printf("GR\n");
      if (ex[0] > 1 && ex[2] == 1) printf("BG\n");
    }
    if (ex[2] == 0) {
      if (ex[1] == 1 && ex[0] == 1) printf("B\n");
      if (ex[1] > 1 && ex[0] > 1) printf("BGR\n");
      if (ex[1] == 1 && ex[0] > 1) printf("BG\n");
      if (ex[1] > 1 && ex[0] == 1) printf("BR\n");
    }
  }
  return 0;
}
