#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
const int p = 1e9 + 7;
int n, m;
int x[maxn], y[maxn];
struct abc {
  int i, d;
} d[maxn];
bool operator<(abc a, abc b) { return a.d < b.d; }
vector<int> v[maxn];
int visd[maxn], visf[maxn];
int k[maxn], fg[maxn], tot, ans[maxn], na;
int a[maxn], b[maxn];
priority_queue<abc> q;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &x[i], &y[i]);
    b[x[i]]++, b[y[i]]++;
    v[x[i]].push_back(i);
    v[y[i]].push_back(i);
  }
  for (int i = 1; i <= n; ++i) {
    d[i].d = a[i] - b[i];
    d[i].i = i;
    q.push(d[i]);
  }
  while (!q.empty()) {
    abc w = q.top();
    q.pop();
    if (visd[w.i]) continue;
    visd[w.i] = 1;
    int len = v[w.i].size();
    for (int i = 0; i < len; ++i) {
      int r = v[w.i][i];
      if (!visf[r]) {
        ans[++na] = r;
        visf[r] = 1;
        if (x[r] == w.i) {
          b[y[r]]--;
          q.push({y[r], a[y[r]] - b[y[r]]});
        } else {
          b[x[r]]--;
          q.push({x[r], a[x[r]] - b[x[r]]});
        }
      }
    }
  }
  for (int i = na; i >= 1; --i) {
    int cnt = 0;
    if (a[x[ans[i]]]) a[x[ans[i]]]--, cnt = 1;
    if (a[y[ans[i]]]) a[y[ans[i]]]--, cnt = 1;
    if (!cnt) {
      puts("DEAD");
      return 0;
    }
  }
  puts("ALIVE");
  for (int i = na; i >= 1; --i) printf("%d ", ans[i]);
  return 0;
}
