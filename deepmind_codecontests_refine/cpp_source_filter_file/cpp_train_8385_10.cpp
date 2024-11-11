#include <bits/stdc++.h>
using namespace std;
const long long maxn = 4e6;
const long double SADAT = 7.84e-17;
const long long INF = 1e9;
const long long mod = 1e9 + 7;
const long double PI = 4 * atan((long double)1);
long long pw(long long a, long long b) {
  return (!b ? 1
             : (b & 1 ? a * pw(a * a % mod, b / 2) % mod
                      : pw(a * a % mod, b / 2) % mod));
}
long long n;
long long a[maxn];
long long p[maxn];
long long sum[maxn];
long long par[maxn], sz[maxn];
bool mark[maxn];
long long mx = 0;
vector<int> ans;
long long getpar(long long v) {
  if (v == par[v]) {
    return (v);
  }
  return (par[v] = getpar(par[v]));
}
void merge(long long x, long long y) {
  x = getpar(x), y = getpar(y);
  if (x == y) {
    return;
  }
  if (sz[y] > sz[x]) {
    swap(x, y);
  }
  sz[x] += sz[y];
  sum[x] += sum[y];
  mx = max(mx, sum[x]);
  par[y] = x;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    par[i] = i;
    sum[i] = a[i];
    sz[i] = 1;
  }
  for (long long i = 1; i <= n; i++) {
    cin >> p[i];
  }
  reverse(p + 1, p + n + 1);
  for (long long i = 1; i <= n; i++) {
    ans.push_back(mx);
    ;
    mark[p[i]] = 1;
    if (p[i] + 1 <= n) {
      if (mark[p[i] + 1]) {
        merge(p[i], p[i] + 1);
      }
    }
    if (p[i] - 1 >= 1) {
      if (mark[p[i] - 1]) {
        merge(p[i], p[i] - 1);
      }
    }
    mx = max(mx, (long long)a[p[i]]);
  }
  reverse(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << '\n';
  ;
  return (0);
}
