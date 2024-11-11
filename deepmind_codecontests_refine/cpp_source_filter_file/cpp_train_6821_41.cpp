#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
int tp, n, i, j, m, x, y, k;
pair<int, int> a[5050], b[5050];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", &tp, &x, &y);
    if (tp == 1)
      a[x] = make_pair(i, y);
    else
      b[x] = make_pair(i, y);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      pair<int, int> T = max(a[i], b[j]);
      printf("%d ", T.second);
    }
    puts("");
  }
  return 0;
}
