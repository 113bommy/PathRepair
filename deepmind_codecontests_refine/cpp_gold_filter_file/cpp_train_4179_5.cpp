#include <bits/stdc++.h>
using namespace std;
const int N = 1e5, K = 5;
const long long INF = 1e18;
const string hard = "hard";
int n, a[N];
string s;
long long memo[N][K];
long long dp(int i, int k) {
  if (k == int((hard).size())) return INF;
  if (i == n) return 0;
  long long &res = memo[i][k];
  if (res != -1) return res;
  return res = min(dp(i + 1, k + (s[i] == hard[k])), dp(i + 1, k) + a[i]);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> s;
  for (int i = int(0); i < int(n); i++) cin >> a[i];
  fill(memo[0], memo[N], -1);
  cout << dp(0, 0) << '\n';
  return 0;
}
