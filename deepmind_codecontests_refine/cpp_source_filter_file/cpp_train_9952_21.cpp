#include <bits/stdc++.h>
using namespace std;
int n;
int a[10];
int s1[10], s2[10], s3[10];
int check(double x) {
  if (x > (1 / 2.0))
    return 500;
  else if (x > (1 / 4.0))
    return 1000;
  else if (x > (1 / 8.0))
    return 1500;
  else if (x > (1 / 16.0))
    return 2000;
  else if (x > (1 / 32.0))
    return 2500;
  else
    return 3000;
}
int main() {
  int n;
  memset(a, 0, sizeof(a));
  scanf("%d", &n);
  scanf("%d %d %d %d %d", &s1[1], &s1[2], &s1[3], &s1[4], &s1[5]);
  if (s1[1] != -1) a[1]++;
  if (s1[2] != -1) a[2]++;
  if (s1[3] != -1) a[3]++;
  if (s1[4] != -1) a[4]++;
  if (s1[5] != -1) a[5]++;
  scanf("%d %d %d %d %d", &s2[1], &s2[2], &s2[3], &s2[4], &s2[5]);
  if (s2[1] != -1) a[1]++;
  if (s2[2] != -1) a[2]++;
  if (s2[3] != -1) a[3]++;
  if (s2[4] != -1) a[4]++;
  if (s2[5] != -1) a[5]++;
  for (int i = 3; i <= n; i++) {
    scanf("%d %d %d %d %d", &s3[1], &s3[2], &s3[3], &s3[4], &s3[4]);
    if (s3[1] != -1) a[1]++;
    if (s3[2] != -1) a[2]++;
    if (s3[3] != -1) a[3]++;
    if (s3[4] != -1) a[4]++;
    if (s3[5] != -1) a[5]++;
  }
  int flag[10];
  if (s1[1] == -1)
    flag[1] = 0;
  else {
    if (s2[1] == -1)
      flag[1] = 0;
    else if (s1[1] < s2[1])
      flag[1] = 0;
    else
      flag[1] = 1;
  }
  if (s1[2] == -1)
    flag[2] = 0;
  else {
    if (s2[2] == -1)
      flag[2] = 0;
    else if (s1[2] < s2[2])
      flag[2] = 0;
    else
      flag[2] = 1;
  }
  if (s1[3] == -1)
    flag[3] = 0;
  else {
    if (s2[3] == -1)
      flag[3] = 0;
    else if (s1[3] < s2[3])
      flag[3] = 0;
    else
      flag[3] = 1;
  }
  if (s1[4] == -1)
    flag[4] = 0;
  else {
    if (s2[4] == -1)
      flag[4] = 0;
    else if (s1[4] < s2[4])
      flag[4] = 0;
    else
      flag[4] = 1;
  }
  if (s1[5] == -1)
    flag[5] = 0;
  else {
    if (s2[5] == -1)
      flag[5] = 0;
    else if (s1[5] < s2[5])
      flag[5] = 0;
    else
      flag[5] = 1;
  }
  int exm1 = 0, exm2 = 0;
  if (s1[1] != -1) exm1 += check((((double)(a[1])) / n)) * (1 - s1[1] / 250.0);
  if (s1[2] != -1) exm1 += check((((double)(a[2])) / n)) * (1 - s1[2] / 250.0);
  if (s1[3] != -1) exm1 += check((((double)(a[3])) / n)) * (1 - s1[3] / 250.0);
  if (s1[4] != -1) exm1 += check((((double)(a[4])) / n)) * (1 - s1[4] / 250.0);
  if (s1[5] != -1) exm1 += check((((double)(a[5])) / n)) * (1 - s1[5] / 250.0);
  if (s2[1] != -1) exm2 += check((((double)(a[1])) / n)) * (1 - s2[1] / 250.0);
  if (s2[2] != -1) exm2 += check((((double)(a[2])) / n)) * (1 - s2[2] / 250.0);
  if (s2[3] != -1) exm2 += check((((double)(a[3])) / n)) * (1 - s2[3] / 250.0);
  if (s2[4] != -1) exm2 += check((((double)(a[4])) / n)) * (1 - s2[4] / 250.0);
  if (s2[5] != -1) exm2 += check((((double)(a[5])) / n)) * (1 - s2[5] / 250.0);
  if (exm1 > exm2) {
    printf("0\n");
    return 0;
  }
  int re = n;
  for (int i = 1; i <= 50000; i++) {
    exm1 = 0;
    exm2 = 0;
    n++;
    a[1] += flag[1];
    a[2] += flag[2];
    a[3] += flag[3];
    a[4] += flag[4];
    a[5] += flag[5];
    if (s1[1] != -1)
      exm1 += check((((double)(a[1])) / n)) * (1 - s1[1] / 250.0);
    if (s1[2] != -1)
      exm1 += check((((double)(a[2])) / n)) * (1 - s1[2] / 250.0);
    if (s1[3] != -1)
      exm1 += check((((double)(a[3])) / n)) * (1 - s1[3] / 250.0);
    if (s1[4] != -1)
      exm1 += check((((double)(a[4])) / n)) * (1 - s1[4] / 250.0);
    if (s1[5] != -1)
      exm1 += check((((double)(a[5])) / n)) * (1 - s1[5] / 250.0);
    if (s2[1] != -1)
      exm2 += check((((double)(a[1])) / n)) * (1 - s2[1] / 250.0);
    if (s2[2] != -1)
      exm2 += check((((double)(a[2])) / n)) * (1 - s2[2] / 250.0);
    if (s2[3] != -1)
      exm2 += check((((double)(a[3])) / n)) * (1 - s2[3] / 250.0);
    if (s2[4] != -1)
      exm2 += check((((double)(a[4])) / n)) * (1 - s2[4] / 250.0);
    if (s2[5] != -1)
      exm2 += check((((double)(a[5])) / n)) * (1 - s2[5] / 250.0);
    if (exm1 > exm2) {
      printf("%d\n", n - re);
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}
