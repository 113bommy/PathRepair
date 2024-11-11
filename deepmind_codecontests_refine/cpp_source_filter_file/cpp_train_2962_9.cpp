#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, i, n, m;
  float c, ans = 0;
  cin >> n >> m;
  int num[n + 1];
  for (i = 1; i <= n; i++) cin >> num[i];
  for (i = 0; i < m; i++) {
    cin >> a >> b >> c;
    ans = max(ans, (num[a] + num[b]) / c);
  }
  printf("%.14f\n", ans);
  return 0;
}
