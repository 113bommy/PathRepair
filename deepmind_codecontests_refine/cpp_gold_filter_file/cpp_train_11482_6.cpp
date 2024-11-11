#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
char s[N];
int a[N];
int n;
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  int x = 1, y = 0;
  for (int i = 2; i <= n; i++) {
    if (a[i] != a[1]) y = i;
  }
  if (y == 0) {
    printf("NO\n");
    return;
  }
  printf("YES\n");
  for (int i = 2; i <= n; i++) {
    if (i == x || i == y) continue;
    if (a[i] == a[x])
      printf("%d %d\n", y, i);
    else
      printf("%d %d\n", x, i);
  }
  printf("%d %d\n", x, y);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
