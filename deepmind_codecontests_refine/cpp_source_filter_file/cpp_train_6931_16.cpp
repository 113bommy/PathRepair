#include <bits/stdc++.h>
using namespace std;
int n, f[100010];
int main() {
  scanf("%d", &n);
  for (int i = 1; i * i <= n; i++) {
    if (f[i] == 0)
      for (int j = 2; i * j <= n; j++) f[i * j] = 1;
  }
  if (n >= 3)
    printf("2\n");
  else
    printf("1\n");
  for (int i = 2; i <= n + 1; i++)
    if (f[i])
      printf("2 ");
    else
      printf("1 ");
  return 0;
}
