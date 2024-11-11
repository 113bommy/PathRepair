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
    if ((s[n - 1] == s[n - 2]) && (s[n - 1] == s[n - 3])) num++;
  }
  printf("%d", num);
  return 0;
}
