#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, len;
  char c[55];
  scanf("%s", &c);
  scanf("%d", &i);
  len = strlen(c);
  for (j = 0; j < len; j++) {
    c[j] = tolower(c[j]);
  }
  for (j = 0; j < len; j++) {
    if ((int)c[j] <= (int)'a' + i - 1) c[j] = toupper(c[j]);
  }
  printf("%s", c);
  return 0;
}
