#include <bits/stdc++.h>
using namespace std;
int const N = 1000000;
long long const inf = 1e18;
int const infs = 1e9;
int n;
long long k, x[N];
map<long long, vector<long long> > fc, c;
vector<vector<char> > cn;
vector<vector<vector<long long> > > dp;
vector<vector<int> > fr, mn;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
inline void up(long long &x, long long y) { x = min(x, y); }
inline void up(int &x, int y) { x = min(x, y); }
void fl(vector<char> &c, vector<long long> const &v, int i = 0,
        long long x = 1ll, int msk = 0) {
  if (i == (int)v.size()) {
    c[msk] = true;
    return;
  }
  fl(c, v, i + 1, x, msk);
  if (x <= k / v[i]) fl(c, v, i + 1, x * v[i], msk | 1 << i);
}
int main() {
  scanf("%d%lld", &n, &k);
  for (int i = 0; i < (int)(n); ++i) scanf("%lld", x + i);
  long long g = x[0];
  for (int i = 1; i < (int)(n); ++i) g = gcd(g, x[i]);
  if (g == 1) {
    printf("0\n");
    return 0;
  }
  vector<long long> pr;
  long long t = g;
  for (int i = 2; (long long)i * i <= t; ++i)
    if (t % i == 0) {
      pr.push_back(i);
      t /= i;
      while (t % i == 0) t /= i;
    }
  if (t != 1) pr.push_back(t);
  for (int i = 0; i < (int)(n); ++i) {
    vector<long long> v(pr.size(), 1ll);
    for (int j = 0; j < (int)(pr.size()); ++j)
      while (x[i] % pr[j] == 0) x[i] /= pr[j], v[j] *= pr[j];
    long long t = 1;
    for (int j = 0; j < (int)(v.size()); ++j) t *= v[j];
    int cst;
    scanf("%d", &cst);
    if (c.find(t) == c.end()) fc[t] = v;
    c[t].push_back(cst);
  }
  cn.resize(c.size(), vector<char>(1 << pr.size(), false));
  int i = 0;
  for (map<long long, vector<long long> >::iterator it = fc.begin();
       it != fc.end(); ++it, ++i)
    fl(cn[i], it->second);
  fr.resize(1 << pr.size());
  for (int i = 0; i < (int)(fr.size()); ++i)
    for (int j = 1; j < (int)(fr.size()); ++j)
      if (!(i & j)) fr[i].push_back(j);
  mn.resize(c.size(), vector<int>(1 << pr.size(), infs));
  i = 0;
  for (map<long long, vector<long long> >::iterator it = c.begin();
       it != c.end(); ++it, ++i) {
    sort(it->second.begin(), it->second.end());
    for (int i = 1; i < (int)(it->second.size()); ++i)
      it->second[i] += it->second[i - 1];
    mn[i][0] = 0;
    for (int j = 0; j < (int)(1 << pr.size()); ++j)
      if (mn[i][j] < (int)it->second.size())
        for (int w = 0; w < (int)(fr[j].size()); ++w)
          if (cn[i][fr[j][w]]) up(mn[i][j | fr[j][w]], mn[i][j] + 1);
  }
  dp.resize(c.size() + 1,
            vector<vector<long long> >(1 << pr.size(),
                                       vector<long long>(pr.size() + 1, inf)));
  dp[0][0][0] = 0;
  i = 0;
  for (map<long long, vector<long long> >::iterator it = c.begin();
       it != c.end(); ++it, ++i)
    for (int j = 0; j < (int)(1 << pr.size()); ++j)
      for (int k = 0; k < (int)(pr.size() + 1); ++k)
        if (dp[i][j][k] != inf) {
          up(dp[i + 1][j][k], dp[i][j][k]);
          for (int w = 0; w < (int)(fr[j].size()); ++w)
            if (mn[i][fr[j][w]] != infs)
              up(dp[i + 1][j | fr[j][w]][k + mn[i][fr[j][w]]],
                 dp[i][j][k] + it->second[mn[i][fr[j][w]] - 1]);
        }
  long long an = inf;
  for (int i = 1; i < (int)(pr.size() + 1); ++i)
    if (dp[c.size()][(1 << pr.size()) - 1][i] != inf)
      up(an, dp[c.size()][(1 << pr.size()) - 1][i] * i);
  printf("%lld\n", an == inf ? -1 : an);
}
