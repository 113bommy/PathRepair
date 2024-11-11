#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, a[6];
  char c[5];
  for (i = 0; i < 5; i++) {
    scanf("%d", &a[i]);
  }
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s", c);
    getchar();
    if (c[0] == 'S') {
      if (a[0] != 0) {
        printf("S\n");
        a[0]--;
      } else {
        if (a[1] != 0) {
          printf("M\n");
          a[1]--;
        } else if (a[2] != 0) {
          printf("L\n");
          a[2]--;
        } else if (a[3] != 0) {
          printf("XL\n");
          a[3]--;
        } else if (a[4] != 0) {
          printf("XXL\n");
          a[4]--;
        }
      }
    } else if (c[0] == 'M') {
      if (a[1] != 0) {
        printf("M\n");
        a[1]--;
      } else {
        if (a[2] != 0) {
          printf("L\n");
          a[2]--;
        } else if (a[0] != 0) {
          printf("S\n");
          a[0]--;
        } else if (a[3] != 0) {
          printf("XL\n");
          a[3]--;
        } else if (a[4] != 0) {
          printf("XXL\n");
          a[4]--;
        }
      }
    } else if (c[0] == 'L') {
      if (a[2] != 0) {
        printf("L\n");
        a[2]--;
      } else {
        if (a[3] != 0) {
          printf("XL\n");
          a[3]--;
        } else if (a[1] != 0) {
          printf("M\n");
          a[1]--;
        } else if (a[4] != 0) {
          printf("XXL\n");
          a[4]--;
        } else if (a[0] != 0) {
          printf("S\n");
          a[0]--;
        }
      }
    } else if (c[0] == 'X' && c[1] == 'L') {
      if (a[3] != 0) {
        printf("XL\n");
        a[3]--;
      } else {
        if (a[4] != 0) {
          printf("XXL\n");
          a[4]--;
        } else if (a[2] != 0) {
          printf("L\n");
          a[2]--;
        } else if (a[1] != 0) {
          printf("M\n");
          a[1]--;
        } else if (a[0] != 0) {
          printf("S\n");
          a[0]--;
        }
      }
    } else if (c[0] == 'X' && c[1] == 'X' && c[2] == 'L') {
      if (a[4] != 0) {
        printf("XXL\n");
        a[4]--;
      } else {
        if (a[3] != 0) {
          printf("XL\n");
          a[3]--;
        }
        if (a[2] != 0) {
          printf("L\n");
          a[2]--;
        } else if (a[1] != 0) {
          printf("M\n");
          a[1]--;
        } else if (a[0] != 0) {
          printf("S\n");
          a[0]--;
        }
      }
    }
  }
}
