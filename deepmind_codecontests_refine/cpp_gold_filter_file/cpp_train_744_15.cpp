#include <bits/stdc++.h>
using namespace std;
int n;
int a[210];
bool dfs(int sum, int k) {
  if (sum == 1) return true;
  if (k + 1 <= n && a[k + 1] == sum - 1) {
    sum--;
    dfs(sum, k + 1);
  } else if (k - 1 >= 1 && a[k - 1] == sum - 1) {
    sum--;
    dfs(sum, k - 1);
  } else if (k == n && a[1] == sum - 1) {
    sum--;
    dfs(sum, 1);
  } else if (k == 1 && a[n] == sum - 1) {
    sum--;
    dfs(sum, n);
  } else
    return false;
}
int main() {
  int q;
  cin >> q;
  while (q--) {
    cin >> n;
    int k = 0, k1 = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] == n) k = i;
      if (a[i] == 1) k1 = i;
    }
    if (k == 0 || k1 == 0) {
      puts("NO");
      continue;
    }
    if (dfs(n, k))
      puts("YES");
    else if (dfs(n, k1))
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
