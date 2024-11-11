#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, l, r, m;
  char a[105];
  l = 0;
  r = 0;
  cin >> a;
  for (i = 0; i < strlen(a); i++) {
    if (a[i] == '-')
      l++;
    else
      r++;
  }
  if (r == 0) {
    puts("NO");
    return 0;
  }
  if (l % r == 0)
    puts("YES");
  else
    puts("NO");
  return 0;
}
