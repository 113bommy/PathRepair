#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, base, f[N];
int main() {
  scanf("%d", &n);
  for (base = 1; base < n; base <<= 1)
    ;
  for (int i = 1; i <= n; i++) f[i] = n + 1;
  for (int i = 1; i <= n; i++) {
    int a;
    scanf("%d", &a);
    int j = lower_bound(f, f + n + 1, a) - f;
    if (a < f[j + 1]) f[j + 1] = a;
  }
  int ans = n;
  while (f[ans] == n + 1) ans--;
  printf("%d\n", ans);
}
