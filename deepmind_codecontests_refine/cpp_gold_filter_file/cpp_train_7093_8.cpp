#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 500;
const long long mod = 1e9 + 7;
const long long INF = 1LL << 57;
const int LN = 22;
long long n, m, u, v, k, t, q, x, d, p, a, b, c, s;
long long dp[N];
const int MAXN = (int)5e3 + 42;
const int MAXLOG = 15;
struct suffix_array {
  pair<pair<int, int>, int> L[MAXN];
  int P[MAXLOG + 1][MAXN], n, stp, cnt, sa[MAXN];
  suffix_array() {
    n = 0;
    stp = 0;
    cnt = 0;
  }
  suffix_array(const string& s) : n(s.size()) {
    for (int i = 0; i < n; i++) P[0][i] = s[i];
    sa[0] = 0;
    for (stp = 1, cnt = 1; cnt < n; stp++, cnt <<= 1) {
      for (int i = 0; i < n; i++)
        L[i] = {{P[stp - 1][i], i + cnt < n ? P[stp - 1][i + cnt] : -1}, i};
      sort(L, L + n);
      for (int i = 0; i < n; i++)
        P[stp][L[i].second] =
            i > 0 && L[i].first == L[i - 1].first ? P[stp][L[i - 1].second] : i;
    }
    for (int i = 0; i < n; i++) sa[i] = L[i].second;
  }
  int& operator[](int idx) { return sa[idx]; }
  int lcp(int x, int y) {
    int k, ret = 0;
    if (x == y) return n - x;
    for (k = stp - 1; k >= 0 && x < n && y < n; k--)
      if (P[k][x] == P[k][y]) x += (1 << k), y += (1 << k), ret += (1 << k);
    return ret;
  }
};
string str;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> a >> b;
  cin >> str;
  suffix_array sa(str);
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) dp[i] = INF;
  for (int i = 1; i <= n; ++i) {
    dp[i] = min(dp[i], dp[i - 1] + a);
    int match = 0;
    for (int j = 1; j < i; ++j) {
      match = max(match, min(sa.lcp(i - 1, j - 1), i - j));
    }
    for (int j = i; j < i + match; ++j) {
      dp[j] = min(dp[j], dp[i - 1] + b);
    }
  }
  cout << dp[n] << endl;
}
