#include <bits/stdc++.h>
using namespace std;
char a[11], b[11];
int main() {
  scanf("%s%s", &a, &b);
  int len = string(a).length();
  printf("%c", a[0]);
  for (int i = 1; i < len; i++)
    if (b[0] <= a[i])
      return printf("%c", b[0]), 0;
    else
      printf("%c", a[i]);
  printf("%c", b[0]);
  return 0;
}
