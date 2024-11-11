#include <bits/stdc++.h>
using namespace std;
char s[2222222], t[2222222];
int d[2][2];
int cnt_a, cnt_b;
int n;
int main() {
  scanf("%d\n", &n);
  gets(s);
  gets(t);
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j) d[i][j] = 0;
  for (int i = 0; i < 2 * n; ++i) {
    s[i] -= '0';
    t[i] -= '0';
    ++d[s[i]][t[i]];
  }
  cnt_a = cnt_b = 0;
  for (int i = 0; i < 2 * n; ++i) {
    if (i & 1) {
      if (d[1][1]) {
        --d[1][1];
        ++cnt_a;
      } else if (d[1][0]) {
        --d[1][0];
        ++cnt_a;
      } else if (d[0][1]) {
        --d[0][1];
      } else
        --d[0][0];
    } else {
      if (d[1][1]) {
        --d[1][1];
        ++cnt_b;
      } else if (d[0][1]) {
        --d[0][1];
        ++cnt_b;
      } else if (d[1][0]) {
        --d[0][1];
      } else
        --d[0][0];
    }
  }
  if (cnt_a > cnt_b) {
    printf("First\n");
  } else if (cnt_a < cnt_b) {
    printf("Second\n");
  } else {
    printf("Draw\n");
  }
  return 0;
}
