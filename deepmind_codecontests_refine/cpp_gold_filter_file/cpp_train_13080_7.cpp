#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200001];
int s, f;
long long d[200001];
int main() {
  scanf("%d", &n);
  a[0] = 0;
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = n + 1; i <= 2 * n; i++) a[i] = a[i - n];
  scanf("%d %d", &s, &f);
  for (int i = 1; i <= 2 * n; i++) {
    d[i] = d[i - 1] + a[i];
  }
  int m_i = 0;
  long long max = 0;
  for (int i = 1; i <= n; i++) {
    long long tmp = d[i + f] - d[i + s];
    if (max <= tmp) {
      max = tmp;
      m_i = i;
    }
  }
  int ans = n - m_i;
  ans %= n;
  if (ans <= 0) ans += n;
  printf("%d\n", ans);
  return 0;
}
