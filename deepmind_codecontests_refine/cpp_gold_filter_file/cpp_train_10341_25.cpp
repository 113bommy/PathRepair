#include <bits/stdc++.h>
using namespace std;
long long p = 1000000009;
long long ans = 0;
long long a[2000001];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) a[i] = 1;
  for (int i = 4; i <= n; i += 2) a[i] = ((a[i - 2] + 3) * 2 - 3) % p;
  if (n % 2 == 1) a[n] = n;
  for (int i = n; i >= 2; i--) ans = (ans * a[i]) % p + 2;
  printf("%I64d\n", (ans * ans * 2 + 2) % p);
  return 0;
}
