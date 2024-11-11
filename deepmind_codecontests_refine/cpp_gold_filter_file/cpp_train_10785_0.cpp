#include <bits/stdc++.h>
using namespace std;
int n, k, p;
long long ans = 1ll << 60;
int a[1005], b[2005];
int main() {
  cin >> n >> k >> p;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= k; i++) {
    scanf("%d", &b[i]);
  }
  sort(a + 1, a + n + 1);
  sort(b + 1, b + k + 1);
  for (int i = 1; i <= k - n + 1; i++) {
    long long tmp = 0;
    for (int j = 0; j < n; j++)
      tmp = max((long long)abs(b[i + j] - p) + abs(b[i + j] - a[j + 1]), tmp);
    ans = min(tmp, ans);
  }
  cout << ans;
  return 0;
}
