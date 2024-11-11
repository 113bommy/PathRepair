#include <bits/stdc++.h>
using namespace std;
int n;
int a[5050];
long long calc(int l, int r) {
  if (l > r) return 0;
  if (l == r) return a[l] > 0;
  int mi = 1000000007;
  long long ans = 0;
  for (int i = l; i <= r; i++) {
    mi = min(mi, a[i]);
  }
  int pos = l;
  for (int i = l; i <= r; i++) {
    if (a[i] == mi) {
      ans += calc(pos, i - 1);
      pos = i + 1;
    }
    a[i] -= mi;
  }
  if (pos <= r) {
    ans += calc(pos, r);
  }
  return min(1ll * (r - l + 1), ans + mi);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  printf("%lld\n", calc(1, n));
}
