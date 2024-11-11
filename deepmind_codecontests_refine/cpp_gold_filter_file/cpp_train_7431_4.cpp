#include <bits/stdc++.h>
using namespace std;
int main() {
  int a = 0, b = 0;
  char ch;
  while ((ch = getchar()) != '\n')
    if (ch == '1') a++;
  while ((ch = getchar()) != '\n')
    if (ch == '1') b++;
  if (a >= b || (a % 2 == 1 && a + 1 == b))
    printf("YES\n");
  else
    printf("NO\n");
}
