#include <bits/stdc++.h>
using namespace std;
int main() {
  char str[1005][1005];
  int n, c, i;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s", str[i]);
  }
  for (i = 0; i < n; i++) {
    if (str[i][0] == 'O' && str[i][1] == 'O') {
      str[i][0] = '+';
      str[i][1] = '+';
      c = 1;
      break;
    }
    if (str[i][3] == 'O' && str[i][4] == 'O') {
      str[i][3] = '+';
      str[i][4] = '+';
      c = 1;
      break;
    }
  }
  if (c == 0)
    printf("NO\n");
  else {
    printf("YES\n");
    for (i = 0; i < n; i++) {
      printf("%s\n", str[i]);
    }
  }
  return 0;
}
