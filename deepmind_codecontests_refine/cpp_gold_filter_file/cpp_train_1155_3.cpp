#include <bits/stdc++.h>
using namespace std;
long long a[110];
int main() {
  int n, i;
  long long s, v;
  for (s = 0, scanf("%d", &n), i = 0; i < n; scanf("%I64d", &a[i]), i++)
    ;
  for (s = 0, v = 1, i = n - 1; i >= 0; s += v + a[i] - 1, v += a[i] - 1, i--)
    ;
  printf("%I64d\n", s);
  return 0;
}
