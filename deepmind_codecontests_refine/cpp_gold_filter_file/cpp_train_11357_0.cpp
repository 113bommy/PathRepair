#include <bits/stdc++.h>
using namespace std;
int in() {
  int x;
  scanf("%d", &x);
  return x;
}
long long lin() {
  long long x;
  scanf("%lld", &x);
  return x;
}
struct RollingHash {
  int n;
  long long mod1 = 1e9 + 7, mod2 = 1e9 + 9;
  long long base1 = 1007, base2 = 1019;
  vector<long long> hash1, hash2, pow1, pow2;
  void init(string s) {
    n = s.length();
    hash1.assign(n + 1, 0);
    hash2.assign(n + 1, 0);
    pow1.assign(n + 1, 1);
    pow2.assign(n + 1, 1);
    for (int i = 0; i < n; ++i) {
      hash1[i + 1] = (hash1[i] * base1 + s[i]) % mod1;
      hash2[i + 1] = (hash2[i] * base2 + s[i]) % mod2;
      pow1[i + 1] = (pow1[i] * base1) % mod1;
      pow2[i + 1] = (pow2[i] * base2) % mod2;
    }
  }
  pair<long long, long long> hash(int l, int r) {
    long long h1 = ((hash1[r] - hash1[l] * pow1[r - l]) % mod1 + mod1) % mod1;
    long long h2 = ((hash2[r] - hash2[l] * pow2[r - l]) % mod2 + mod2) % mod2;
    return pair<long long, long long>(h1, h2);
  }
  bool match(int l1, int r1, int l2, int r2) {
    if (r1 > n || r2 > n) return false;
    return hash(l1, r1) == hash(l2, r2);
  }
  bool match(int l1, int l2, int k) { return match(l1, l1 + k, l2, l2 + k); }
  int lcp(int l1, int l2) {
    int ok = 0, ng = n;
    while (ng - ok > 1) {
      int m = (ok + ng) / 2;
      if (match(l1, l2, m))
        ok = m;
      else
        ng = m;
    }
    return ok;
  }
};
RollingHash rh;
int len[310];
int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) cin >> s[i];
  string t;
  for (int i = 0; i < n; ++i) t += s[i];
  vector<int> h(t.length() + 1, -1);
  for (int i = 0; i < n; ++i) {
    h[len[i]] = i;
    len[i + 1] = len[i] + s[i].length();
  }
  h[len[n]] = n;
  rh.init(t);
  vector<vector<int> > same(n, vector<int>(n));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      while (i + same[i][j] < n && j + same[i][j] < n &&
             s[i + same[i][j]].length() == s[j + same[i][j]].length() &&
             rh.match(len[i + same[i][j]], len[j + same[i][j]],
                      s[i + same[i][j]].length())) {
        same[i][j]++;
      }
    }
  int ans = t.length() + n - 1, m = ans;
  for (int l = 0; l < n; ++l)
    for (int r = l + 1; r <= n; ++r) {
      int x = r - l, d = len[r] - len[l], cnt = 0;
      for (int i = 0; i < n; ++i) {
        if (same[i][l] >= x) {
          cnt++;
          i = h[len[i] + d] - 1;
        }
      }
      if (cnt > 1) {
        ans = min(ans, m - cnt * (d - 1));
      }
    }
  cout << ans << endl;
  return 0;
}
