#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
const long long Mod = 998244353;
int a[maxn * maxn];
int b[maxn][maxn];
int c[maxn * maxn];
void upd(int id, int x) {
  while (x < maxn) {
    b[id][x]++;
    x += (x & (-x));
  }
}
int qry(int id, int x) {
  int sum = 0;
  while (x) {
    sum += b[id][x];
    x -= (x & (-x));
  }
  return sum;
}
vector<int> g[maxn * maxn];
int s[maxn * maxn];
struct node {
  int x, y, id;
} d[maxn * maxn];
bool cmp(node a, node b) {
  if (a.x == b.x) return a.y < b.y;
  return a.x > b.x;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int cnt = n * m;
    int j;
    for (int i = 0; i <= n; i++) {
      for (j = 0; j <= m; j++) {
        b[i][j] = 0;
      }
    }
    for (int i = 1; i <= cnt; i++) {
      cin >> a[i];
      c[i] = a[i];
    }
    sort(c + 1, c + cnt + 1);
    int tot = unique(c + 1, c + cnt + 1) - c - 1;
    for (int i = 1; i <= tot; i++) g[i].clear();
    for (int i = cnt; i >= 1; i--) {
      a[i] = lower_bound(c + 1, c + tot + 1, a[i]) - c;
      g[a[i]].push_back(i);
    }
    int now = 0;
    int L = 1, R;
    for (int i = 1; i <= tot; i++) {
      R = L + g[i].size() - 1;
      now = 0;
      for (j = L; j <= R; j++) {
        now++;
        d[now].id = j;
        d[now].x = (j - 1) / m + 1;
        d[now].y = (j - 1) % m + 1;
      }
      sort(d + 1, d + now + 1, cmp);
      now = 0;
      for (int v : g[i]) {
        now++;
        s[v] = d[now].id;
      }
      L = R + 1;
    }
    long long ans = 0;
    int x, y, id;
    for (int i = 1; i <= cnt; i++) {
      id = s[i];
      x = (id - 1) / m + 1;
      y = (id - 1) % m + 1;
      ans = ans + 1ll * qry(x, y);
      upd(x, y);
    }
    cout << ans << endl;
  }
  return 0;
}
