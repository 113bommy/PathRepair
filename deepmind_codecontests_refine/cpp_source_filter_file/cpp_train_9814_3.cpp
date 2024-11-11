#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int N = 5005;
long long a[N], b[N];
long long f[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    b[i] = a[i];
  }
  sort(b + 1, b + 1 + n);
  long long ans = INF;
  for (int i = 1; i <= n; i++) {
    long long t = INF;
    for (int j = 1; j <= n; j++) {
      t = min(t, f[j]);
      f[j] = t + abs(a[i] - b[j]);
    }
  }
  for (int i = 1; i <= n; i++) {
    ans = min(ans, f[i]);
  }
  printf("%lld\n", ans);
  return 0;
}
