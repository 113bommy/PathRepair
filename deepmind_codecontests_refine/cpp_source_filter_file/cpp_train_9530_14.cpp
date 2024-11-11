#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  bool res = false;
  while (n--) {
    char x[50];
    int before, after;
    scanf(" %s %d %d", x, &before, &after);
    if (before >= 2400 && before > after) res = true;
  }
  if (res)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
