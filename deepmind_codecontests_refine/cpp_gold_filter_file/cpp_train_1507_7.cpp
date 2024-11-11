#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s, len;
  scanf("%d%d%d", &n, &s, &len);
  vector<int> a(n);
  for (int &t : a) scanf("%d", &t);
  if (len > n) {
    puts("-1");
    return 0;
  }
  multiset<int> ms;
  vector<int> dp(n + 1, 1 << 20);
  for (int r = 0; r < len; r++) {
    ms.insert(a[r]);
  }
  auto getDif = [](multiset<int> &ms) { return *ms.rbegin() - *ms.begin(); };
  int ans = -1;
  dp[0] = 0;
  if (getDif(ms) <= s) dp[len] = 1;
  int st = 0;
  multiset<int> best;
  best.insert(dp[0]);
  for (int r = len; r < n; r++) {
    best.insert(dp[r - len + 1]);
    ms.insert(a[r]);
    while (!best.empty() && getDif(ms) > s) {
      best.erase(best.find(dp[st++]));
      ms.erase(ms.find(a[r - ms.size() + 1]));
    }
    if (!best.empty()) dp[r + 1] = *best.begin() + 1;
  }
  cout << (dp[n] >= (1 << 20) ? -1 : dp[n]) << endl;
}
