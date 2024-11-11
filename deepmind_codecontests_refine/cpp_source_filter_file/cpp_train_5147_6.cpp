#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  if (2 * k != n - 1) {
    printf("-1");
    return;
  }
  printf("%d\n", k * n);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1, l = 0; l < k; l++, j++) {
      printf("%d %d\n", i + 1, (j % n) + 1);
    }
  }
}
int main() {
  int t = 1;
  while (t) {
    t--;
    solve();
  }
}
