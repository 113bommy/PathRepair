#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, k;
int a[1000005], maxx[1000005], minn[1000005];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= k; i++) {
    minn[i] = k + 1;
    maxx[i] = 0;
  }
  int mx = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    maxx[a[i]] = mx;
    mx = max(mx, a[i]);
  }
  int mi = k + 1;
  for (int i = n - 1; i >= 0; i--) {
    minn[a[i]] = mi;
    mi = min(mi, a[i]);
  }
  int s = 1;
  for (; s <= k; s++) {
    if (minn[s] < s) {
      break;
    }
  }
  int t = k;
  for (; t >= 2; t--) {
    if (maxx[t] > t) {
      break;
    }
  }
  long long ans = k - t + 1;
  for (int i = 1; i < s; i++) {
    t = max(t, maxx[i]);
    t = max(t, i + 1);
    ans += k - t + 1;
  }
  printf("%I64d\n", ans);
  return 0;
}
