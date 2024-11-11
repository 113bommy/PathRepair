#include <bits/stdc++.h>
using namespace std;
int main() {
  int a1, b1, a2, b2;
  scanf("%d%d%d%d", &a1, &b1, &a2, &b2);
  int valid = 0;
  if (a1 <= b2 + 1 && b2 <= 2 * (a1 + 1)) valid = 1;
  if (b1 <= a2 + 1 && a2 <= 2 * (b1 + 1)) valid = 1;
  if (valid)
    printf("YES");
  else
    printf("NO");
  return 0;
}
