#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using namespace std;
const int N = 2002, NN = 502, mod = 1e9 + 7, mod1 = 1e9 + 9, Base = 317,
          Base1 = 371;
int n, K, pw[NN], pw1[NN], lcp[N], mn[N][11], id[N];
string s[N];
struct Hash {
  vector<pair<int, int> > hs;
  Hash() {}
  Hash(const string &s) : hs(((int)(s).size()) + 1, {0, 0}) {
    for (int i = (1); i <= (((int)(s).size())); ++i)
      hs[i] = {(hs[i - 1].first * 1LL * Base + s[i - 1]) % mod,
               (hs[i - 1].second * 1LL * Base1 + s[i - 1]) % mod1};
  }
  pair<int, int> query(int l, int r) {
    pair<int, int> h = {
        hs[r].first - hs[l - 1].first * 1LL * pw[r - l + 1] % mod,
        hs[r].second - hs[l - 1].second * 1LL * pw1[r - l + 1] % mod1};
    if (h.first < 0) h.first += mod;
    if (h.second < 0) h.second += mod;
    return h;
  }
} hs[N];
int getLcp(const int &A, const int &B) {
  int l = 1, r = min(((int)(s[A]).size()), ((int)(s[B]).size()));
  while (l <= r) {
    int m = (l + r) >> 1;
    if (hs[A].query(1, m) == hs[B].query(1, m))
      l = m + 1;
    else
      r = m - 1;
  }
  return r;
}
bool cmp(const int &A, const int &B) {
  int r = getLcp(A, B);
  if (r == ((int)(s[B]).size())) return 0;
  if (r == ((int)(s[A]).size())) return 1;
  return s[A][r] < s[B][r];
}
int queryLcp(int l, int r) {
  int k = 31 - __builtin_clz(r - l + 1);
  return min(mn[l][k], mn[r - (1 << k) + 1][k]);
}
vector<int> solve(int l, int r) {
  if (l == r) return vector<int>(2, 0);
  vector<int> dp(r - l + 2, 0);
  int mid = l + 1;
  for (int i = (l + 2); i <= (r); ++i)
    if (lcp[i] < lcp[mid]) mid = i;
  vector<int> dpLeft = solve(l, mid - 1), dpRight = solve(mid, r);
  for (int i = (0); i <= (mid - l); ++i)
    for (int j = (0); j <= (r - mid + 1); ++j)
      dp[i + j] = max(dp[i + j], dpLeft[i] + dpRight[j] + i * j * lcp[mid]);
  return dp;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> K;
  for (int i = (1); i <= (n); ++i) cin >> s[i], id[i] = i, hs[i] = Hash(s[i]);
  sort(id + 1, id + 1 + n, cmp);
  for (int i = (2); i <= (n); ++i) lcp[i] = getLcp(id[i - 1], id[i]);
  cout << solve(1, n)[K];
  return 0;
}
