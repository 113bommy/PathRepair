#include <bits/stdc++.h>
using namespace std;
const int N = 300001;
int n;
long long a[N], s[N], tar, res = 0, K, ret, ans = 0;
int main() {
  scanf("%d%I64d", &n, &K);
  for (int i = 0; i <= n; i++) scanf("%I64d", &a[i]);
  for (int i = 0; i <= n + 50; i++) {
    s[i] += a[i];
    s[i + 1] += s[i] / 2;
    s[i] %= 2;
  }
  for (int i = 0; i <= n + 50; i++)
    if (s[i] != 0) {
      tar = i;
      break;
    }
  tar = min(tar, (long long)n);
  for (int i = n + 50; i > tar; i--) {
    res = res * 2 + s[i];
    if (res > K * 3 || res < -K * 3) {
      printf("0\n");
      return 0;
    }
  }
  for (int i = tar; i >= 0; i--) {
    res = res * 2 + s[i];
    if (res > K * 3 || res < -K * 3) break;
    ret = a[i] - res;
    if (-K <= ret && ret <= K && (!(i == n && ret == 0))) ans++;
  }
  cout << ans;
  return 0;
}
