#include <bits/stdc++.h>
using namespace std;
long long mo = 101051, mod = 1000003769, ind;
long long mo1 = 10289, mod1 = 10001419;
long long n;
long long bs, ch[300005];
long long powe[300005], powe1[300005];
long long k[300005], t[300005];
long long ans[300005], depth, dep[300005], bst[300005];
pair<long long, long long> p[300005];
map<long long, bool> mpn, mp, mpnn;
int ti[300005][30];
vector<pair<long long, long long> > v[300005];
long long kt;
void go(long long x, long long par, long long z) {
  ch[x] = 1;
  p[x] = make_pair(par, z);
  for (int i = 0; i < v[x].size(); i++) {
    int to = v[x][i].first;
    if (to != par) {
      dep[to] = dep[x] + 1;
      go(to, x, v[x][i].second);
      ch[x] += ch[to];
    }
  }
}
void trav(long long x, long long d, long long curhash, long long curhash1,
          long long las) {
  if (d >= 0) {
    curhash = (powe[d] * curhash + las) % mod;
    curhash1 = (powe1[d] * curhash1 + las) % mod1;
    if (mpn[curhash] && mpnn[curhash1]) {
      ans[depth]++;
      mp[x] = 1;
    }
    mpn[curhash] = 1;
    mpnn[curhash1] = 1;
  }
  for (int i = 0; i < v[x].size(); i++)
    trav(v[x][i].first, d + 1, curhash, curhash1, v[x][i].second);
}
void travel(long long x, long long d, long long curhash, long long las) {
  for (int i = 0; i < v[x].size(); i++) {
    if (ti[ind][v[x][i].second]) {
      if (!mp[v[x][i].first]) ans[depth]++;
      long long o = ind;
      ind = ti[ind][v[x][i].second];
      travel(v[x][i].first, d + 1, curhash, v[x][i].second);
      ind = o;
    }
  }
}
void solve(long long x) {
  ans[dep[x]]++;
  if (v[x].size() == 0) {
    t[x] = 1;
    bst[x] = x;
    return;
  }
  for (int i = 0; i < v[x].size(); i++) solve(v[x][i].first);
  mpn.clear();
  mp.clear();
  mpnn.clear();
  for (int T = 0; T < v[x].size(); T++) {
    int to = v[x][T].first;
    if (T == 0) {
      bst[x] = bst[to];
      continue;
    }
    depth = dep[x] + 1;
    bs = bst[x];
    trav(to, -1, 0, 0, 0);
  }
  for (int T = 1; T < v[x].size(); T++) {
    int to = v[x][T].first;
    ind = v[x][0].first;
    travel(to, 0, 0, v[x][T].second);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  powe[0] = 1;
  for (int i = 1; i <= n; i++) powe[i] = (powe[i - 1] * mo) % mod;
  powe1[0] = 1;
  for (int i = 1; i <= n; i++) powe1[i] = (powe1[i - 1] * mo1) % mod1;
  for (int i = 1; i < n; i++) {
    long long x, y;
    char c;
    cin >> x >> y >> c;
    v[x].push_back(make_pair(y, c - 'a' + 1));
    v[y].push_back(make_pair(x, c - 'a' + 1));
  }
  go(1, 0, 0);
  for (int i = 1; i <= n; i++) v[i].clear();
  for (int i = 2; i <= n; i++) {
    ti[p[i].first][p[i].second] = i;
    v[p[i].first].push_back(make_pair(i, p[i].second));
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j < v[i].size(); j++)
      if (ch[v[i][j].first] > ch[v[i][0].first]) swap(v[i][j], v[i][0]);
  solve(1);
  long long mx = 0, ind = 1;
  for (int i = 1; i <= n; i++) {
    if (ans[i] > mx) {
      mx = ans[i];
      ind = i;
    }
  }
  cout << (long long)(n - mx) << '\n' << (long long)ind << '\n';
  return 0;
}
