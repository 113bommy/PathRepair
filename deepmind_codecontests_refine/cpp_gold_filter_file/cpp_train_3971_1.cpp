#include <bits/stdc++.h>
using namespace std;
char s[1010], t[1010];
bool ok(char a) {
  return (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u');
}
int main() {
  scanf("%s%s", s, t);
  int n = strlen(s), m = strlen(t);
  if (n != m) {
    printf("No\n");
    return 0;
  }
  bool f = 1;
  for (int i = 0; i < n; i++) {
    if (ok(s[i]) != ok(t[i])) {
      f = 0;
      break;
    }
  }
  printf("%s\n", f ? "Yes" : "No");
  return 0;
}
