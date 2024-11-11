#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
int d[30002];
int ans[30002];
int num;
map<int, bool> f;
priority_queue<pair<int, int> > q;
inline bool jud(int l, int n) { return l >= 0 && l + 1 <= n; }
bool ok() {
  int i;
  for (i = 0; i < num - 1; i++) {
    bool g = 1;
    if (jud(i - 1, num - 1) && f[ans[i - 1] * 30001 + ans[num - 1]]) g = 0;
    if (jud(i + 1, num - 1) && f[ans[num - 1] * 30001 + ans[i + 1]]) g = 0;
    if (jud(num - 2, num - 1) && f[ans[num - 2] * 30001 + ans[i]]) g = 0;
    if (g) {
      swap(ans[num - 1], ans[i]);
      return 1;
    }
  }
  return 0;
}
int main() {
  int n, m, x, y, k, i, j;
  cin >> n >> m;
  for (i = 0; i < m; i++) {
    scanf("%d%d", &x, &y);
    d[x]++;
    f[x * 30001 + y] = true;
  }
  for (i = 1; i <= n; i++) {
    q.push(make_pair(-d[i], i));
  }
  while (!q.empty()) {
    pair<int, int> tp = q.top();
    x = tp.first;
    y = tp.second;
    q.pop();
    ans[num++] = y;
    if (num == 1) continue;
    if (f[ans[num - 2] * 30001 + y]) {
      if (!ok()) {
        x--;
        num--;
        q.push(make_pair(x, y));
      }
    }
  }
  for (i = 0; i < n; i++) printf("%d ", ans[i]);
  return 0;
}
