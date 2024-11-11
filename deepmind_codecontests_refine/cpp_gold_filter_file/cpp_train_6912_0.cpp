#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, a1, a2, a3, c, s1;
  char s[200000];
  scanf("%d", &n);
  scanf("%s", s);
  c = strlen(s);
  s1 = 0;
  for (i = n; i < c; i += n) {
    a1 = i - 1;
    a2 = i - 2;
    a3 = i - 3;
    if ((s[a1] == s[a2]) && (s[a2] == s[a3])) s1++;
  }
  printf("%d", s1);
  return 0;
}
