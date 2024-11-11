#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 3;
int n, c;
long long dp[N], sum = 0;
deque<pair<int, int> > sub;
void add(pair<int, int> x) {
  sum += x.first;
  while ((int)(sub).size() and sub.back().first >= x.first) sub.pop_back();
  sub.push_back(x);
}
int get(int x) {
  while ((int)(sub).size() and sub.front().second <= x) sub.pop_front();
  return sub.front().first;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int i, j, a;
  cin >> n >> c;
  for (i = 1; i <= n; i++) {
    cin >> a;
    add({a, i});
    dp[i] = dp[i - 1];
    if (i >= c)
      dp[i] = (dp[i] > dp[i - c] + get(i - c) ? dp[i] : dp[i - c] + get(i - c));
  }
  cout << sum - dp[n];
  return 0;
}
