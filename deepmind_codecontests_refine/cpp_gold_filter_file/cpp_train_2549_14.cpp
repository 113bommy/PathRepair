#include <bits/stdc++.h>
using namespace std;
char str[100];
int main() {
  scanf("%s", str);
  int len = strlen(str);
  printf("%d\n", 26 * (len + 1) - len);
  return 0;
}
