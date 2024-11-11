#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 11;
const int sqr = 400;
const long long base = 727;
const long long mod = 1e9 + 11;
const int oo = 1e9;
int nxt[maxn][26], k[maxn], ind[maxn], siz, n;
long long h[maxn], po[maxn], qh[maxn];
string s, t[maxn];
vector<int> found[maxn];
void add(string &s, int i) {
  int cur = 0;
  for (auto x : s) {
    if (!nxt[cur][x - 'a']) nxt[cur][x - 'a'] = ++siz;
    cur = nxt[cur][x - 'a'];
  }
  ind[cur] = i;
}
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  memset(ind, -1, sizeof ind);
  cin >> s >> n;
  po[0] = 1LL;
  h[0] = s[0] - 'a' + 1;
  for (int i = 1; i < (int)(s).size(); i++) {
    h[i] = (h[i - 1] * base + (s[i] - 'a' + 1)) % mod;
    po[i] = po[i - 1] * base % mod;
  }
  vector<int> big;
  for (int i = 0; i < n; i++) {
    cin >> k[i] >> t[i];
    if ((int)(t[i]).size() > sqr) {
      big.push_back(i);
    } else {
      add(t[i], i);
    }
    for (auto x : t[i]) {
      qh[i] = (qh[i] * base + (x - 'a' + 1)) % mod;
    }
  }
  auto gethash = [&](int l, int r) {
    long long ret = h[r];
    if (l) {
      ret -= po[r - l + 1] * h[l - 1];
      assert(r - l + 1 < (int)(s).size());
    }
    ret %= mod;
    while (ret < 0) ret += mod;
    return ret;
  };
  for (int i = 0; i < (int)(s).size(); i++) {
    int cur = 0;
    for (int r = i;
         r < (int)(s).size() && r - i + 1 <= sqr && nxt[cur][s[r] - 'a']; r++) {
      cur = nxt[cur][s[r] - 'a'];
      if (ind[cur] >= 0) {
        found[ind[cur]].push_back(i);
      }
    }
    for (int b : big) {
      if (i + (int)(t[b]).size() <= (int)(s).size() &&
          gethash(i, i + (int)(t[b]).size() - 1) == qh[b])
        found[b].push_back(i);
    }
  }
  for (int i = 0; i < n; i++) {
    if ((int)(found[i]).size() < k[i] || (int)(t[i]).size() > (int)(s).size())
      cout << -1 << endl;
    else {
      int ans = 1e9;
      for (int j = 0; j + k[i] - 1 < (int)(found[i]).size(); j++) {
        ans =
            min(ans, found[i][j + k[i] - 1] + (int)(t[i]).size() - found[i][j]);
      }
      cout << ans << endl;
    }
  }
}
