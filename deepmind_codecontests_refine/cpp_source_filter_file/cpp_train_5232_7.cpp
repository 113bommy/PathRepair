#include <bits/stdc++.h>
using namespace std;
const int N = 3007;
int n, a[N], dp[N];
vector<int> g;
int get_id(int x) { return lower_bound(g.begin(), g.end(), x) - g.begin(); }
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    g.clear();
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
      dp[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      g.push_back(a[i]);
    }
    sort(g.begin(), g.end());
    for (int i = 1; i <= n; i++) {
      int x = get_id(a[i]);
      dp[x] = dp[x - 1] + 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      ans = max(ans, dp[i]);
    }
    printf("%d\n", n - ans);
  }
}
