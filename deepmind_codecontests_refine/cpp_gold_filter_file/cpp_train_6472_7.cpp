#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 999;
int x, y, z;
int ori[3333][3333];
deque<int> q[3333];
int ans[3333][3333];
void solve() {
  int n, m, a, b;
  scanf("%d %d %d %d", &n, &m, &a, &b);
  int lastg;
  scanf("%d %d %d %d", &lastg, &x, &y, &z);
  ori[1][1] = lastg;
  for (int i = 1; i < 20000006; i++) {
    int nowg = ((1ll * lastg * x) % z + y) % z;
    int hang = i / m;
    int lie = i % m;
    if (hang + 1 > n) break;
    ori[hang + 1][lie + 1] = nowg;
    lastg = nowg;
  }
  for (int hang = 1; hang <= n; hang++) {
    for (int lie = 1; lie < b; lie++) {
      while (q[hang].size() && q[hang].back() > ori[hang][lie])
        q[hang].pop_back();
      q[hang].push_back(ori[hang][lie]);
    }
  }
  for (int hang = 1; hang <= n; hang++) {
    for (int lie = 1; lie + b - 1 <= m; lie++) {
      while (q[hang].size() && q[hang].back() > ori[hang][lie + b - 1])
        q[hang].pop_back();
      q[hang].push_back(ori[hang][lie + b - 1]);
      ans[hang][lie] = q[hang].front();
      if (ori[hang][lie] == q[hang].front()) q[hang].pop_front();
    }
  }
  long long res = 0;
  deque<int> nowq;
  for (int lie = 1; lie + b - 1 <= m; lie++) {
    while (!nowq.empty()) nowq.pop_back();
    for (int hang = 1; hang < a; hang++) {
      while (nowq.size() && nowq.back() > ans[hang][lie]) nowq.pop_back();
      nowq.push_back(ans[hang][lie]);
    }
    for (int hang = 1; hang + a - 1 <= n; hang++) {
      while (nowq.size() && nowq.back() > ans[hang + a - 1][lie])
        nowq.pop_back();
      nowq.push_back(ans[hang + a - 1][lie]);
      res += nowq.front();
      if (ans[hang][lie] == nowq.front()) nowq.pop_front();
    }
  }
  printf("%lld\n", res);
}
signed main() { solve(); }
