#include <bits/stdc++.h>
using namespace std;
struct tuyn {
  int pos, d;
  long long w;
  tuyn(long long W = 0, long long D = 0) {
    w = W;
    d = D;
    pos = 0;
  }
};
bool operator<(tuyn a, tuyn b) {
  if (a.w != b.w) return a.w < b.w;
  return a.d > b.d;
}
bool operator>(tuyn a, tuyn b) { return b < a; }
int n, m, k;
tuyn mx[100005];
long long dp[100005][202], ans;
vector<tuyn> v;
multiset<tuyn> s;
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
    int l, r, d;
    long long w;
    scanf("%d%d%d%lld", &l, &r, &d, &w);
    tuyn add;
    add.w = w;
    add.d = d;
    add.pos = l;
    v.push_back(add);
    add.pos = r + 1;
    add.w *= -1;
    v.push_back(add);
  }
  sort(v.begin(), v.end(), [](tuyn a, tuyn b) { return a.pos < b.pos; });
  for (int i = 0, j = 0; i <= n; i++) {
    while (j < v.size() && v[j].pos <= i) {
      if (v[j].w < 0)
        s.erase(s.find(tuyn(-v[j].w, v[j].d)));
      else
        s.insert(v[j]);
      j++;
    }
    if (!s.empty()) {
      auto it = s.end();
      --it;
      mx[i] = (*it);
    } else
      mx[i] = tuyn(0ll, i);
  }
  for (int i = 1; i <= n + 1; i++)
    for (int j = 0; j <= m; j++) dp[i][j] = 1000000007ll * 1000000007ll;
  dp[1][0] = 0;
  ans = 1000000007ll * 1000000007ll;
  for (int i = 1; i <= n + 1; i++)
    for (int j = 0; j <= m; j++) {
      dp[i + 1][j + 1] = min(dp[i][j], dp[i + 1][j + 1]);
      dp[mx[i].d + 1][j] = min(dp[i][j] + mx[i].w, dp[mx[i].d + 1][j]);
      if (i == n + 1) ans = min(ans, dp[i][j]);
    }
  cout << ans << endl;
  return 0;
}
