#include <bits/stdc++.h>
using namespace std;
const int N = 1000004, P = 1000000007;
int n, a;
long long f[N];
int main() {
  int i;
  scanf("%d", &n);
  for (a = 0, i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    if (x == 1) a++;
  }
  long long ans = 1;
  for (i = n; i > a; i--) ans = ans * i % P;
  f[1] = 1;
  f[2] = 2;
  for (i = 3; i <= a; i++) f[i] = (f[i - 1] + f[i - 2] * (i - 1)) % P;
  printf("%d\n", ans * f[a] % P);
  return 0;
}
