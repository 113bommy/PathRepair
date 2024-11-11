#include <bits/stdc++.h>
using namespace std;
long long n, m, l, r;
long long a[100009], h[100009], s[100009], top;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  scanf("%lld%lld", &n, &m);
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  for (long long i = 1; i < n; i++) {
    h[i] = abs(a[i + 1] - a[i]);
  }
  for (long long i = 1ll; i <= m; i++) {
    scanf("%lld%lld", &l, &r);
    top = 0;
    s[0] = l - 1;
    long long tmp = h[r];
    long long ans = 0;
    h[r] = 1e9;
    for (long long j = l; j <= r; j++) {
      while (top && h[j] >= h[s[top]]) {
        ans += (s[top] - s[top - 1]) * (j - s[top]) * h[s[top]];
        top--;
      }
      s[top++] = j;
    }
    h[r] = tmp;
    printf("%lld\n", ans);
  }
  return 0;
}
