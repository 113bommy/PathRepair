#include <bits/stdc++.h>
using namespace std;
char s[2005];
int n, i;
int main() {
  scanf("%d", &n);
  scanf("%s", s);
  int chang = strlen(s);
  int num = 0;
  for (i = n; i < chang; i = i + n) {
    if ((s[i - 1] == s[i - 2]) && (s[i - 1] == s[i - 3])) num++;
  }
  printf("%d", num);
  return 0;
}
