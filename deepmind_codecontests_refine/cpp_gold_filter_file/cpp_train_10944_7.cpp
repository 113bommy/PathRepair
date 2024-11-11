#include <bits/stdc++.h>
using namespace std;
struct Event {
  int d, w, t;
};
struct T {
  bool operator()(const Event &e1, const Event &e2) const {
    return e1.w > e2.w || (e1.w == e2.w && e1.d > e2.d);
  }
};
long long dp[100005][205];
vector<Event> e[100010];
Event a[100010];
map<Event, int, T> cur;
int n, m, k;
long long f[2][100010], ans = 0x3f3f3f3f3f3f3f3fLL;
void insert(Event x) {
  if (cur.count(x)) {
    cur[x]++;
  } else {
    cur[x] = 1;
  }
}
void erase(Event x) {
  cur[x]--;
  if (cur[x] == 0) {
    cur.erase(x);
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= k; i++) {
    int s, t, d, w;
    scanf("%d%d%d%d", &s, &t, &d, &w);
    e[s].push_back((Event){d, w, 1});
    e[t + 1].push_back((Event){d, w, -1});
  }
  for (int i = 1; i <= n; i++) {
    for (auto p : e[i]) {
      if (p.t == 1) {
        insert(p);
      } else {
        erase(p);
      }
    }
    if (cur.size()) {
      a[i] = (*cur.begin()).first;
    } else {
      a[i] = (Event){i, 0, 0};
    }
  }
  for (int i = n; i >= 1; i--)
    for (int j = 0; j <= m; j++) {
      dp[i][j] = 1e18;
      dp[i][j] = min(dp[i][j], a[i].w + dp[a[i].d + 1][j]);
      if (j != 0) dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
    }
  cout << dp[1][m] << endl;
}
