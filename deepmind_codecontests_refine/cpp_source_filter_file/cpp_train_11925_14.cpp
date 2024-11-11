#include <bits/stdc++.h>
using namespace std;
int a[10];
int check(int x, int y, int n, int m) {
  memset(a, 0, sizeof a);
  if (!x) a[0]++;
  if (!y) a[0]++;
  while (n) {
    a[x % 7]++;
    x /= 7;
    n /= 7;
  }
  while (m) {
    a[y % 7]++;
    y /= 7;
    m /= 7;
  }
  for (int i = 0; i < 7; i++)
    if (a[i] > 1) return 0;
  return 1;
}
int ans = 0;
int main() {
  int n, m;
  cin >> n >> m;
  if (1ll * n * m > 1e7) {
    puts("0");
    return 0;
  }
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < m; y++) {
      ans += check(x, y, n - 1, m - 1);
    }
  }
  cout << ans << endl;
}
