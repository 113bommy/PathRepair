#include <bits/stdc++.h>
using namespace std;
char s[15];
struct node {
  int x;
  int y;
} a[15];
int k = 0;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int sum = 0;
    k = 0;
    scanf("%s", s);
    int flag = 0;
    for (int i = 0; i < 12; i++) {
      if (s[i] == 'X') {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      printf("0\n");
      continue;
    } else {
      sum++;
      a[k].x = 1;
      a[k].y = 12;
      k++;
    }
    for (int i = 0; i < 6; i++) {
      if (s[i] == 'X' && s[i + 6] == 'X') {
        sum++;
        a[k].x = 2;
        a[k].y = 6;
        k++;
        break;
      }
    }
    for (int i = 0; i < 4; i++) {
      if (s[i] == 'X' && s[i + 4] == 'X' && s[i + 8] == 'X') {
        sum++;
        a[k].x = 3;
        a[k].y = 4;
        k++;
        break;
      }
    }
    for (int i = 0; i < 3; i++) {
      if (s[i] == 'X' && s[i + 3] == 'X' && s[i + 6] == 'X' &&
          s[i + 9] == 'X') {
        sum++;
        a[k].x = 4;
        a[k].y = 3;
        k++;
        break;
      }
    }
    for (int i = 0; i < 2; i++) {
      if (s[i] == 'X' && s[i + 2] == 'X' && s[i + 4] == 'X' &&
          s[i + 6] == 'X' && s[i + 8] == 'X' && s[i + 10] == 'X') {
        sum++;
        a[k].x = 6;
        a[k].y = 2;
        k++;
        break;
      }
    }
    flag = 0;
    for (int i = 0; i <= 11; i++) {
      if (s[i] == 'O') {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      sum++;
      a[k].x = 12;
      a[k].y = 1;
      k++;
    }
    printf("%d", sum);
    for (int i = 0; i < k; i++) {
      printf(" %dx%d", a[i].x, a[i].y);
    }
    printf("\n");
  }
  return 0;
}
