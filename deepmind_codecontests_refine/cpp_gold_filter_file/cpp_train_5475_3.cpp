#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e14;
struct UF {
  vector<int> t;
  UF(int n) { t.assign(n, -1); }
  int find(int a) { return t[a] < 0 ? a : t[a] = find(t[a]); }
  void merge(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return;
    t[a] = b;
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> x(n);
  vector<pair<int, int>> pc(m);
  for (auto &a : x) cin >> a;
  sort(x.begin(), x.end());
  for (int j = 0; j < (m); ++j) cin >> pc[j].first >> pc[j].second;
  sort(pc.begin(), pc.end());
  vector<int> p(m), c(m);
  for (int j = 0; j < (m); ++j) {
    p[j] = pc[j].first;
    c[j] = pc[j].second;
  }
  vector<vector<long long>> dp(2, vector<long long>(n + 1, inf));
  dp[1][0] = 0;
  for (int j = 0; j < (m); ++j) {
    vector<long long> pre(n + 1), dif(n + 1);
    ;
    for (int i = 0; i < (n); ++i) pre[i + 1] = pre[i] + abs(p[j] - x[i]);
    for (int i = 0; i < (n + 1); ++i) dif[i] = dp[!(j & 1)][i] - pre[i];
    UF u(n + 1);
    stack<pair<int, long long>> st;
    for (int b = 0; b < (n + 1); ++b) {
      while (!st.empty() && st.top().second >= dif[b]) {
        u.merge(st.top().first, b);
        st.pop();
      }
      st.push({b, dif[b]});
      dp[j & 1][b] = pre[b] + dif[u.find(max(0, b - c[j]))];
    }
  }
  long long ans = dp[(m - 1) & 1][n];
  if (ans >= inf) ans = -1;
  cout << ans << endl;
}
