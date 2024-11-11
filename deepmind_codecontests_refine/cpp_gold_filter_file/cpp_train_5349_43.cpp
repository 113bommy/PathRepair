#include <bits/stdc++.h>
int main() {
  char st[1001] = {'\0'};
  scanf("%s", &st);
  if (st[0] >= 'a' && st[0] <= 'z') {
    st[0] -= 32;
    printf("%s", st);
  } else {
    printf("%s", st);
  }
  return 0;
}
