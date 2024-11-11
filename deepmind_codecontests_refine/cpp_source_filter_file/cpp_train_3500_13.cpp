#include <bits/stdc++.h>
const long long INF = 1e18 + 1;
const long long N = 1e5 + 5;
const long long MOD = 1e18 + 1;
using namespace std;
vector<long long> b;
vector<vector<long long> > g(N + 5);
long long n, m, k, r, x, y, l, c, t, cur, ans, mn(INF), mn2(INF), mn3(INF),
    mx(-INF), a[N + 5], ar[N + 5];
char c1, c2;
string s;
bool f, fl, used[N + 5];
void read(long long &in) { scanf("%I64d", &in); }
void read(long long &in1, long long &in2) { scanf("%I64d%I64d", &in1, &in2); }
void read(long long &in1, long long &in2, long long &in3) {
  scanf("%I64d%I64d%I64d", &in1, &in2, &in3);
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
void dfs(long long x) {
  used[x] = true;
  for (int i = 0; i < g[x].size(); i++) {
    if (!used[g[x][i]]) {
      dfs(g[x][i]);
    }
  }
}
long long bpow(long long x, long long p) {
  long long res;
  if (p == 0) {
    return 1;
  } else {
    res = bpow(x, p / 2);
    res = (res * res) % MOD;
    if (p % 2 == 1) {
      res = (res * x) % MOD;
    }
    return res;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mx = max(a[i], mx);
    mn = min(a[i], mn);
  }
  if (k > 2) {
    cout << mx;
  }
  if (k == 1) {
    cout << mn;
  } else {
    mx = -INF;
    mn = INF;
    ar[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      ar[i] = min(a[i], ar[i + 1]);
    }
    for (int i = 0; i < n - 1; i++) {
      mn = min(a[i], mn);
      mx = max(mx, max(mn, ar[i + 1]));
    }
    cout << mx;
  }
  return 0;
}
