#include <bits/stdc++.h>
using namespace std;
int wyk, n, t[2010][2010], xx1[2010], xx2[2010], yy1[2010], yy2[2010], res;
char s[2010];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s + 1);
    for (int j = 1; j <= n; j++) t[i][j] = s[j] - '0';
  }
  for (int i = n; i > 0; i--)
    for (int j = 1; j < i; j++) {
      wyk = xx1[j] + yy1[i];
      if (wyk % 2 != t[i][j]) {
        res++;
        xx1[j]++;
        yy1[i]++;
      }
    }
  for (int i = 1; i <= n; i++)
    for (int j = n; j > i; j--) {
      wyk = xx2[j] + yy2[i];
      if (wyk % 2 != t[i][j]) {
        res++;
        xx2[j]++;
        yy2[i]++;
      }
    }
  for (int i = 1; i <= n; i++) {
    wyk = xx1[i] + xx2[i] + yy1[i] + yy2[i];
    if (wyk % 2 != t[i][i]) res++;
  }
  printf("%d\n", res);
}
