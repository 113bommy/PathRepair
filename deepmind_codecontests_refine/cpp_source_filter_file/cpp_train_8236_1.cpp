#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e6 + 3;
const int maxn = 300500;
long long pa[maxn], su[maxn], suf[maxn], pre[maxn];
long long par(int x) { return (x == pa[x] ? x : pa[x] = par(pa[x])); }
long long d[maxn], c[maxn], res[maxn];
void solve() {
  int n;
  scanf("%d", &n);
  long long x;
  scanf("%lld", &x);
  long long ret = 0;
  for (int i = 0; i < (int)(n); ++i) {
    pa[i] = i;
    scanf("%lld", &d[i]);
    scanf("%lld", &c[i]);
    c[i] = x - c[i];
    suf[i] = pre[i] = res[i] = max(0LL, c[i]);
    su[i] = c[i];
    ret = max(ret, c[i]);
  }
  vector<pair<long long, int>> v;
  for (int i = (1); i < (int)(n); ++i) {
    v.push_back({(d[i] - d[i - 1]) * 1LL * (d[i] - d[i - 1]), i});
  }
  sort(v.begin(), v.end());
  for (auto it : v) {
    int i = it.second - 1, j = it.second;
    i = par(i);
    j = par(j);
    if (i != j) {
      pa[j] = i;
      res[i] = max({res[i], res[j], suf[i] + pre[j]});
      suf[i] = max(suf[j], pre[i] + su[j]);
      pre[i] = max(pre[i], su[i] + pre[j]);
      su[i] += su[j];
    }
    ret = max(ret, res[i] - it.first);
  }
  printf("%lld\n", ret);
}
int main() { solve(); }
