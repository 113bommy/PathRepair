#include <bits/stdc++.h>
using namespace std;
char s[51];
int main() {
  scanf("%s", s);
  int ans = 0;
  for (int i = 0; s[i]; i++) {
    if (islower(s[i])) ans -= s[i] - 'a';
    if (isupper(s[i])) ans -= s[i] - 'A';
  }
  printf("%d\n", ans);
}
