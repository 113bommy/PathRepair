#include <bits/stdc++.h>
using namespace std;
int odd1, eve1, odd2, eve2;
int main() {
  int a, b, i, j, c;
  scanf("%d%d", &a, &b);
  for (i = 0; i < a; i++) {
    scanf("%d", &c);
    if (c & 1)
      odd1++;
    else
      eve1++;
  }
  for (i = 0; i < a; i++) {
    scanf("%d", &c);
    if (c & 1)
      odd2++;
    else
      eve2++;
  }
  printf("%d", min(odd1, eve2) + min(odd2, eve1));
  return 0;
}
