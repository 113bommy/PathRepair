#include <bits/stdc++.h>
using namespace std;
const int nax = 5e5 + 100;
int T, n, p[nax], gdzie[nax];
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", p + i);
    gdzie[p[i]] = i;
  }
  int last = -1;
  int mini = n + 1;
  for (int i = 1; i <= n; ++i) {
    int x = gdzie[i];
    if (x < mini && x == n - i + 1) {
      mini = min(mini, x);
      last = x;
    } else if (x != last + 1 && last < x) {
      printf("No\n");
      return;
    }
    mini = min(mini, x);
    last = x;
  }
  printf("Yes\n");
}
int main() {
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
