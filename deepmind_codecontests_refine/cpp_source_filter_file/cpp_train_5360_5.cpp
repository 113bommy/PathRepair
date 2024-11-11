#include <bits/stdc++.h>
using namespace std;
int const INF = 1e9 + 7;
long long const LLINF = 1e18;
int const N = 100100;
unordered_set<int> was[210];
bool ok(vector<int> const& f) {
  for (int i = 1; i < f.size(); i++) {
    if (f[i] != f[f[i]]) return false;
  }
  return true;
}
vector<int> binpow(vector<int> const& f, int p) {
  if (p == 1) return f;
  if (p % 2) {
    auto res = binpow(f, p - 1);
    for (int i = 1; i < f.size(); i++) res[i] = f[res[i]];
    return res;
  } else {
    auto res = binpow(f, p / 2);
    auto nw = res;
    for (int i = 1; i < res.size(); i++) res[i] = nw[res[i]];
    return res;
  }
}
long long gcd(long long a, long long b) { return (!b) ? a : gcd(b, a % b); }
int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> f(n + 1), position(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> f[i];
  }
  int pre = 0;
  vector<int> cycles(n + 1, 0);
  long long lcm = 1;
  for (int i = 1; i <= n; i++) {
    int pos = i;
    vector<int> was(n + 1, 0);
    int sz = 0;
    do {
      sz++;
      was[pos] = sz;
      pos = f[pos];
    } while (!was[pos]);
    cycles[i] = sz - was[pos] + 1;
    pre = max(pre, was[pos]);
    lcm = lcm * cycles[i] / gcd(lcm, cycles[i]);
  }
  if (lcm < pre) lcm = ((pre + lcm - 1) / lcm) * lcm;
  cout << lcm;
  return 0;
  cout << pre << '\n';
  for (int i : cycles) cout << i << ' ';
  cout << '\n';
  int k = 1;
  auto nf = f;
  for (int cnt = 0; cnt < pre; cnt++) {
    if (!ok(nf)) {
      for (int i = 1; i <= n; i++) nf[i] = f[nf[i]];
      k++;
    }
    if (ok(nf)) break;
  }
  long long ans = LLINF;
  if (ok(nf))
    ans = min(ans, 1LL * k);
  else {
    long long lcm = 1;
    for (int i = 1; i <= n; i++) {
      if (cycles[i]) lcm = (lcm * cycles[i]) / gcd(lcm, cycles[i]);
    }
    ans = min(ans, pre + lcm);
  }
  k = 1;
  nf = f;
  while (k <= n && !ok(nf)) {
    for (int i = 1; i <= n; i++) nf[i] = f[nf[i]];
    k++;
  }
  if (ok(nf)) ans = min(ans, 1LL * k);
  cout << ans;
  return 0;
}
