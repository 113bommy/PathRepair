#include <bits/stdc++.h>
using namespace std;
int solve() {
  int n, m, c, c0;
  cin >> n >> m >> c >> c0;
  vector<pair<int, pair<int, int>>> P;
  for (int i = 0; i < n; i++) {
    int t, a, b;
    cin >> t >> a >> b;
    P.emplace_back(t, make_pair(b, a));
  }
  P.emplace_back(m, make_pair(0, 0));
  sort(P.begin(), P.end());
  map<int, int> M;
  M[0] = c0;
  int sum = c0;
  long long ans = 0;
  for (int i = 0; i <= n; i++) {
    int b = P[i].second.first, a = P[i].second.second,
        d = P[i].first - (i ? P[i - 1].first : 0);
    while (!M.empty() && d > 0) {
      if (d >= M.begin()->second) {
        sum -= M.begin()->second;
        ans += (long long)M.begin()->first * M.begin()->second;
        d -= M.begin()->second;
        M.erase(M.begin());
      } else {
        sum -= d;
        ans += (long long)M.begin()->first * d;
        M.begin()->second -= d;
        d = 0;
      }
    }
    if (d > 0) return -1;
    int nxt = min(c - sum, a);
    sum += nxt;
    while (nxt < a && !M.empty() && M.rbegin()->first > b) {
      if (a - nxt >= M.rbegin()->second) {
        nxt += M.rbegin()->second;
        M.erase(--M.end());
      } else {
        M.rbegin()->second -= a - nxt;
        nxt = a;
      }
    }
    if (nxt) M[b] += nxt;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int q;
  cin >> q;
  while (q--) cout << solve() << '\n';
}
