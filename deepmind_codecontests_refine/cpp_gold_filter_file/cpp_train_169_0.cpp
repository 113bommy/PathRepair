#include <bits/stdc++.h>
using namespace std;
char str[120];
int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", str);
  int ans = -1;
  char fin[5];
  for (int i = 0; i < n - 1; i++) {
    char s[5];
    s[0] = str[i];
    s[1] = str[i + 1];
    int res = 0;
    for (int j = 0; j < n - 1; j++) {
      if (str[j] == s[0] && str[j + 1] == s[1]) res++;
    }
    if (res > ans) {
      ans = res;
      fin[0] = s[0];
      fin[1] = s[1];
      fin[2] = '\0';
    }
  }
  printf("%s\n", fin);
  return 0;
}
