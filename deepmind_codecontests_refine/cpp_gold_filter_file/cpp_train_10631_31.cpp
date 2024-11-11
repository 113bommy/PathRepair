#include <bits/stdc++.h>
using namespace std;
const int M = 4e3 + 44;
const int F = 4000;
int n;
int s[M];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &s[i]);
  printf("%d\n", n + 1);
  int tmp, tmp1, tmp2, sum = 0;
  for (int i = n; i >= 1; i--) {
    tmp = (F + i - ((sum + s[i]) % F)) % F;
    sum += tmp;
    printf("%d %d %d\n", 1, i, tmp);
  }
  printf("%d %d %d\n", 2, n, F);
  return 0;
}
