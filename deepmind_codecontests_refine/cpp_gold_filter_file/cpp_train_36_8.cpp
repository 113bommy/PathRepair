#include <bits/stdc++.h>
using namespace std;
char s[200001];
int ii, ia;
int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", s);
  for (int i = 0; s[i] != '\0'; i++)
    if (s[i] == 'I')
      ii++;
    else if (s[i] == 'A')
      ia++;
  if (ii > 1)
    printf("%d\n", 0);
  else if (ii == 1)
    printf("%d\n", 1);
  else
    printf("%d\n", ia);
  return 0;
}
