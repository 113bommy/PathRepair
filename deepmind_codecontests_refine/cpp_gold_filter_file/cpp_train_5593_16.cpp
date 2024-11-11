#include <bits/stdc++.h>
using namespace std;
int main() {
  char str[1005];
  scanf("%s", str);
  int cc = -1;
  while (str[++cc] != '.') {
  }
  if (str[cc - 1] == '9') {
    printf("GOTO Vasilisa.\n");
    return 0;
  }
  if (str[cc + 1] >= '5') {
    for (int i = 0; i < cc - 1; i++) printf("%c", str[i]);
    printf("%c", str[cc - 1] + 1);
  } else {
    for (int i = 0; i < cc; i++) printf("%c", str[i]);
  }
  printf("\n");
  return 0;
}
