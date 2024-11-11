#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int t, n;
int a[N], s[100];
int check(int x) {
  int ans = 0;
  while (x) {
    ans++;
    x >>= 1;
  }
  return ans;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    memset(s, 0, sizeof s);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
      int x = check(a[i]);
      s[x]++;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) ans += (long long)s[i] * (s[i] - 1) / 2;
    printf("%lld\n", ans);
  }
  return 0;
}
