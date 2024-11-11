#include <bits/stdc++.h>
using namespace std;
int a, ans;
int main() {
  scanf("%d", &a);
  while (a != 0) {
    if (a % 8 == 1) ans++;
    a /= 8;
  }
  printf("%d\n", ans);
  return 0;
}
