#include <bits/stdc++.h>
using namespace std;
int c[2000005] = {0};
void seive() {
  int i, j;
  for (i = 2; i <= 2000000; i++) {
    if (c[i] == 0) {
      for (j = 2 * i; j < 2000003; j += i) {
        c[j] = 1;
      }
    }
  }
}
int main() {
  long long int n, m, count, temp, temp1, temp2, a[10005], flag, flag2, i, j;
  scanf("%lld", &n);
  seive();
  count = 0;
  flag = 0;
  flag2 = 0;
  long long int flag3 = 0;
  long long int temp4;
  for (i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
    if (c[1 + a[i]] == 0 && a[i] != 1) {
      flag2 = 1;
      temp = a[i];
    }
    if (a[i] == 1) count++;
    if (c[a[i]] == 0) {
      flag3 = 1;
      temp4 = a[i];
    }
  }
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (c[a[i] + a[j]] == 0) {
        flag = 1;
        temp1 = a[i];
        temp2 = a[j];
        break;
      }
    }
  }
  if (count >= 2) {
    if (flag2) {
      printf("%lld\n", count + 1);
      for (i = 0; i < count; i++) printf("1 ");
      printf("%lld", temp);
      flag2 = 0;
      printf("\n");
    } else {
      printf("%lld\n", count);
      for (i = 0; i < count; i++) printf("1 ");
      printf("\n");
    }
  } else {
    if (count >= 1 && flag2) {
      printf("2\n");
      printf("1 %lld\n", temp);
    } else if (flag) {
      printf("2\n");
      printf("%lld %lld\n", temp1, temp2);
    } else if (flag3) {
      printf("1\n");
      printf("%lld\n", temp4);
    } else {
      printf("1\n");
      printf("%lld\n", a[0]);
    }
  }
  return 0;
}
