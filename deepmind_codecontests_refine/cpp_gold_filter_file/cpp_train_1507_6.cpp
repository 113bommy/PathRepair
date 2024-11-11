#include <bits/stdc++.h>
using namespace std;
const long long int N = 2e5 + 100;
long long int n, s, no, a[N], l, k, dp[N];
deque<pair<long long int, long long int> > dma, dmi, re;
pair<long long int, long long int> p;
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> s >> no;
  dp[0] = 0;
  for (int i = 1; i <= n; i++) cin >> a[i];
  l = 1;
  k = 0;
  re.push_back({0, 0});
  for (int r = 1; r <= n; r++) {
    dp[r] = 1e18;
    p = make_pair(a[r], r);
    while (!dma.empty() && dma.back().first < p.first) dma.pop_back();
    while (!dmi.empty() && dmi.back().first > p.first) dmi.pop_back();
    dma.push_back(p);
    dmi.push_back(p);
    while (dma.front().first - dmi.front().first > s) {
      if (dma.front().second > dmi.front().second) {
        l = dmi.front().second + 1;
        dmi.pop_front();
      } else {
        l = dma.front().second + 1;
        dma.pop_front();
      }
    }
    while (k + 1 <= n && k + 1 <= r - no) {
      k++;
      while (!re.empty() && re.back().first > dp[k]) re.pop_back();
      re.push_back({dp[k], k});
    }
    while (!re.empty() && re.front().second < l - 1) re.pop_front();
    if (!re.empty() && r - l + 1 >= no) dp[r] = re.front().first + 1;
  }
  if (dp[n] >= 1e18)
    cout << -1;
  else
    cout << dp[n];
}
