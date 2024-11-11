#include <bits/stdc++.h>
using namespace std;
const static int inf = 0x3f3f3f3f;
const static long long INF = 0x3f3f3f3f3f3f3f3f;
const static int maxn = 2000005;
struct node {
  int x, y;
  node() {}
  node(int _x, int _y) : x(_x), y(_y) {}
  bool operator<(const node &a) const {
    if (x == a.x) return y < a.y;
    return x < a.x;
  }
} rb[maxn], lt[maxn];
int cnt;
int n, m;
vector<int> v[maxn];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> rb[i].x >> rb[i].y;
  for (int i = 1; i <= m; i++) cin >> lt[i].x >> lt[i].y;
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      mx = max(mx, lt[j].x - rb[i].x);
      if (lt[j].x >= rb[i].x)
        v[lt[j].x - rb[i].x].push_back(lt[j].y - rb[i].y + 1);
    }
  }
  int ans = inf, now = 0;
  for (int i = mx + 1; i >= 0; i--) {
    for (int j = 0; j < (int)v[i].size(); j++) now = max(now, v[i][j]);
    ans = min(ans, now + i);
  }
  cout << ans << endl;
  return 0;
}
