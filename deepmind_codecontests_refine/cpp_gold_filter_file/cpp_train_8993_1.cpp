#include <bits/stdc++.h>
using namespace std;
int n, a[1005], l[5], r[5];
void dfs(int x) {
  bool sorted = 1;
  for (int i = 1; i <= n; i++)
    if (!(sorted &= (a[i] == i))) break;
  if (sorted) {
    cout << x << endl;
    for (int i = x - 1; ~i; i--) cout << l[i] << ' ' << r[i] << endl;
    exit(0);
  }
  if (x > 2) return;
  for (int i = 1; i <= n; i++) {
    if (a[i] == i || (abs(a[i] - a[i - 1]) == 1 && abs(a[i + 1] - a[i]) == 1))
      continue;
    for (int j = i + 1; j <= n; j++) {
      if (a[j] == j || (abs(a[j] - a[j - 1]) == 1 && abs(a[j + 1] - a[j]) == 1))
        continue;
      l[x] = i;
      r[x] = j;
      reverse(a + i, a + j + 1);
      dfs(x + 1);
      reverse(a + i, a + j + 1);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  a[n + 1] = n + 1;
  dfs(0);
  return 0;
}
