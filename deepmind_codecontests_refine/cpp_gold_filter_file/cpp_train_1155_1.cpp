#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a[1001];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  long long ans = 0;
  int t = 0;
  for (int i = 0; i < n; i++) {
    ans += a[i] + (a[i] - 1) * t;
    t++;
  }
  printf("%I64d", ans);
  return 0;
}
