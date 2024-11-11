#include <bits/stdc++.h>
using namespace std;
long double T, n, w, m, nn, mm, ma, mb, h, r, l, i, j, ii, jj, x[1000001],
    y[1000001], z, g, aa, bb, a, b, c, d, vis[1000001], k, mod = 998244353, q,
                                                           inf = 1e12;
vector<long long> v[1000001], vv;
vector<long long> vvv;
queue<pair<long long, long long> > qq;
pair<long long, pair<long long, long long> > p;
map<long long, long long> mp, mpp, mppp;
set<pair<long long, long long> > se, see;
set<pair<long long, long long> >::iterator it, itt;
string s, t;
char cc;
int main() {
  ios::sync_with_stdio(0);
  scanf("%Lf%Lf%Lf", &k, &d, &n);
  long long dd = d, nn = n, kk = k;
  aa = 1;
  a = k + (((dd - (kk % dd)) % dd) * (aa)) / 2;
  z = k + ((dd - (kk % dd)) % dd);
  long long q = n / a;
  z *= q;
  n -= a * q;
  if (n <= k)
    c = n;
  else
    c = k + (n - k) * 2;
  printf("%Lf", z + c);
  return 0;
}
