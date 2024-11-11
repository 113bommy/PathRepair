#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
int main() {
  char a[10] = {0};
  char b[10] = {0};
  char bb = 1;
  int hj = 0;
  scanf("%c", &bb);
  do {
    a[hj] = bb;
    hj++;
    scanf("%c", &bb);
  } while (bb != ':');
  a[hj] = 0;
  scanf("%s", &b);
  int begA = -1;
  int begB = -1;
  for (int i = 0; a[i] && a[i] == '0'; i++) begA++;
  for (int i = 0; b[i] && b[i] == '0'; i++) begB++;
  int la = strlen(a);
  int lb = strlen(b);
  char v[37] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int ma = -1;
  int mb = -1;
  if ((begA >= (la - 2)) && (begB >= (lb - 2))) {
    if (a[la - 1] <= 'O') {
      printf("-1");
      return 0;
    }
  }
  for (int i = 0; a[i]; i++) {
    for (int j = 0; v[j]; j++) {
      if (v[j] == a[i]) ma = max(ma, j);
    }
  }
  for (int i = 0; b[i]; i++) {
    for (int j = 0; v[j]; j++) {
      if (v[j] == b[i]) mb = max(mb, j);
    }
  }
  int beg = max(ma, mb) + 1;
  bool f = false;
  for (int i = beg; true; i++) {
    int ca = 0;
    int cb = 0;
    int p = 0;
    for (int j = la - 1; j > begA; j--) {
      int mest = 0;
      for (int k = 0; v[k]; k++) {
        if (v[k] == a[j]) {
          mest = k;
          break;
        }
      }
      int buf = (int)pow((double)i, (double)p) * mest;
      ca += buf;
      p++;
    }
    p = 0;
    for (int j = lb - 1; j > begB; j--) {
      int mest = 0;
      for (int k = 0; v[k]; k++) {
        if (v[k] == b[j]) {
          mest = k;
          break;
        }
      }
      int buf = (int)pow((double)i, (double)p) * mest;
      cb += buf;
      p++;
    }
    if ((ca > 23) || (cb > 59)) break;
    f = true;
    printf("%d ", i);
  }
  if (!f) printf("0");
  return 0;
}
