#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using ll = long long int;
using vi = vector<int>;
using graph = vector<vi>;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 2005;
ll dp[MAXN], of[MAXN], sum[MAXN];
vi v;
int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  v.push_back(-1);
  int x;
  while (n--) {
    scanf("%d", &x);
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  int y;
  while (m--) {
    scanf("%d %d", &x, &y);
    if (x > k) continue;
    of[x] = max(of[x], (ll)y);
  }
  for (int i = 1; i <= k; ++i) {
    sum[i] = v[i] + sum[i - 1];
    of[i] = i - of[i];
    dp[i] = sum[i];
  }
  for (int i = 1; i <= k; ++i) {
    for (int w = i; w <= k; ++w) {
      dp[w] = min(dp[w], sum[w] - sum[w - of[i]] + dp[w - i]);
    }
  }
  printf("%lld\n", dp[k]);
}
