#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  scanf("%d", &n);
  int num4 = 0, num7 = n / 7;
  int ok = 0;
  int i;
  for (i = num7; i >= 0; i--) {
    if ((n - i * 7) % 4 == 0) {
      ok = 1;
      num4 = (n - i * 7) / 4;
      num7 = i;
      break;
    }
  }
  if (!ok)
    printf("-1");
  else {
    for (int j = 1; j <= num4; j++) printf("4");
    for (int j = 1; j <= num7; j++) printf("7");
  }
  printf("\n");
}
