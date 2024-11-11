#include <bits/stdc++.h>
using namespace std;
const long long N = (long long)(1e6) + 322;
const long long MAXN = (long long)(1e7) + 100;
const long long inf = (long long)(1e18) + 322;
const long long mod = (long long)(1e9) + 7;
const double eps = 1e-6;
long long n, a[N], b[N], m, p[N], dp[N];
vector<long long> pos[N];
bool in[N];
long long f[N];
void add(long long i, long long add) {
  if (!i) return;
  for (; i < N; i += (i & -i)) {
    f[i] += add;
  }
}
long long get(long long i) {
  if (!i) return 0;
  long long res = 0;
  for (; i > 0; i -= (i & -i)) res += f[i];
  return res;
}
signed main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (long long i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (long long i = 1; i <= n; ++i) {
    cin >> p[i];
  }
  cin >> m;
  for (long long i = 1; i <= m; ++i) {
    cin >> b[i];
    in[b[i]] = true;
  }
  m++;
  b[m] = b[m - 1] + 1;
  n++;
  a[n] = b[m];
  in[b[m]] = true;
  in[0] = true;
  for (long long i = 0; i <= n; ++i) {
    pos[a[i]].push_back(i);
    add(i, p[i]);
  }
  vector<long long> prev = pos[0];
  long long previd = 0;
  for (long long i = 1; i <= n; ++i) {
    if (in[i]) {
      long long ptr = 0;
      long long mn = inf;
      for (auto it : pos[i]) {
        while (ptr < (long long)(prev.size()) && prev[ptr] < it) {
          mn = min(mn, dp[prev[ptr]] - get(prev[ptr] - 1));
          ptr++;
        }
        if (mn < inf) {
          dp[it] = get(it - 1) + mn;
        } else {
          dp[it] = inf;
        }
      }
      for (long long j = previd + 1; j <= i; ++j) {
        for (auto it : pos[j]) {
          if (p[it] >= 0) {
            add(it, -p[it]);
          }
        }
      }
      prev = pos[i];
      previd = i;
    }
  }
  if (dp[n] >= (long long)(1e15)) {
    cout << "NO";
    return 0;
  }
  cout << "YES\n";
  cout << dp[n];
  return 0;
}
