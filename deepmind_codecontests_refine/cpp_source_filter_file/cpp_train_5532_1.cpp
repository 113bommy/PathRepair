#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[100];
  cin >> a;
  int i, l, c = 0;
  l = strlen(a);
  for (i = 0; i < l; i++)
    if (a[i] == '4' || a[i] == '7') c++;
  if (c >= 4 || c <= 7)
    printf("YES\n");
  else
    printf("NO\n");
}
