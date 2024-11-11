#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1000005;
char sa[SIZE], sb[SIZE];
char rab[SIZE], ba[SIZE];
int f1[SIZE * 2];
int f2[SIZE * 2];
int main() {
  while (gets(sa) && gets(sb)) {
    int l1 = strlen(sa);
    int l2 = strlen(sb);
    if (l1 != l2) {
      printf("-1 -1\n");
      continue;
    }
    strcpy(rab, sa);
    reverse(rab, rab + l1);
    strcat(rab, "#");
    strcat(rab, sb);
    rab[l1] = '\0';
    strcpy(ba, sb);
    strcat(ba, "#");
    strcat(ba, sa);
    ba[l1] = '\0';
    int n = l1;
    f1[0] = 0;
    for (int i = 1; i <= 2 * n; i++) {
      f1[i] = f1[i - 1];
      while (f1[i] > 0 && rab[f1[i]] != rab[i]) f1[i] = f1[f1[i] - 1];
      if (rab[f1[i]] == rab[i]) f1[i]++;
    }
    f2[0] = 0;
    for (int i = 1, l = 0, r = 0; i <= 2 * n; i++) {
      f2[i] = 0;
      if (i <= r) f2[i] = min(f2[i - l], r - i + 1);
      while (i + f2[i] <= 2 * n && ba[f2[i]] == ba[i + f2[i]]) f2[i]++;
      if (i + f2[i] - 1 > r) {
        l = i;
        r = i + f2[i] - 1;
      }
    }
    int r1 = -1, r2 = -1;
    for (int i = 0; i < n - 1; i++) {
      if (sa[i] != sb[n - i - 1]) break;
      int len = f1[2 * n - i - 1];
      if (f2[n + 1 + i + 1] >= n - i - len - 1) {
        r1 = i;
        r2 = n - len;
      }
    }
    printf("%d %d\n", r1, r2);
  }
}
