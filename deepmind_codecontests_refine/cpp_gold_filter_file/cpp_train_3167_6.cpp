#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
map<int, int> mp;
map<int, int> mk;
int n, m, p, cnt, num;
int d[maxn];
int ans[maxn];
bool vis[maxn];
int cmp(int x, int y) { return x < y; }
void Init() {
  cnt = num = 0;
  mp.clear();
  mk.clear();
  memset(vis, false, sizeof(vis));
}
void Input() {
  scanf("%d%d%d", &n, &m, &p);
  for (int i = 1; i <= n; ++i) scanf("%d", &d[i]);
  for (int i = 1; i <= m; ++i) {
    int x;
    scanf("%d", &x);
    ++mk[x];
  }
}
void Solve() {
  int mx = n / p;
  for (int cc = 1; cc <= n; ++cc)
    if (!vis[cc]) {
      int tt = 1;
      int vv;
      num = 0;
      mp.clear();
      for (int i = cc; i <= n; i += p) {
        vis[i] = true;
        int uu = d[i];
        if (mk[uu]) {
          if (mp[uu] < mk[uu]) ++num;
          ++mp[uu];
        }
        if (tt < m) {
          ++tt;
        } else {
          int st = i - (m - 1) * p;
          vv = d[st];
          if (num == m) {
            ans[cnt++] = st;
          }
          if (mk[vv]) {
            if (mk[vv] >= mp[vv]) --num;
            --mp[vv];
          }
        }
      }
    }
}
void Output() {
  sort(ans, ans + cnt, cmp);
  printf("%d\n", cnt);
  for (int i = 0; i < cnt; ++i) printf("%d ", ans[i]);
  puts("");
}
int main() {
  Init();
  Input();
  Solve();
  Output();
  return 0;
}
