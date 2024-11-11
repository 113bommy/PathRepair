#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
struct Pair {
  int cost, num, kind;
  Pair(int a = 0, int c = 0) {
    cost = a;
    kind = c;
  }
};
bool operator>(const Pair& a, const Pair& b) { return a.cost > b.cost; }
priority_queue<Pair, vector<Pair>, greater<Pair> > que;
int r[100010], c[100010];
int main() {
  int T = 1;
  while (T--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) scanf("%d", r + i);
    for (int i = 1; i <= n; i++) scanf("%d", c + i);
    for (int i = 1; i <= n; i++) que.push(Pair(c[i], i));
    vector<long long int> ans;
    int x, y, Min;
    long long money;
    for (int t = 0; t < m; t++) {
      money = 0;
      scanf("%d %d", &x, &y);
      Min = min(r[x], y);
      money = (long long)(Min)*c[x];
      r[x] -= Min;
      y -= Min;
      while (que.size() && y > 0) {
        Pair p = que.top();
        if (r[p.kind] == 0) {
          que.pop();
          continue;
        }
        Min = min(r[p.kind], y);
        money += c[p.kind] * (long long)(Min);
        y -= Min;
        r[p.kind] -= Min;
      }
      if (y > 0) {
        money = 0;
        break;
      }
      ans.push_back(money);
    }
    while (ans.size() < m) ans.push_back(0);
    for (int i = 0; i < ans.size(); i++) printf("%lld\n", ans[i]);
  }
}
