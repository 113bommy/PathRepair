#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 * 100 + 5;
int r[MAXN], l[MAXN], a[MAXN], n;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    r[i] = max(sum + (-1 * a[i]), a[i] + r[i - 1]);
    sum += -1 * a[i];
  }
  sum = 0;
  for (int i = n; i >= 1; i--) {
    l[i] = max(sum + (-1 * a[i]), a[i] + l[i + 1]);
    sum += -1 * a[i];
  }
  int ans = -1 * int(1e9) + 5;
  for (int i = 1; i < n; i++) {
    ans = max(ans, r[i] + l[i + 1]);
  }
  cout << ans;
  return 0;
}
