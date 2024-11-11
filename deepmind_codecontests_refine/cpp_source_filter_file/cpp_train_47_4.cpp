#include <bits/stdc++.h>
using namespace std;
bool vowel(char che) {
  if (che == 'A' || che == 'E' || che == 'I' || che == 'O' || che == 'U' ||
      che == 'Y') {
    return true;
  } else {
    return false;
  }
}
const long long mod = 1e9 + 7;
long long pw(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b % 2 == 1) {
      ans *= a;
      ans %= mod;
    }
    b /= 2;
    a *= a;
    a %= mod;
  }
  return ans;
}
const int N = 1e6 + 5;
pair<long long, long long> p[N];
stack<int> sk;
string s, s1;
char o;
bool mark[N], h;
vector<long long> vt[N], vm, vs;
set<long long> st;
long long a[N], b[N], c[N], d[N], dp[N][3], dis, ps[N], tree, v[N];
void dfs(long long v, long long k) {}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t, n, m, k = 0, f = 0, sum = 0, ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  dp[0][2] = 0;
  dp[0][0] = 1;
  if ((a[1] - a[0]) >= b[0]) dp[0][1] = 1;
  long long mx = 1, mx1 = 1;
  a[n] = 1e17;
  for (int i = 1; i < n; i++) {
    dp[i][2] = mx;
    if ((a[i + 1] - a[i]) >= b[i]) dp[i][1] = mx + 1;
    if ((a[i] - a[i - 1]) >= (b[i] + b[i - 1]))
      dp[i][0] = mx + 1;
    else if ((a[i] - a[i - 1]) >= b[i])
      dp[i][0] = mx1 + 1;
    mx = max(mx, max(dp[i][0], max(dp[i][1], dp[i][2])));
    mx1 = max(mx1, max(dp[i][0], max(dp[i - 1][1], dp[i][2])));
  }
  cout << mx << endl;
}
