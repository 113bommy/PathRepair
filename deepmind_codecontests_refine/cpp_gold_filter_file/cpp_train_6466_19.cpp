#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7, INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long qpow(long long a, long long n) {
  long long r = 1 % P;
  for (a %= P; n; a = a * a % P, n >>= 1)
    if (n & 1) r = r * a % P;
  return r;
}
long long inv(long long first) {
  return first <= 1 ? 1 : inv(P % first) * (P - P / first) % P;
}
inline int rd() {
  int first = 0;
  char p = getchar();
  while (p < '0' || p > '9') p = getchar();
  while (p >= '0' && p <= '9') first = first * 10 + p - '0', p = getchar();
  return first;
}
const int N = 222;
const long long M = 1e18 + 10;
int n, m, L[N][N], R[N][N], z[N];
string sl[N], sr[N], s;
long long k, len[N], dp[N];
void init(string s, int *z) {
  int mx = 0, l = 0, n = s.size();
  for (int i = 1; i <= n - 1; ++i) {
    z[i] = i < mx ? min(mx - i, z[i - l]) : 0;
    while (i + z[i] < s.size() && s[z[i]] == s[i + z[i]]) ++z[i];
    if (i + z[i] > mx) mx = i + z[i], l = i;
  }
}
long long calc() {
  int first = s.size();
  dp[0] = s == "0";
  dp[1] = s == "1";
  L[0][1] = s.back() == '0';
  R[0][1] = s[0] == '0';
  L[1][1] = s.back() == '1';
  R[1][1] = s[0] == '1';
  for (int i = 2; i <= n; ++i) {
    dp[i] = dp[i - 2] + dp[i - 1];
    if (dp[i] > M) {
      dp[i] = M;
      continue;
    }
    for (int j = 1; j <= first - 1; ++j)
      if (R[i - 2][j] && L[i - 1][first - j]) ++dp[i];
    dp[i] = min(dp[i], M);
    init(sl[i] + s, z);
    int sz = sl[i].size() + s.size();
    for (int j = 1; j <= first - 1; ++j) {
      if (sz - j >= sl[i].size()) {
        int t = min({z[sz - j], (int)sl[i].size(), j});
        L[i][j] = t == j;
      } else
        L[i][j] = 0;
    }
    init(s + sr[i], z);
    sz = s.size() + sr[i].size();
    for (int j = 1; j <= first - 1; ++j) {
      if (sz - j >= s.size()) {
        int t = min({z[sz - j], (int)sr[i].size(), j});
        R[i][j] = t == j;
      } else
        R[i][j] = 0;
    }
  }
  return dp[n];
}
int main() {
  scanf("%d%lld%d", &n, &k, &m);
  sl[0] = sr[0] = '0', sl[1] = sr[1] = '1';
  len[0] = len[1] = 1;
  for (int i = 2; i <= n; ++i) {
    len[i] = len[i - 1] + len[i - 2];
    len[i] = min(len[i], M);
    sl[i] = sl[i - 2];
    if (sl[i].size() == len[i - 2]) sl[i] += sl[i - 1];
    sr[i] = sr[i - 1];
    if (sr[i].size() == len[i - 1]) sr[i] = sr[i - 2] + sr[i];
    while (sl[i].size() > m) sl[i].pop_back();
    reverse(sr[i].begin(), sr[i].end());
    while (sr[i].size() > m) sr[i].pop_back();
    reverse(sr[i].begin(), sr[i].end());
  }
  for (int i = 1; i <= m; ++i) {
    if (s.size() <= sr[n].size() &&
        s == sr[n].substr(sr[n].size() - s.size(), s.size()) && !k)
      break;
    s.push_back('0');
    long long w = calc();
    if (k > w) {
      k -= w;
      s.back() = '1';
      w = calc();
      if (k > w) return cout << s << '\n', 0;
      if (s.size() <= sr[n].size() &&
          s == sr[n].substr(sr[n].size() - s.size(), s.size()))
        --k;
    } else if (s.size() <= sr[n].size() &&
               s == sr[n].substr(sr[n].size() - s.size(), s.size()))
      --k;
  }
  cout << s << '\n';
}
