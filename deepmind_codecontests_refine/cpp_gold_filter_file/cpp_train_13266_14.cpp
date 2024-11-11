#include <bits/stdc++.h>
using namespace std;
void file() {}
void fast() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
}
long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
int dx[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
char dir[] = {'U', 'R', 'D', 'L'};
const int N = 2e5 + 5, mod = 1e9 + 7;
int n, m;
vector<vector<int>> a;
long long dp[2][1 << 20];
long long p;
long long solve() {
  for (int i = 0; i < (1 << m); i++) dp[0][i] = 4e18;
  dp[0][(1 << m) - 1] = 0;
  bool b = 0;
  long long ans = 4e18;
  for (int i = n - 1; i >= 0; i--) {
    b = !b;
    for (int t = 0; t < (1 << m); t++) {
      dp[b][t] = dp[!b][t];
      dp[b][t] = min(dp[b][t], a[i][1] + dp[!b][t | a[i][2]]);
    }
    ans = min(ans, a[i][0] * p + dp[b][0]);
  }
  return ans;
}
int main() {
  file();
  fast();
  cin >> n >> m >> p;
  a = vector<vector<int>>(n, vector<int>(3));
  for (int i = 0; i < n; i++) {
    int x;
    cin >> a[i][1] >> a[i][0] >> x;
    while (x--) {
      int z;
      cin >> z;
      z--;
      a[i][2] |= (1 << z);
    }
  }
  sort((a).begin(), (a).end());
  reverse((a).begin(), (a).end());
  if (solve() == 4e18)
    cout << -1 << "\n";
  else
    cout << solve() << "\n";
}
