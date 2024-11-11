#include <bits/stdc++.h>
using namespace std;
int base = -1;
bool ans = true;
void base_find(int x) {
  while (x > 1) {
    if (x % 3 == 0)
      x /= 3;
    else if (x % 2 == 0)
      x /= 2;
    else {
      if (base == -1)
        base = x;
      else if (x != base)
        ans = false;
      return;
    }
  }
}
int main() {
  int n, i, x;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &x);
    base_find(x);
  }
  if (ans)
    printf("Yes");
  else
    printf("No");
  return 0;
}
