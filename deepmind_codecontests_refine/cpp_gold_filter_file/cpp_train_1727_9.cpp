#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int p[10] = {8, -1, -1, 3, 6, 9, 4, 7, 0, 5};
  char s[11];
  scanf("%s", s);
  int len = strlen(s);
  bool ok = true;
  for (int i = 0; i < len; ++i) {
    if (s[len - 1 - i] - '0' != p[s[i] - '0']) {
      ok = false;
      break;
    }
  }
  if (ok)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
