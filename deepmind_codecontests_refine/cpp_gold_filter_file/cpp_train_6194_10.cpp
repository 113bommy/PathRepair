#include <bits/stdc++.h>
using namespace std;
int f[1000001];
int main() {
  int n, a, u = -1;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a);
    for (int j = a; j <= 1000000; j += a) f[j] = 1;
  }
  for (int i = 1; i <= 1000000; i++) {
    if (!f[i]) {
      u = i;
      break;
    }
  }
  printf("%d", u);
  return 0;
}
