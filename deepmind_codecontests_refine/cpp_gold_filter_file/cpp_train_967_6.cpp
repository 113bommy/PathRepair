#include <bits/stdc++.h>
char str[12];
char a[6], b[6];
int radix[59];
int convert(char a[], int len, int radix) {
  int i;
  int dec = 0;
  for (i = 0; i < len; i++) {
    int temp = ('0' <= a[i] && a[i] <= '9') ? (a[i] - '0') : (a[i] - 'A' + 10);
    dec = dec * radix + temp;
  }
  return dec;
}
int find_max(char a[], int len) {
  int i;
  int max = 0;
  for (i = 0; i < len; i++) {
    int temp = ('0' <= a[i] && a[i] <= '9') ? (a[i] - '0') : (a[i] - 'A' + 10);
    if (temp > max) max = temp;
  }
  return max;
}
int main() {
  scanf("%s", str);
  int i = 0, j = 0;
  while (str[i] != ':') {
    a[j++] = str[i];
    i++;
  }
  a[j] = '\0';
  j = 0;
  i++;
  while (str[i] != '\0') {
    b[j++] = str[i];
    i++;
  }
  b[j] = '\0';
  int a_len = strlen(a);
  int b_len = strlen(b);
  int a_max = find_max(a, a_len);
  int b_max = find_max(b, b_len);
  int min = ((a_max > b_max) ? a_max : b_max) + 1;
  if (min < 2) {
    min = 2;
  }
  int a_dec = 0, b_dec = 0;
  j = 0;
  for (i = min; i <= 60; i++) {
    a_dec = convert(a, a_len, i);
    b_dec = convert(b, b_len, i);
    if (a_dec < 24 && b_dec < 60) {
      radix[j++] = i;
    }
  }
  if (radix[j - 1] == 60)
    printf("-1\n");
  else if (j == 0)
    printf("0\n");
  else {
    for (i = 0; i < j; i++) {
      printf("%d ", radix[i]);
    }
    printf("\n");
  }
  return 0;
}
