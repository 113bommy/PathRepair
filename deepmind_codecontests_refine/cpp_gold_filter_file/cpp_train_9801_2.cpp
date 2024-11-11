#include <bits/stdc++.h>
using namespace std;
const int N = 1000000;
const int inf = 0x3f3f3f3f;
int a[300005];
int main() {
  int n;
  scanf("%d", &n);
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  sort(a + 1, a + n + 1);
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int b;
    scanf("%d", &b);
    long long ans = sum;
    ans -= a[n - b + 1];
    printf("%lld\n", ans);
  }
  return 0;
}
