#include <bits/stdc++.h>
using namespace std;
int n, p, a[100100];
long long s[100100];
int main() {
  scanf("%d%d", &n, &p);
  s[0] = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    s[i] = s[i - 1] + a[i];
  }
  int ans = 0;
  for (int i = 1; i < n; i++)
    if ((s[i] % p + (s[n] - s[i]) % p) > ans)
      ans = s[i] % p + (s[n] - s[i]) % p;
  printf("%d", ans);
  return 0;
}
