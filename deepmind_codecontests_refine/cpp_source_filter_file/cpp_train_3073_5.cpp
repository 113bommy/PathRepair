#include <bits/stdc++.h>
using namespace std;
int a[100], b[100];
int gcd(int x, int y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
int n;
void work1(int x) {
  int g;
  for (int i = 1; i <= n; i++)
    if (a[i] != x)
      b[i] = a[i] / x / 2;
    else {
      g = i;
      b[i] = (a[i] / x) - 1;
      b[i] /= 2;
    }
  for (int i = 1; i <= x; i++) {
    putchar(g + 96);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= b[i]; j++) putchar(i + 96);
    for (int i = n; i >= 1; i--)
      for (int j = 1; j <= b[i]; j++) putchar(i + 96);
  }
}
void printany() {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= a[i]; j++) putchar(i + 96);
}
void work2(int x) {
  for (int i = 1; i <= n; i++) b[i] = a[i] / x;
  for (int i = 1; i <= x / 2; i++) {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= b[i]; j++) putchar(i + 96);
    for (int i = n; i >= 1; i--)
      for (int j = 1; j <= b[i]; j++) putchar(i + 96);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int sum = 0;
  for (int i = 1; i <= n; i++) sum += a[i];
  if (sum % 2) {
    int judge = 0, now;
    for (int i = 1; i <= n; i++)
      if (a[i] % 2) {
        judge++;
        now = a[i];
      }
    if (judge > 1) {
      printf("0\n");
      printany();
      return 0;
    }
    int nowx = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] % 2) continue;
      nowx = gcd(nowx, a[i]);
    }
    nowx = gcd(nowx, now);
    printf("%d\n", nowx);
    work1(now);
    return 0;
  }
  for (int i = 1; i <= n; i++)
    if (a[i] % 2) {
      printf("0\n");
      printany();
      return 0;
    }
  int now = 0;
  for (int i = 1; i <= n; i++) now = gcd(now, a[i]);
  printf("%d\n", now);
  work2(now);
  return 0;
}
