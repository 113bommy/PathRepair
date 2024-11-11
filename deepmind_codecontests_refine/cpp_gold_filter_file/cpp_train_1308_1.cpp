#include <bits/stdc++.h>
int v[200], fr[200];
bool viz[200];
int gcd(int a, int b) {
  int r;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &v[i]);
    fr[v[i]]++;
  }
  bool ok = 1;
  for (int i = 1; i <= n; i++)
    if (fr[i] != 1) ok = 0;
  if (!ok)
    printf("-1\n");
  else {
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
      if (!viz[i]) {
        int x = i, s = 0;
        do {
          viz[x] = 1;
          s++;
          x = v[x];
        } while (x != i);
        if (s % 2 == 0) s /= 2;
        ans = ans * s / gcd(ans, s);
      }
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
