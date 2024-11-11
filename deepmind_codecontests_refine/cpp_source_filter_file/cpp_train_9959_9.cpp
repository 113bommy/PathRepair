#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, w, arr[1005], minn = 1e9, maxn = -1e9, use = 0;
  scanf("%d %d", &n, &w);
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  for (int i = 0; i < n; i++) {
    use += arr[i];
    minn = min(minn, use);
    maxn = max(maxn, use);
  }
  maxn = w - maxn;
  minn = minn < 0 ? -minn : 0;
  printf("%d\n", max(0, maxn - minn + 1));
  return 0;
}
