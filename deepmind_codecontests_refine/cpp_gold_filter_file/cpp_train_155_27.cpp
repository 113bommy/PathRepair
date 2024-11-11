#include <bits/stdc++.h>
using namespace std;
int n, k, i, j, a, b, c, d;
bool mark[100002];
int main() {
  cin >> n >> k;
  cin >> a >> b >> c >> d;
  mark[a] = mark[b] = mark[c] = mark[d] = true;
  if (k < n - 1 + 2 && n > 4) {
    cout << -1 << endl;
    return 0;
  }
  if (n == 4) {
    cout << -1 << endl;
    return 0;
  }
  printf("%d %d ", a, c);
  for (i = 1; i <= n; i++) {
    if (mark[i]) continue;
    printf("%d ", i);
  }
  printf("%d %d\n", d, b);
  printf("%d %d ", c, a);
  for (i = 1; i <= n; i++) {
    if (mark[i]) continue;
    printf("%d ", i);
  }
  printf("%d %d\n", b, d);
  return 0;
}
