#include <bits/stdc++.h>
using namespace std;
int cp[1000010], n;
int dfs(int first) {
  int second = 0;
  for (int i = 1;; i++)
    if ((1 << i) - 1 >= first) {
      return (1 << i) - 1 ^ first;
    }
}
int main() {
  scanf("%d", &n);
  for (int i = n; i >= 1; i--)
    if (!cp[i]) {
      cp[i] = dfs(i);
      cp[cp[i]] = i;
    }
  long long ans = 0;
  for (int i = n; i >= 1; i--) {
    ans += i ^ cp[i];
  }
  cout << ans << endl;
  for (int i = 0; i <= n; i++) {
    printf("%d ", cp[i]);
  }
  return 0;
}
