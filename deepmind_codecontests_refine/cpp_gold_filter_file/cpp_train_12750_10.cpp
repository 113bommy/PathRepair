#include <bits/stdc++.h>
using namespace std;
int a[20];
char s[20];
int main(void) {
  int n;
  scanf("%d", &n);
  scanf("%s", s);
  for (int i = 0; i < n; ++i) {
    a[s[i] - '0']++;
  }
  a[3] += a[4];
  a[2] += a[4] * 2;
  a[5] += a[6];
  a[3] += a[6];
  a[7] += a[8];
  a[2] += a[8] * 3;
  a[3] += a[9] * 2;
  a[2] += a[9];
  a[7] += a[9];
  a[4] = a[6] = a[8] = a[9] = 0;
  for (int i = 9; i >= 2; --i) {
    for (int j = 0; j < a[i]; ++j) {
      printf("%d", i);
    }
  }
  printf("\n");
  return 0;
}
