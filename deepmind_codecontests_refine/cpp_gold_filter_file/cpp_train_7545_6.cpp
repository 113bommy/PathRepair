#include <bits/stdc++.h>
using namespace std;
template <class T>
T sqr(T x) {
  return x * x;
}
const int maxn = 100001;
int k, n, m, x, y, d[maxn], c[maxn], visit[maxn], a[maxn];
double r[maxn];
pair<int, int> edge[maxn];
vector<int> g[maxn], anslist;
bool check(double k) {
  queue<int> q;
  int cnt = 0;
  for (int i = 1; i <= n; i++) visit[i] = a[i];
  memset(c, 0, sizeof(c));
  for (int i = 1; i <= m; i++) {
    if (!a[edge[i].first]) c[edge[i].second]++;
    if (!a[edge[i].second]) c[edge[i].first]++;
  }
  for (int i = 1; i <= n; i++) {
    r[i] = c[i] * 1.0 / d[i];
    if (!visit[i] && r[i] < k) {
      q.push(i);
      visit[i] = 1;
    }
  }
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = 0; i < g[x].size(); i++)
      if (!visit[g[x][i]]) {
        int y = g[x][i];
        c[y]--;
        r[y] = c[y] * 1.0 / d[y];
        if (r[y] < k) {
          q.push(y);
          visit[y]++;
        }
      }
  }
  for (int i = 1; i <= n; i++)
    if (!visit[i]) return 1;
  return 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= k; i++) {
    scanf("%d", &x);
    a[x] = 1;
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
    edge[i] = pair<int, int>(x, y);
    d[x]++;
    d[y]++;
  }
  double lefts = 0, rights = 1;
  double ans = 0;
  while (rights - lefts > 1e-12) {
    double mid = (lefts + rights) * 0.5;
    if (check(mid))
      ans = mid, lefts = mid;
    else
      rights = mid;
  }
  check(ans);
  for (int i = 1; i <= n; i++)
    if (!visit[i]) anslist.push_back(i);
  printf("%d\n", anslist.size());
  for (int i = 0; i < anslist.size(); i++) printf("%d ", anslist[i]);
  fclose(stdin);
  return 0;
}
