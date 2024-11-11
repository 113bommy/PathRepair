#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
  int n;
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    long long s1 = 0, s2 = 0;
    for (int i = 1; i <= n / 2; i++) s1 += a[i];
    for (int i = n / 2 + 1; i <= n; i++) s2 += a[i];
    long long p = s1 * s1 + s2 * s2;
    printf("%lld\n", p);
  }
  return 0;
}
