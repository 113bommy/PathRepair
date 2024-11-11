#include <bits/stdc++.h>
using namespace std;
const long long MOD = (long long)1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;
priority_queue<int, vector<int>, greater<int> > pq;
vector<int> v;
pair<int, int> dp[300001];
int vec[300001];
int x[300001];
pair<int, int> num[300001];
int main() {
  int t;
  scanf("%d", &t);
  dp[0] = {0, -1};
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      num[i] = {(int)2e9, -1};
      dp[i] = {0, (int)2e9};
    }
    int tt, mav = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &vec[i]);
      x[i] = vec[i];
      num[vec[i]].first = min(num[vec[i]].first, i);
      num[vec[i]].second = max(num[vec[i]].second, i);
    }
    x[n] = 0;
    sort(x, x + n + 1);
    int nn = unique(x, x + n + 1) - x;
    for (int i = 0; i < n; i++) {
      tt = lower_bound(x, x + n, vec[i]) - x;
      if (dp[tt].second < 1e9) continue;
      if (i > dp[tt - 1].second) {
        dp[tt].first = dp[tt - 1].first + 1;
        dp[tt].second = num[x[tt]].second;
      } else {
        dp[tt].first = 1;
        dp[tt].second = num[x[tt]].second;
      }
      mav = max(mav, dp[tt].first);
    }
    printf("%d\n", nn - 1 - mav);
  }
}
