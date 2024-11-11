#include <bits/stdc++.h>
using namespace std;
int n, m, k, dem, kq;
char a[3][3];
char b[3][3];
char s1[5], s2[5];
char s3[5];
void solve() {
  dem = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      if (a[i][j] == 'A') {
        if (i == 0 && j == 0) {
          s1[dem++] = 'A';
          s1[dem++] = a[0][1];
          s1[dem++] = a[1][1];
          s1[dem++] = a[1][0];
        }
        if (i == 0 && j == 1) {
          s1[dem++] = 'A';
          s1[dem++] = a[1][1];
          s1[dem++] = a[1][0];
          s1[dem++] = a[0][0];
        }
        if (i == 1 && j == 0) {
          s1[dem++] = 'A';
          s1[dem++] = a[0][0];
          s1[dem++] = a[0][1];
          s1[dem++] = a[1][1];
        }
        if (i == 1 && j == 1) {
          s1[dem++] = 'A';
          s1[dem++] = a[1][0];
          s1[dem++] = a[0][0];
          s1[dem++] = a[0][1];
        }
        break;
      }
    }
  }
  dem = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      if (b[i][j] == 'A') {
        if (i == 0 && j == 0) {
          s2[dem++] = 'A';
          s2[dem++] = b[0][1];
          s2[dem++] = b[1][1];
          s2[dem++] = b[1][0];
        }
        if (i == 0 && j == 1) {
          s2[dem++] = 'A';
          s2[dem++] = b[1][1];
          s2[dem++] = b[1][0];
          s2[dem++] = b[0][0];
        }
        if (i == 1 && j == 0) {
          s2[dem++] = 'A';
          s2[dem++] = b[0][0];
          s2[dem++] = b[0][1];
          s2[dem++] = b[1][1];
        }
        if (i == 1 && j == 1) {
          s2[dem++] = 'A';
          s2[dem++] = b[1][0];
          s2[dem++] = b[0][0];
          s2[dem++] = b[0][1];
        }
        break;
      }
    }
  }
  for (int i = 0; i < 4; i++) {
    if (s1[i] == 'X') {
      for (int j = i; j < 4; j++) {
        s1[j] = s1[j + 1];
      }
      break;
    }
  }
  for (int i = 0; i < 4; i++) {
    if (s2[i] == 'X') {
      for (int j = i; j < 4; j++) {
        s2[j] = s2[j + 1];
      }
      break;
    }
  }
  if (strcmp(s1, s2) == 0) {
    printf("YES\n");
    return;
  }
  printf("NO\n");
}
int main() {
  int i, j;
  for (int i = 0; i < 2; i++) {
    scanf("%s", &a[i]);
  }
  for (int i = 0; i < 2; i++) {
    scanf("%s", &b[i]);
  }
  solve();
  return 0;
}
