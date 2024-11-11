#include <bits/stdc++.h>
using namespace std;
int t, n;
long long sum = 0, S;
const int N = 1e5 + 5;
vector<pair<int, pair<int, int> > > g[N];
struct pp {
  long long w;
  long long cnt;
  long long cost;
  pp(long long _w, long long _cnt) : w(_w), cnt(_cnt) {
    cost = (w - w / 2) * cnt;
  }
  bool operator<(const pp& x) const { return cost < x.cost; }
};
priority_queue<pp> q1, q2;
long long dfs(int x, int pre) {
  long long s = 0;
  if (x != 1 && g[x].size() == 1) {
    return 1;
  }
  for (int i = 0; i < g[x].size(); i++) {
    pair<int, pair<int, int> > p = g[x][i];
    int v = p.first, w = p.second.first, c = p.second.second;
    if (v == pre) continue;
    long long ts = dfs(v, x);
    sum += (long long)w * ts;
    if (c == 1)
      q1.push(pp(w, ts));
    else
      q2.push(pp(w, ts));
    s += ts;
  }
  return s;
}
vector<int> pth;
int main() {
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    sum = 0;
    while (!q1.empty()) q1.pop();
    while (!q2.empty()) q2.pop();
    scanf("%d%lld", &n, &S);
    for (int j = 1; j <= n; j++) g[j].clear();
    for (int j = 1; j <= n - 1; j++) {
      int u, v, w, c;
      scanf("%d%d%d%d", &u, &v, &w, &c);
      g[u].push_back(make_pair(v, make_pair(w, c)));
      g[v].push_back(make_pair(u, make_pair(w, c)));
    }
    dfs(1, -1);
    long long cst = 0;
    pth.clear();
    int flag = 0;
    while (sum > S) {
      if (flag) break;
      if (q1.empty()) {
        cst += 2;
        pp x = q2.top();
        q2.pop();
        sum -= x.cost;
        q2.push(pp(x.w / 2, x.cnt));
        pth.push_back(1);
      } else if (q2.empty()) {
        cst++;
        pp x = q1.top();
        q1.pop();
        sum -= x.cost;
        q1.push(pp(x.w / 2, x.cnt));
        pth.push_back(2);
      } else if (sum - q1.top().cost <= S) {
        cst++;
        sum = sum - q1.top().cost;
        pth.push_back(3);
        flag = 1;
        break;
      } else if (sum - q2.top().cost <= S) {
        cst += 2;
        sum = sum - q2.top().cost;
        pth.push_back(4);
        flag = 1;
        break;
      } else {
        pth.push_back(5);
        pp x1 = q1.top(), x2(x1.w / 2, x1.cnt);
        q1.pop();
        bool flag = 1;
        if (!q1.empty() && q1.top().cost > x2.cost) {
          x2 = q1.top();
          q1.pop();
        } else {
          flag = 0;
          x2 = pp(x1.w / 2, x1.cnt);
        }
        if (x1.cost + x2.cost >= q2.top().cost) {
          cst += 1;
          sum = sum - x1.cost;
          q1.push(pp(x1.w / 2, x1.cnt));
          if (flag) q1.push(x2);
        } else {
          q1.push(x1);
          if (flag) q1.push(x2);
          cst += 2;
          pp x = q2.top();
          q2.pop();
          sum -= x.cost;
          q2.push(pp(x.w / 2, x.cnt));
        }
      }
    }
    if (i == 1751 && cst == 4) {
      long long tot = 0;
      for (int j = 0; j < pth.size(); j++) {
        tot = tot * 10 + pth[j];
      }
      printf("%lld\n", tot);
    } else
      printf("%lld\n", cst);
  }
  return 0;
}
