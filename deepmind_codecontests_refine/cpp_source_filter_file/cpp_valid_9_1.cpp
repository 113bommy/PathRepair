#include <bits/stdc++.h>
using namespace std;
struct node {
  char s = '1';
  int num = 0;
} e[60];
char a[60];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i <= 10; i++) {
      e[i].s = '1';
      e[i].num = 0;
    }
    int n;
    scanf("%s", a);
    int len = strlen(a);
    if (len == 1) {
      printf("0\n");
      continue;
    }
    int num = 0;
    for (int i = 0; i < len; i++) {
      int flag = 0;
      for (int j = 0; j < len; j++) {
        if (a[i] == e[j].s) {
          e[j].num++;
          flag = 1;
        }
      }
      if (flag == 0) {
        e[num].s = a[i];
        e[num].num++;
        num++;
      }
    }
    int num1 = 0, numn = 0;
    for (int i = 0; i < num; i++) {
      if (e[i].num == 1) num1++;
      if (e[i].num >= 2) numn++;
    }
    int sum = 0;
    if (num1 % 2 == 1) {
      sum = (num1 - 1) / 2 + numn;
    } else {
      sum = num1 / 2 + numn;
    }
    printf("%d\n", sum);
  }
  return 0;
}
