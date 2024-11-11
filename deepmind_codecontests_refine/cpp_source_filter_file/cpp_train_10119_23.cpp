#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
const long double eps = 1e-4;
const int MAXE = 1000020;
const int INF = 0x3f3f3f3f;
const double pi = 2 * asin(1);
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
inline int dcmp(double x) {
  if (fabs(x) < eps)
    return 0;
  else
    return x < 0 ? -1 : 1;
}
struct node {
  string s;
} nd[10];
int n, m;
int ans;
bool vis[10];
int order[10];
void find() {
  int minn = 999999999, maxx = -1;
  int num[10];
  for (int i = 0; i < n; i++) {
    int tmp = 0;
    for (int j = 0; j < m; j++) {
      tmp = tmp * 10 + (nd[i].s[order[j]] - '0');
    }
    maxx = max(maxx, tmp);
    minn = min(minn, tmp);
  }
  ans = min(ans, maxx - minn);
}
void dfs(int k) {
  if (k == m) {
    find();
  }
  for (int i = 0; i < m; i++) {
    if (vis[i]) continue;
    order[k] = i;
    vis[i] = 1;
    dfs(k + 1);
    vis[i] = 0;
  }
}
int main(void) {
  while (cin >> n >> m) {
    ans = 0x3f3f3f;
    memset(vis, 0, sizeof(vis));
    memset(order, 0, sizeof(order));
    for (int i = 0; i < n; i++) cin >> nd[i].s;
    dfs(0);
    cout << ans << endl;
  }
}
