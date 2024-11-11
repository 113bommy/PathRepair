#include <bits/stdc++.h>
using namespace std;
constexpr int N = 100005;
int arr[N];
int suffix_mn[N];
int prefix_mn[N];
int main(void) {
  int n, k;
  scanf("%d%d", &n, &k);
  int mn = 1e9 + 7;
  int mx = -1e9 - 7;
  suffix_mn[0] = 1e9 + 7;
  suffix_mn[n + 1] = 1e9 + 7;
  for (int i = 1; i <= n; i++) {
    scanf("%d", arr + i);
    mx = max(mx, arr[i]);
    mn = min(mn, arr[i]);
  }
  for (int i = 1; i <= n; i++) {
    prefix_mn[i] = min(prefix_mn[i - 1], arr[i]);
  }
  for (int i = n; i >= 1; i--) {
    suffix_mn[i] = min(suffix_mn[i + 1], arr[i]);
  }
  int ans = -1e9 - 7;
  for (int i = 1; i < n; i++) {
    ans = max(ans, max(prefix_mn[i], suffix_mn[i + 1]));
  }
  if (k == 1) {
    printf("%d\n", mn);
  } else if (k == 2) {
    printf("%d\n", ans);
  } else if (k == 3) {
    printf("%d\n", mx);
  }
  return 0;
}
