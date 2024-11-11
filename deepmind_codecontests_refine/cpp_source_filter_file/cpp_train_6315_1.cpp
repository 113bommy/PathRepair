#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const double PI = acos(-1);
const double eps = 1e-6;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;
int n, m;
struct ppo {
  int s, d, c;
} a[110];
int ans[110];
int ed[110];
vector<int> q;
int cmp(int x, int y) { return a[x].d < a[y].d; }
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i].s >> a[i].d >> a[i].c;
    ed[a[i].d] = i;
  }
  for (int i = 1; i <= n; i++) {
    if (ed[i] != 0) {
      if (a[ed[i]].c != 0) {
        cout << -1 << endl;
        return 0;
      }
      ans[i] = m + 1;
      continue;
    }
    q.clear();
    for (int j = 1; j <= m; j++) {
      if (a[j].s <= i && i < a[j].d && a[j].c > 0) {
        q.push_back(j);
      }
    }
    sort(q.begin(), q.end());
    if (q.size() == 0) {
      ans[i] = 0;
    } else {
      int t = *q.begin();
      a[t].c--;
      ans[i] = t;
    }
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
  return 0;
}
