#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[200];
  scanf("%s", a);
  int l = strlen(a);
  int sum = 0;
  for (int i = 1; i < l; i++) {
    if (a[i] == '1') {
      sum++;
    }
  }
  if (sum > 0 && l % 2 == 0) {
    printf("%d", l / 2);
  }
  if (sum > 0 && l % 2 == 1) {
    printf("%d", l / 2 + 1);
  }
  if (sum == 0 && l % 2 == 0) {
    printf("%d", l / 2);
  }
  if (sum == 0 && l % 2 == 1) {
    printf("%d", l / 2);
  }
  return 0;
}
