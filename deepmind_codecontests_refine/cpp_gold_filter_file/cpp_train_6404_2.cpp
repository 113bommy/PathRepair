#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[105];
  char b[105];
  char c[105] = {'0'};
  scanf("%s", a);
  scanf("%s", b);
  for (int j = 0; j < strlen(a); j++) {
    if (a[j] != b[j])
      c[j] = '1';
    else
      c[j] = '0';
  }
  printf("%s\n", c);
  return 0;
}
