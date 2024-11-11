#include <bits/stdc++.h>
using namespace std;
char a[1000005], b[1000005];
int i, n, phi[1000005], phi2[1000005], k;
char inv(char c) {
  if (c == 'N') return 'S';
  if (c == 'S') return 'N';
  if (c == 'E') return 'W';
  if (c == 'V') return 'E';
}
int main() {
  scanf("%d\n", &n);
  --n;
  gets(a + 1);
  gets(b + 1);
  reverse(a + 1, a + n + 1);
  a[1] = inv(a[1]);
  for (i = 2; i <= n; ++i) {
    a[i] = inv(a[i]);
    k = phi[i - 1];
    while (k && a[i] != a[k + 1]) k = phi[k];
    if (a[i] == a[k + 1])
      phi[i] = k + 1;
    else
      phi[i] = 0;
  }
  for (i = 1; i <= n; ++i) {
    k = phi2[i - 1];
    while (k && b[i] != a[k + 1]) k = phi[k];
    if (b[i] == a[k + 1])
      phi2[i] = k + 1;
    else
      phi2[i] = 0;
  }
  if (phi2[n])
    printf("NO\n");
  else
    printf("YES\n");
  return 0;
}
