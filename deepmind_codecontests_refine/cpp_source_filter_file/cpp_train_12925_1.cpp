#include <bits/stdc++.h>
const int N = 1e6 + 10;
const int mod = 998244353;
using namespace std;
struct Bip {
  vector<vector<pair<int, int> > > ls;
  vector<vector<pair<int, int> > > rs;
  vector<int> lfix;
  vector<int> rfix;
  int L, R;
  Bip(int L_, int R_)
      : ls(L_), rs(R_), lfix(L_, 0), rfix(R_, 0), L(L_), R(R_) {}
  bool fix_l(int i, int val) {
    if (val && lfix[i] && val != lfix[i]) return false;
    lfix[i] = val;
    return true;
  }
  bool fix_r(int i, int val) {
    if (val && rfix[i] && val != rfix[i]) return false;
    rfix[i] = val;
    return true;
  }
  void add(int i, int j, int sw) {
    ls[i].emplace_back(j, sw);
    rs[j].emplace_back(i, sw);
  }
  bool ldfs(int i, int val, vector<bool> &visl, vector<bool> &visr) {
    visl[i] = true;
    if (val && lfix[i] && lfix[i] != val) return false;
    for (auto &e : ls[i]) {
      if (visr[e.first]) continue;
      if (!rdfs(e.first, val * e.second, visl, visr)) return false;
    }
    return true;
  }
  bool rdfs(int i, int val, vector<bool> &visl, vector<bool> &visr) {
    visr[i] = true;
    if (val && rfix[i] && rfix[i] != val) return false;
    for (auto &e : rs[i]) {
      if (visl[e.first]) continue;
      if (!ldfs(e.first, val * e.second, visl, visr)) return false;
    }
    return true;
  }
};
long long work(int n, const char *s, int len) {
  Bip g((len + 1) / 2, (n + 1) / 2);
  vector<int> a(len);
  vector<int> b(n);
  for (int i = 0; i < len; ++i)
    if (i < (len + 1) / 2)
      a[i] = i;
    else
      a[i] = len - 1 - i;
  for (int i = 0; i < n; ++i)
    if (i < (n + 1) / 2)
      b[i] = i;
    else
      b[i] = n - 1 - i;
  for (int i = 0; i < n; ++i) {
    int c = s[n - 1 - i];
    if (c == '?') continue;
    if (i < len)
      g.add(a[i], b[i], c == '0' ? 1 : -1);
    else if (!g.fix_r(b[i], c == '1' ? 1 : -1))
      return 0;
  }
  if (!g.fix_l(0, 1)) return 0;
  vector<bool> visl((len + 1) / 2, false);
  vector<bool> visr((n + 1) / 2, false);
  for (int l = 0; l < (len + 1) / 2; ++l) {
    if (g.lfix[l] && !visr[l]) {
      if (!g.ldfs(l, g.lfix[l], visl, visr)) return 0;
    }
  }
  for (int r = 0; r < (n + 1) / 2; ++r) {
    if (g.rfix[r] && !visl[r]) {
      if (!g.rdfs(r, g.rfix[r], visl, visr)) return 0;
    }
  }
  long long ans = 1;
  for (int l = 0; l < (len + 1) / 2; ++l) {
    if (!visl[l]) ans = ans * 2 % mod, g.ldfs(l, 0, visl, visr);
  }
  for (int r = 0; r < (n + 1) / 2; ++r) {
    if (!visr[r]) {
      ans = ans * 2 % mod;
      g.rdfs(r, 0, visl, visr);
    }
  }
  return ans;
}
int main() {
  char s[1002];
  scanf("%s", s);
  int n = strlen(s);
  int ans = 0;
  for (int i = 1; i < n; ++i) ans = (ans + work(n, s, i)) % mod;
  printf("%d\n", ans);
  return 0;
}
