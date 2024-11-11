#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int a[maxn];
int main() {
  int n, l, r, k, su, sk, s1, s2, x, i;
  scanf("%d %d %d %d %d %d", &n, &k, &l, &r, &su, &sk);
  for (i = l; i <= r; i++)
    if (i * k <= sk && i * (n - k) >= su - sk) break;
  x = i;
  s1 = x * k;
  s2 = x * (n - k);
  for (i = 1; i <= n; i++) a[i] = x;
  i = n;
  while (s1 < sk) {
    a[i]++;
    i--;
    s1++;
    if (i == n - k) i = n;
  }
  i = 1;
  while (k < n && s2 > su - sk) {
    a[i]--;
    i++;
    s2--;
    if (i == n - k + 1) i = 1;
  }
  for (i = 1; i <= n; i++) printf("%d ", a[i]);
  printf("\n");
  return 0;
}
