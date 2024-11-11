#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7, siz = 2e5 + 5;
long long t, n, m, k, a[siz], cost[siz];
long long en[siz];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  string s;
  cin >> s;
  s = "0" + s;
  queue<long long> q;
  for (long long i = 1; i <= n; i++) {
    if (s[i] == '1') q.push(i);
    while (q.size() and i - q.front() > k) q.pop();
    if (q.size()) en[i] = q.front();
  }
  cost[0] = 0;
  set<pair<long long, long long>> ss;
  ss.insert({0, 0});
  for (long long i = 1; i <= n; i++) {
    cost[i] = i + cost[i - 1];
    if (en[i] > 0) {
      long long best = 1e15;
      while ((*ss.begin()).second < (en[i] - k - 1)) ss.erase(ss.begin());
      best = (*ss.begin()).first;
      cost[i] = min(cost[i], en[i] + best);
    }
    ss.insert({cost[i], i});
  }
  cout << cost[n] << endl;
}
