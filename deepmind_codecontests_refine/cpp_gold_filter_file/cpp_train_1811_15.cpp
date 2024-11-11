#include <bits/stdc++.h>
using namespace std;
int n, m;
int ar[5003];
int ok[1000005];
int diff[1000005];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &ar[i]);
  sort(ar + 1, ar + n + 1);
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) diff[ar[j] - ar[i]]++;
  for (int ans = 1;; ans++) {
    int sum = 0;
    for (int i = ans; i < 1000005; i += ans) sum += diff[i];
    if (sum > m * (m + 1) / 2) continue;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (ok[ar[i] % ans] == ans) cnt++;
      ok[ar[i] % ans] = ans;
    }
    if (cnt <= m) {
      printf("%d\n", ans);
      break;
    }
  }
  return 0;
}
