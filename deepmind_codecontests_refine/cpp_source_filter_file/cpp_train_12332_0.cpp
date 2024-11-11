#include <bits/stdc++.h>
using namespace std;
int size[10];
char pp[5][10] = {"S", "M", "L", "XL", "XXL"};
int main() {
  int i, j, n;
  char s[20];
  for (i = 0; i < 5; i++) scanf("%d", &size[i]);
  scanf("%d", &n);
  while (n--) {
    scanf("%s", &s);
    int pos;
    for (i = 0; i < 5; i++)
      if (strcmp(s, pp[i]) == 0) {
        pos = i;
        break;
      }
    if (size[pos]) {
      size[pos]--;
      printf("%s\n", pp[pos]);
    } else {
      int cnt = 1;
      while (cnt <= 2) {
        if (pos + cnt < 5 && size[pos + cnt]) {
          size[pos + cnt]--;
          printf("%s\n", pp[pos + cnt]);
          break;
        } else if (pos - cnt >= 0 && size[pos - cnt]) {
          size[pos - cnt]--;
          printf("%s\n", pp[pos - cnt]);
          break;
        }
        cnt++;
      }
    }
  }
  return 0;
}
