#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int sum = 0;
  char a[100];
  for (int i = 0; i < n; i++) {
    scanf("%s", a);
    if (a[0] == 'T') sum = sum + 4;
    if (a[0] == 'C') sum = sum + 6;
    if (a[0] == 'C') sum = sum + 6;
    if (a[0] == 'D') sum = sum + 12;
    if (a[0] == 'I') sum = sum + 20;
  }
  printf("%d", sum);
}
