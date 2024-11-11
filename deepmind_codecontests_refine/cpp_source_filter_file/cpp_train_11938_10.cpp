#include <bits/stdc++.h>
using namespace std;
char str[2005];
int main() {
  int n, p;
  while (scanf("%d%d", &n, &p) != EOF) {
    scanf("%s", str);
    int len = strlen(str);
    int flag = 0;
    for (int i = 0; i < len - p; i++) {
      if (str[i] == str[i + p] && str[i] != '.')
        continue;
      else {
        if (str[i] == '.') {
          if (str[i + p] == '0')
            str[i] = '1';
          else
            str[i] = '0';
        } else {
          if (str[i] == '0')
            str[i + p] = '1';
          else
            str[i + p] = '0';
        }
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      printf("No\n");
    } else {
      for (int i = 0; i < n; i++) {
        if (str[i] == '.') {
          str[i] = '0';
        }
      }
      printf("%s\n", str);
    }
  }
  return 0;
}
