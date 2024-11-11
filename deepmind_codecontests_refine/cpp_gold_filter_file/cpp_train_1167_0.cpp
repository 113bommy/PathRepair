#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
void FAST() {
  ios::sync_with_stdio(false);
  cin.tie(0);
}
struct po {
  int x, y;
  void input() { scanf("%d%d", &x, &y); }
} p[1010];
bool cmp(po a, po b) {
  if (a.x == b.x)
    return a.y < b.y;
  else
    return a.x < b.x;
}
int ans[N][2];
void solve() {
  int n;
  cin >> n;
  memset(ans, 0, sizeof(ans));
  for (int i = 1; i <= n; ++i) p[i].input();
  p[0].x = p[0].y = 0;
  sort(p, p + n + 1, cmp);
  bool ok = true;
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    int u = p[i].y - p[i - 1].y;
    int r = p[i].x - p[i - 1].x;
    if (u < 0 || r < 0) {
      ok = false;
      break;
    }
    ans[cnt][0] = u;
    ans[cnt++][1] = r;
  }
  if (ok) {
    puts("YES");
    for (int i = 0; i < cnt; ++i) {
      for (int j = 0; j < ans[i][1]; ++j) printf("R");
      for (int j = 0; j < ans[i][0]; ++j) printf("U");
    }
    puts("");
  } else
    puts("NO");
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
