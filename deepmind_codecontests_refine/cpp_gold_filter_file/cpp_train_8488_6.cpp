#include <bits/stdc++.h>
using namespace std;
const long long md = 1e9 + 7;
int n;
vector<int> gpf;
void pfs(int x, vector<int> &res) {
  if (x == 1) return;
  if (x == n + 1) {
    res.push_back(x);
    return;
  }
  int p = gpf[x];
  pfs(x / p, res);
  res.push_back(p);
}
void fail() {
  puts("0");
  exit(0);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  vector<bool> pr(n + 1);
  gpf.resize(n + 1);
  vector<int> rad(n + 1), kl(n + 2);
  rad[1] = 1;
  for (int i = (2); i < int(n + 1); ++i) {
    if (!gpf[i]) {
      for (int j = i; j <= n; j += i) gpf[j] = i;
      pr[i] = 1;
    }
    int p = gpf[i], j = i / p;
    rad[i] = rad[j];
    if (j % p != 0) rad[i] *= p;
  }
  rad[1] = n + 1;
  int hi = n + 2;
  for (int d = (2); d < int(n); ++d) {
    int nx = n / d;
    for (int i = (nx + 1); i < int(hi); ++i) kl[i] = d;
    hi = nx + 1;
  }
  vector<int> perm(n + 1), pp(n + 2), rcnt(n + 2), klcnt(n + 2);
  vector<int> rseen(n + 2), pseen(n + 2);
  for (int i = (1); i < int(n + 1); ++i) {
    cin >> perm[i];
    if (perm[i] == 0)
      rcnt[rad[i]]++;
    else {
      if (rseen[perm[i]]++) fail();
      vector<int> ps, is;
      pfs(rad[perm[i]], ps);
      pfs(rad[i], is);
      if (is.size() != ps.size()) fail();
      for (int k = (0); k < int(is.size()); ++k) {
        if (pp[is[k]] == 0) pp[is[k]] = ps[k];
        if (pp[is[k]] != ps[k]) fail();
      }
    }
  }
  for (int i = (2); i < int(n + 2); ++i)
    if (i == n + 1 || pr[i]) {
      if (pp[i] == 0)
        ++klcnt[kl[i]];
      else {
        if (pseen[pp[i]]++) fail();
        if (kl[i] != kl[pp[i]]) fail();
      }
    }
  long long ans = 1;
  vector<long long> fs(n + 3);
  fs[0] = 1;
  for (int i = (1); i < int(n + 3); ++i) fs[i] = i * fs[i - 1] % md;
  for (auto &x : rcnt) ans = ans * fs[x] % md;
  for (auto &x : klcnt) ans = ans * fs[x] % md;
  cout << ans << endl;
}
