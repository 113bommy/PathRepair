#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const long long inf = 3e18;
const long long MAXN = 1e5 + 10;
const long long R = 1 << 19;
const long long mod = 1e9 + 7;
const long long LOGN = 21;
vector<long long> P(1e6 + 10, -1);
vector<long long> RAND(1e6 + 10);
void init() {
  for (long long i = 2; i < (long long)P.size(); ++i) {
    if (P[i] == -1) {
      P[i] = i;
      for (long long j = i * i; j < (long long)P.size(); j += i)
        if (P[j] == -1) P[j] = i;
    }
  }
  for (long long i = 0; i < (long long)RAND.size(); ++i) RAND[i] = rnd();
}
void out(vector<long long> &cur) {
  vector<long long> ans;
  for (long long i = 1; i < (long long)cur.size(); ++i)
    if (cur[i]) ans.push_back(i);
  cout << (long long)ans.size() << "\n";
  for (auto x : ans) cout << x << " ";
  cout << "\n";
}
void solve() {
  init();
  long long n;
  cin >> n;
  vector<long long> cur(n + 1, 1);
  if (n % 4 == 0) {
    cur[n / 2] = 0;
    out(cur);
    return;
  }
  unordered_map<long long, long long> rem;
  vector<long long> dp(n + 1, 0);
  rem[0] = 0;
  long long XOR = 0;
  for (long long i = 2; i <= n; ++i) {
    dp[i] = dp[i - 1];
    long long x = i;
    while (P[x] != -1) {
      dp[i] ^= RAND[P[x]];
      x /= P[x];
    }
    rem[dp[i]] = i;
    XOR ^= dp[i];
  }
  if (rem.find(XOR) != rem.end()) {
    cur[rem[XOR]] = 0;
    out(cur);
    return;
  }
  for (long long i = 2; i <= n; ++i) {
    long long x = XOR ^ dp[i];
    if (rem.find(x) != rem.end() && rem[x] != i) {
      cur[i] = cur[rem[x]] = 0;
      out(cur);
      return;
    }
  }
  if (n & 1) {
    cur[n] = 0;
    --n;
  }
  n /= 2;
  cur[n] = 0;
  if (n & 1) cur[2] = 0;
  cur[1] = 1;
  out(cur);
}
void solve2() {
  cout << "======"
       << "\n";
  long long n;
  cin >> n;
  long long ans = 0;
  for (long long i = 1; i < (1 << (n)); ++i) {
    vector<long long> cur;
    long long cnt = 0;
    for (long long j = 0; j < n; ++j)
      if ((1 << j) & i) {
        cur.push_back(j + 1);
        ++cnt;
      }
    long long x = 1;
    for (auto y : cur)
      for (long long j = 1; j <= y; ++j) x *= j;
    long long k = sqrt(x);
    while (k * k < x) k++;
    if (k * k == x) ans = max(ans, cnt);
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
