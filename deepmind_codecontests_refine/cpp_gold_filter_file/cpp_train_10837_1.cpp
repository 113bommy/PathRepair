#include <bits/stdc++.h>
using namespace std;
char s[100];
int main() {
  scanf("%s", s);
  int len = strlen(s);
  if (len % 20 == 0) {
    printf("%d %d\n", len / 20, 20);
    for (int i = 0; i < len / 20; i++) {
      for (int j = 0; j < 20; j++) {
        printf("%c", s[i * 20 + j]);
      }
      printf("\n");
    }
  } else {
    int tmp = len / 20 + 1;
    int tmpp = len / tmp;
    int ttmp = tmp - len % tmp;
    if (len % tmp == 0) {
      printf("%d %d\n", tmp, tmpp);
      for (int i = 0; i < tmp; i++) {
        for (int j = 0; j < tmpp; j++) {
          printf("%c", s[i * tmpp + j]);
        }
        printf("\n");
      }
    } else {
      printf("%d %d\n", tmp, tmpp + 1);
      for (int i = 0; i < len % tmp; i++) {
        for (int j = 0; j < tmpp + 1; j++) {
          printf("%c", s[i * tmpp + i + j]);
        }
        printf("\n");
      }
      for (int i = len % tmp; i < tmp; i++) {
        for (int j = 0; j < tmpp; j++) {
          printf("%c", s[len % tmp * (tmpp + 1) + (i - len % tmp) * tmpp + j]);
        }
        printf("*\n");
      }
    }
  }
}
