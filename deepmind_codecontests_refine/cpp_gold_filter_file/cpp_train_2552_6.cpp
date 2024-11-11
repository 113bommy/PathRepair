#include <bits/stdc++.h>
using namespace std;
int n;
int a[33];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a, a + n);
  int last = 1111111111;
  long long ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    int v = a[i];
    if (v >= last) v = last - 1;
    v = max(0, v);
    ans += v;
    last = v;
  }
  printf("%I64d\n", ans);
  return 0;
}
