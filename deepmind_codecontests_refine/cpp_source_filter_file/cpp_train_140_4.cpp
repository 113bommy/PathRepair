#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-6;
char s[55];
int main() {
  int n;
  scanf("%s%d", s, &n);
  for (int i = 0; s[i]; i++)
    if (tolower(s[i]) < 'a' + n - 1)
      printf("%c", toupper(s[i]));
    else
      printf("%c", tolower(s[i]));
  return 0;
}
