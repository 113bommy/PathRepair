#include <bits/stdc++.h>
using namespace std;
long long int power(long long int n, long long int l) {
  long long int odd = 1;
  if (l == 1) return n;
  if (l == 0) return 1;
  while (l > 0) {
    if (l % 2) {
      odd *= n;
    }
    n = n * n;
    l = l / 2;
  }
  return odd;
}
int main() {
  char a[20], b[6], c[6];
  long long int i, j, k, l, l1 = 0, l2 = 0, flag = 0, flag1 = 0;
  cin >> a;
  l = strlen(a);
  for (i = 0; i < l; i++) {
    if (a[i] == ':') flag = 1;
    if (flag == 0) {
      b[l1] = a[i];
      l1++;
    } else {
      if (a[i] != ':') {
        c[l2] = a[i];
        l2++;
      }
    }
  }
  flag = 0;
  int temp = 0;
  for (i = l1 - 1; i >= 0; i--) {
    if (b[l1 - i - 1] >= 65) {
      temp += (b[l1 - i - 1] - 55) * power(60, i);
    } else {
      temp += (b[l1 - i - 1] - 48) * power(60, i);
    }
  }
  if (temp >= 24) {
    flag = 1;
  }
  temp = 0;
  for (i = l2 - 1; i >= 0; i--) {
    if (c[l2 - i - 1] >= 65) {
      temp += (c[l2 - i - 1] - 55) * power(60, i);
    } else {
      temp += (c[l2 - i - 1] - 48) * power(60, i);
    }
  }
  if (temp >= 60) flag = 1;
  if (flag == 0)
    printf("-1\n");
  else {
    for (j = 2; j <= 60; j++) {
      temp = 0;
      flag = 0;
      for (i = l1 - 1; i >= 0; i--) {
        if (b[l1 - i - 1] >= 65) {
          temp += (b[l1 - i - 1] - 55) * power(j, i);
          if (b[l1 - i - 1] - 55 >= j) flag = 1;
        } else {
          temp += (b[l1 - i - 1] - 48) * power(j, i);
          if (b[l1 - i - 1] - 48 >= j) flag = 1;
        }
      }
      if (temp >= 24) flag = 1;
      temp = 0;
      for (i = l2 - 1; i >= 0; i--) {
        if (c[l2 - i - 1] >= 65) {
          temp += (c[l2 - i - 1] - 55) * power(j, i);
          if (c[l2 - i - 1] - 55 >= j) flag = 1;
        } else {
          temp += (c[l2 - i - 1] - 48) * power(j, i);
          if (c[l2 - i - 1] - 48 >= j) flag = 1;
        }
      }
      if (temp >= 60) flag = 1;
      if (flag == 0) {
        flag1 = 1;
        printf("%lld ", j);
      }
    }
    if (flag1 == 0) printf("0\n");
  }
  return 0;
}
