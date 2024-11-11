#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long inf = (1ll << 62);
const int MX = 2e5 + 9;
struct node {
  long long t, d, p, ind;
  node() {}
  node(long long t, long long d, long long p, long long ind)
      : t(t), d(d), p(p), ind(ind) {}
} a[109];
long long n;
long long dp[109][20 * 109];
bool operator<(const node &A, const node &B) { return A.d < B.d; }
long long DP(long long x, long long t) {
  if (x == n) return 0;
  long long &ret = dp[x][t];
  if (ret != -1) return ret;
  ret = DP(x + 1, t);
  if (t + a[x].t < a[x].d) ret = max(ret, DP(x + 1, t + a[x].t) + a[x].p);
  return ret;
}
vector<int> sol;
void FDP(long long x, long long t) {
  if (x == n) return;
  long long &ret = dp[x][t];
  if (ret == DP(x + 1, t)) {
    FDP(x + 1, t);
    return;
  }
  if (t + a[x].t < a[x].d) {
    if (ret == DP(x + 1, t + a[x].t) + a[x].p) {
      sol.push_back(a[x].ind + 1);
      FDP(x + 1, t + a[x].t);
      return;
    }
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%lld%lld%lld", &a[i].t, &a[i].d, &a[i].p);
    a[i].ind = i;
  }
  sort(a, a + n);
  memset(dp, -1, sizeof(dp));
  cout << DP(0, 0) << endl;
  FDP(0, 0);
  cout << sol.size() << endl;
  for (auto pp : sol) cout << pp << " ";
}
