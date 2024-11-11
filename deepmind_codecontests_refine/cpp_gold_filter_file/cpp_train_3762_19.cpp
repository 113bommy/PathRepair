#include <bits/stdc++.h>
using namespace std;
int n;
int a[400000];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + n + 1);
  long long s = 0;
  for (int i = 1; i <= n / 2; i++) {
    s = s + 1LL * (a[i] + a[n - i + 1]) * (a[i] + a[n - i + 1]);
  }
  printf("%I64d\n", s);
  return 0;
}
