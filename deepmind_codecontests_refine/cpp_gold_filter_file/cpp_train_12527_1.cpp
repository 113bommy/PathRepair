#include <bits/stdc++.h>
using namespace std;
char str[400009];
bool pos[400009];
int main() {
  scanf("%s", str);
  int l = 0, len = strlen(str);
  int last = l;
  while (str[l] != '.' && str[l]) l++;
  if (str[0] == '.' || l == len || l > 8) {
    puts("NO");
    return 0;
  }
  last = l;
  for (int i = l + 1; i < len; i++)
    if (str[i] == '.') {
      if (i - last - 1 >= 2 && i - last - 1 <= 11) {
        if (i - last - 1 < 4)
          pos[last + 1] = 1;
        else
          pos[last + 3] = 1;
      } else {
        puts("NO");
        return 0;
      }
      last = i;
    }
  if (len - last > 4 || len == last + 1) {
    puts("NO");
    return 0;
  } else {
    puts("YES");
    for (int i = 0; i < len; i++) {
      printf("%c", str[i]);
      if (pos[i]) puts("");
    }
  }
}
