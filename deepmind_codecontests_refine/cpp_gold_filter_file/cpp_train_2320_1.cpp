#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
long long a[maxn], b[maxn], n;
long long t[maxn][7];
struct Node {
  long long c;
  int id;
} x[maxn * 5];
bool cmp(Node y, Node z) { return y.c < z.c; }
int m;
int vis[maxn];
int main() {
  for (int i = 1; i <= 6; i++) cin >> a[i];
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> b[i];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= 6; j++) t[i][j] = b[i] - a[j];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 6; j++) {
      m++;
      x[m].c = t[i][j];
      x[m].id = i;
    }
  }
  sort(x + 1, x + m + 1, cmp);
  long long ans = 1ll << 61;
  int cnt = 0;
  int l = 1, r = 0;
  for (l = 1; l <= m; l++) {
    if (l > 1) {
      vis[x[l - 1].id]--;
      if (vis[x[l - 1].id] == 0) cnt--;
    }
    while (1) {
      if (r == m) break;
      if (cnt == n) break;
      r++;
      if (vis[x[r].id] == 0) cnt++;
      vis[x[r].id]++;
    }
    if (cnt != n) break;
    ans = min(ans, x[r].c - x[l].c);
  }
  cout << ans << endl;
  return 0;
}
