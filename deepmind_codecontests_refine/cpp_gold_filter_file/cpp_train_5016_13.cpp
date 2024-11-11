#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e6 + 555;
int p[maxn];
int ppos[maxn];
int q[maxn];
int qpos[maxn];
char ans[maxn];
void solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &p[i]);
    ppos[p[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &q[i]);
    qpos[q[i]] = i;
  }
  vector<pair<int, int> > v;
  int L = 1;
  int r = 1;
  for (int i = 1; i <= n; i++) {
    r = max(r, qpos[p[i]]);
    r = max(r, ppos[q[i]]);
    if (r == i) {
      v.push_back(make_pair(L, r));
      L = i + 1;
      r = i + 1;
    }
  }
  if (int(v.size()) < m)
    puts("NO");
  else {
    for (int i = 0; i < v.size(); i++) {
      for (int j = v[i].first; j <= v[i].second; j++) {
        ans[p[j]] = min((int)'z', 'a' + i);
      }
    }
    puts("YES");
    for (int i = 1; i <= n; i++) printf("%c", ans[i]);
  }
}
signed main() { solve(); }
