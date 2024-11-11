#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, M = 5e5 + 5;
int n, q, a[N], dp[M];
vector<int> d[M];
bool mark[N];
inline void add(int x, int t) {
  int sz = d[x].size();
  for (int i = 0; i < 1 << sz; i++) {
    int cur = 1;
    for (int j = 0; j < sz; j++)
      if (i >> j & 1) cur *= d[x][j];
    dp[cur] += t;
  }
}
inline int calc(int x) {
  int ans = 0, sz = d[x].size();
  for (int i = 0; i < 1 << sz; i++) {
    int cur = 1;
    for (int j = 0; j < sz; j++)
      if (i >> j & 1) cur *= d[x][j];
    ans += __builtin_popcount(i) & 1 ? -dp[cur] : dp[cur];
  }
  return ans;
}
inline void read_input() {
  cin >> n >> q;
  for (int i = 0; i < n; i++) cin >> a[i];
}
inline void solve() {
  for (int i = 2; i < M; i++)
    if (d[i].empty())
      for (int j = i; j < M; j += i) d[j].push_back(i);
}
inline void write_output() {
  long long ans = 0;
  while (q--) {
    int p;
    cin >> p;
    if (mark[--p]) {
      add(a[p], -1);
      mark[p] = false;
      ans -= calc(a[p]);
    } else {
      ans += calc(a[p]);
      mark[p] = true;
      add(a[p], 1);
    }
    cout << ans << endl;
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  read_input(), solve(), write_output();
  return 0;
}
