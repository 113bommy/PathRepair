#include <bits/stdc++.h>
using namespace std;
char str[1010];
int main() {
  scanf("%s", str);
  int len = strlen(str), ans = 0;
  for (int i = 0; i < len; ++i) {
    if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' ||
        str[i] == 'u')
      ++ans;
    if (str[i] == '1' || str[i] == '3' || str[i] == '5' || str[i] == '7' ||
        str[i] == '9')
      ++ans;
  }
  printf("%d\n", ans);
  return 0;
}
