#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y) { return (!y ? x : gcd(y, x % y)); }
const int maxn = 1e6 + 10;
const int mod = 1e9 + 7;
int base1 = 41111;
int base2 = 100003;
inline int ad(int x, int y) {
  x += y;
  if (x < mod) return x;
  return x - mod;
}
inline int mu(int x, int y) { return 1LL * x * y % mod; }
int pw1[maxn], pw2[maxn];
int hs1[maxn], hs2[maxn];
string s;
void prep() {
  pw1[0] = pw2[0] = 1;
  for (int i = 1; i < maxn; i++) {
    pw1[i] = mu(pw1[i - 1], base1);
    pw2[i] = mu(pw2[i - 1], base2);
  }
  int n = s.size();
  for (int i = 1; i <= n; i++) {
    hs1[i] = ad(mu(hs1[i - 1], base1), (int)s[i - 1] + 21);
    hs2[i] = ad(mu(hs2[i - 1], base2), (int)s[i - 1] + 21);
  }
}
inline pair<int, int> get_hash(int l, int r) {
  int h1 = ad(hs1[r], mod - mu(pw1[r - l], hs1[l]));
  int h2 = ad(hs2[r], mod - mu(pw2[r - l], hs2[l]));
  return {h1, h2};
}
inline bool iseq(int l1, int r1, int l2, int r2) {
  if (r1 - l1 != r2 - l2) return false;
  auto t1 = get_hash(l1, r1);
  auto t2 = get_hash(l2, r2);
  return (t1 == t2);
}
int p[maxn], cnt[2];
int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0);
  string pat;
  cin >> pat;
  cin >> s;
  int n = s.size(), m = pat.size();
  for (int i = 0; i < m; i++) {
    p[i] = (pat[i] == pat[0] ? 0 : 1);
    cnt[p[i]]++;
  }
  vector<pair<int, int> > go;
  for (int i = 0; i < m; i++) {
    if (!i || p[i] != p[i - 1]) {
      int cc = 0;
      for (int j = i; j < m && p[j] == p[i]; j++) cc++;
      go.push_back({p[i], cc});
    }
  }
  prep();
  int jav = 0;
  for (int sz = 1; sz < n; sz++) {
    long long rem = n - 1LL * sz * cnt[0];
    if (rem < 0LL || rem % cnt[1] != 0) continue;
    long long sz2 = rem / cnt[1];
    int cur = 0;
    pair<int, int> h[2];
    h[0] = {-1, -1};
    h[1] = {-1, -1};
    int Sz[2];
    Sz[0] = sz;
    Sz[1] = sz2;
    bool ans = 1;
    for (int i = 0; i < (int)go.size(); i++) {
      auto t = go[i];
      int x = t.first, ted = t.second;
      if (h[x].first == -1) {
        h[x] = get_hash(cur, cur + Sz[x]);
      } else if (h[x] != get_hash(cur, cur + Sz[x])) {
        ans = 0;
        break;
      }
      int len = ted * Sz[x];
      if (!iseq(cur, cur + len - Sz[x], cur + Sz[x], cur + len)) {
        ans = 0;
        break;
      }
      cur += len;
    }
    if (h[0] == h[1]) ans = 0;
    jav += ans;
  }
  cout << jav << '\n';
}
