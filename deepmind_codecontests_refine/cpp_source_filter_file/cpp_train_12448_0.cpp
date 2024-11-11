#include <bits/stdc++.h>
using namespace std;
inline long long mod(long long n, long long m) {
  long long ret = n % m;
  if (ret < 0) ret += m;
  return ret;
}
long long gcd(long long a, long long b) {
  return (b == 0LL ? a : gcd(b, a % b));
}
long long exp(long long a, long long b, long long m) {
  if (b == 0LL) return 1LL;
  if (b == 1LL) return mod(a, m);
  long long k = mod(exp(a, b / 2, m), m);
  if (b & 1LL) {
    return mod(a * mod(k * k, m), m);
  } else
    return mod(k * k, m);
}
long long modpow(long long b, long long e, long long mod) {
  long long ans = 1;
  for (; e; b = b * b % mod, e /= 2)
    if (e & 1) ans = ans * b % mod;
  return ans;
}
const int N = 1e6 + 10;
int p[N];
bool vis[N];
int n;
int dp[2][N];
int cnt[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  vector<int> tam;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      int cur = p[i];
      vis[cur] = 1;
      int t = 1;
      while (cur != i) {
        t++;
        cur = p[cur];
        vis[cur] = 1;
      }
      tam.push_back(t);
    }
  }
  int mx = 0;
  int kk = k;
  for (int x : tam) {
    int poe = min(kk, x / 2);
    kk -= poe;
    mx += poe * 2;
  }
  mx += kk;
  mx = min(mx, n);
  for (int x : tam) cnt[x]++;
  sort(tam.begin(), tam.end());
  tam.erase(unique(tam.begin(), tam.end()), tam.end());
  int tot = 0;
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  kk = 0;
  for (int i = 1; i <= (int)tam.size(); i++) {
    int val = tam[i - 1];
    int prv = (i - 1) & 1;
    int cur = (i & 1);
    kk += val * cnt[val];
    for (int j = 0; j <= kk; j++) {
      if (dp[prv][j] >= 0)
        dp[cur][j] = 0;
      else if (j - val >= 0 and dp[cur][j - val] >= 0 and
               dp[cur][j - val] < cnt[val]) {
        dp[cur][j] = dp[cur][j - val] + 1;
      } else
        dp[cur][j] = -1;
    }
    if (dp[cur][k]) {
      cout << k << " " << mx << "\n";
      exit(0);
    }
  }
  int mn = 0;
  if (dp[(int)tam.size() & 1][k] != -1) {
    mn = k;
  } else
    mn = min(n, k + 1);
  cout << mn << " " << mx << "\n";
}
