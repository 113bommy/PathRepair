#include <bits/stdc++.h>
using namespace std;
int cmd(char x, char y) { return x < y; }
int main() {
  int n;
  char a[210000];
  scanf("%d%s", &n, a);
  int len = strlen(a);
  if (n > len) {
    int Max = 10000;
    for (int i = 0; i < len; i++) {
      if (Max > a[i]) Max = a[i];
    }
    printf("%c", Max);
    return 0;
  }
  int MAX = -10000;
  for (int i = 0; i < len; i++) {
    int ss = i + n;
    if (ss >= len) break;
    int Max = 10000, zz;
    for (; i < ss; i++) {
      if (Max > a[i]) {
        Max = a[i];
        zz = i;
      }
    }
    if (MAX < Max) MAX = Max;
    i = zz;
  }
  char cnt[210000];
  int cot = 0;
  for (int i = 0; i < len; i++) {
    if (a[i] < MAX) {
      cnt[cot++] = a[i];
      continue;
    }
    int ss = i + n;
    if (ss >= len) {
      for (i; i < len; i++) {
        if (a[i] < MAX) {
          cnt[cot++] = a[i];
        }
      }
      break;
    }
    int Max = 10000, zz;
    for (; i < ss; i++) {
      if (a[i] < MAX) {
        cnt[cot++] = a[i];
        break;
      }
      if (Max > a[i]) {
        Max = a[i];
        zz = i;
      }
    }
    if (i == ss) {
      i = zz;
      cnt[cot++] = Max;
    }
  }
  cnt[cot] = '\0';
  sort(cnt, cnt + cot, cmd);
  printf("%s", cnt);
  return 0;
}
