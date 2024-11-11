#include <bits/stdc++.h>
using namespace std;
char s[300010];
int main() {
  int m, n, a, ans = 0;
  char c;
  scanf("%d%d", &m, &n);
  scanf("%s", s);
  for (int i = 0; i < strlen(s) - 1; i++) {
    if (s[i] == '.' && s[i + 1] == '.') ans++;
  }
  while (n--) {
    scanf("%d %c", &a, &c);
    int j = a - 1;
    if (s[j] != '.' && c == '.') {
      s[j] = c;
      if (s[j + 1] == '.') ans++;
      if (s[j - 1] == '.') ans++;
    } else if (s[j] == '.' && c != '.') {
      s[j] = c;
      if (s[j + 1] == '.') ans--;
      if (s[j - 1] == '.') ans--;
    }
    printf("%d\n", ans);
  }
  return 0;
}
