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
    if (str[i] == '0' || str[i] == '2' || str[i] == '4' || str[i] == '6' ||
        str[i] == '8')
      ++ans;
  }
  printf("%d\n", ans);
  return 0;
}
