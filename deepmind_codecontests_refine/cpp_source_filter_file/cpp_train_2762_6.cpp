#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/uACK:1024000000,1024000000")
const int inf = (int)1e9;
const int nn = 5000010;
int main() {
  int n;
  scanf("%d", &n);
  set<long long, long long> st;
  for (int i = 0; i < n; i++) {
    char op[100];
    scanf("%s", op);
    int x = 0;
    int len = strlen(op);
    for (int i = 4; i < len; i++) x = x * 10 + op[i] - '0';
    len -= 4;
    if (len == 1) {
      if (x >= 9)
        printf("198%d\n", x);
      else
        printf("199%d\n", x);
    } else if (len == 2) {
      if (x == 99)
        puts("1999");
      else
        printf("20%02d\n", x);
    } else if (len == 3) {
      if (x <= 98)
        printf("3%03d\n", x);
      else
        printf("2%d\n", x);
    } else if (len == 4) {
      if (x <= 3098)
        printf("1%04d\n", x);
      else
        printf("%d\n", x);
    } else if (len == 5) {
      if (x <= 13098)
        printf("1%05d\n", x);
      else
        printf("%d\n", x);
    } else if (len == 6) {
      if (x <= 113098)
        printf("1%06d\n", x);
      else
        printf("%d\n", x);
    } else if (len == 7) {
      if (x <= 1113098)
        printf("1%07d\n", x);
      else
        printf("%d\n", x);
    } else if (len == 8) {
      if (x <= 11113098)
        printf("1%08d\n", x);
      else
        printf("%d\n", x);
    } else if (len == 9) {
      if (x <= 111113098)
        printf("1%09d\n", x);
      else
        printf("%d\n", x);
    }
  }
  return 0;
}
