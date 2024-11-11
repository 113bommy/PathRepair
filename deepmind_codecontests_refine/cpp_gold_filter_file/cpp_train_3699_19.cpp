#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j;
  string str, tmp;
  scanf("%d", &n);
  ;
  cin >> str;
  int a[3] = {};
  for (i = 0; i < n; i++) {
    if (str[i] == 'B')
      a[0]++;
    else if (str[i] == 'G')
      a[1]++;
    else
      a[2]++;
  }
  if (a[0] >= 1 && a[1] >= 1 && a[2] >= 1) printf("BGR\n");
  if (a[0] != 0 && a[1] == 0 && a[2] == 0) printf("B\n");
  if (a[1] != 0 && a[0] == 0 && a[2] == 0) printf("G\n");
  if (a[2] != 0 && a[1] == 0 && a[0] == 0) printf("R\n");
  if (a[0] && a[1] && a[2] == 0) {
    if (a[1] != 1) printf("B");
    if (a[0] != 1) printf("G");
    printf("R\n");
  }
  if (a[0] && a[2] && a[1] == 0) {
    if (a[2] != 1) printf("B");
    printf("G");
    if (a[0] != 1) printf("R");
    printf("\n");
    ;
  }
  if (a[2] && a[1] && a[0] == 0) {
    printf("B");
    if (a[2] != 1) printf("G");
    if (a[1] != 1) printf("R");
    printf("\n");
    ;
  }
  return 0;
}
