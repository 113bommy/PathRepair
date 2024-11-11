#include <bits/stdc++.h>
using namespace std;
char s[3333], t[100010];
int main() {
  scanf("%s", s + 1);
  int len = strlen(s + 1);
  int cnt = 0, pos = 0;
  for (int i = 1; i <= len; i++) {
    if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' &&
        s[i] != 'u') {
      cnt++;
      if (cnt >= 3) {
        if (s[i - 1] != s[i] || s[i - 2] != s[i]) {
          t[++pos] = ' ';
          t[++pos] = s[i];
          cnt = 1;
        } else
          t[++pos] = s[i];
      } else
        t[++pos] = s[i];
    } else
      cnt = 0, t[++pos] = s[i];
  }
  printf("%s", t + 1);
}
