#include <bits/stdc++.h>
using namespace std;
int N, ans;
pair<int, int> ar[100005];
int dp[100005];
int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d%d", &ar[i].first, &ar[i].second);
  }
  ans = N - 1;
  sort(ar, ar + N);
  for (int i = 1; i < N; i++) {
    int pos = (int)(lower_bound(ar, ar + i + 1,
                                make_pair(ar[i].first - ar[i].second, 0)) -
                    ar);
    if (pos > 0) {
      dp[i] = dp[pos - 1] + i - pos;
    } else
      dp[i] = i - pos;
    ans = min(ans, dp[i] + (N - i - 1));
  }
  printf("%d\n", ans);
  return 0;
}
