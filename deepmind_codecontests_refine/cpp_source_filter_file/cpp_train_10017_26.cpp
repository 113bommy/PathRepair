#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, sum, ans = 0, z[200];
  scanf("%d", &a);
  for (int i = 0; i < a; i++) {
    scanf("%d", &z[i]);
    sum += z[i];
  }
  if (sum % 2 == 1) {
    for (int i = 0; i < a; i++)
      if (z[i] % 2 == 0) ans++;
  } else {
    for (int i = 0; i < a; i++)
      if (z[i] % 2 == 1) ans++;
  }
  printf("%d\n", ans);
}
