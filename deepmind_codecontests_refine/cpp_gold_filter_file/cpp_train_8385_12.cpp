#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
const double PI = acos(-1.0);
const long long mod = 1000000007;
const long long INF = 1e9;
const long long LINF = 1e18;
const long long MAX = 2e5 + 7;
const long long MAXN = 2e3 + 7;
const double EPS = 1e-9;
int n;
vector<long long> a;
vector<int> q;
vector<long long> ans;
vector<int> p;
vector<long long> sz;
vector<long long> sum;
long long ma = 0;
int find(int v) {
  if (p[v] == v) return v;
  return p[v] = find(p[v]);
}
void unite(int i, int j) {
  i = find(i);
  j = find(j);
  if (i != j) {
    if (sz[i] < sz[j]) swap(i, j);
    sz[i] += sz[j];
    sum[i] += sum[j];
    p[j] = i;
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  a.resize(n);
  for (int i = (0); i < (n); ++i) cin >> a[i];
  q.resize(n);
  for (int i = (0); i < (n); ++i) cin >> q[i], q[i]--;
  reverse(q.begin(), q.end());
  ans.resize(n);
  p.assign(n, -1);
  sz.resize(n);
  sum.resize(n);
  for (int i = (0); i < (n); ++i) {
    ans[i] = ma;
    int x = q[i];
    p[x] = x;
    sz[x] = 1;
    sum[x] = a[x];
    ma = max(ma, sum[x]);
    if (x && p[x - 1] != -1) {
      unite(x, x - 1);
      ma = max(ma, sum[find(x)]);
    }
    if (x < n - 1 && p[x + 1] != -1) {
      unite(x, x + 1);
      ma = max(ma, sum[find(x)]);
    }
  }
  reverse(ans.begin(), ans.end());
  for (int i = (0); i < (n); ++i) cout << ans[i] << endl;
  cin >> n;
  return 0;
}
