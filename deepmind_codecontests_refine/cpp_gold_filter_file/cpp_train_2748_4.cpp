#include <bits/stdc++.h>
using namespace std;
bool gr[1005], gc[1005];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) gr[i] = gc[i] = 1;
  int x, y;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    gc[y] = 0;
    gr[x] = 0;
  }
  int ans = 0;
  int rc = 0, cc = 0;
  for (int i = 2; i <= n / 2; i++) {
    rc = gr[i] + gr[n - i + 1];
    cc = gc[i] + gc[n - i + 1];
    ans += min(rc + cc, 4);
  }
  if (n % 2 == 1) {
    if (gr[n / 2 + 1] || gc[n / 2 + 1]) ans++;
  }
  cout << ans << endl;
}
