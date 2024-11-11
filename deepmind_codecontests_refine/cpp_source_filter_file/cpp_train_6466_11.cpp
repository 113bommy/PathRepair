#include <bits/stdc++.h>
using namespace std;
const long long oo = 1100000000000000000LL;
string Prefix(const string& s, int len) {
  if (len >= (int)s.size()) return s;
  return s.substr(0, len);
}
string Suffix(const string& s, int len) {
  if (len >= (int)s.size()) return s;
  return s.substr(s.size() - len);
}
int Count(const string& text, const string& pattern) {
  const int n = text.size();
  const int k = pattern.size();
  int cnt = 0;
  for (int i = 0; i + k <= n; ++i) {
    cnt += (text.substr(i, k) == pattern);
  }
  return cnt;
}
string pre[201];
string suf[201];
long long dp[201];
long long Count(const string& s, int n, int m) {
  const int len = s.size();
  dp[0] = Count("0", s);
  dp[1] = Count("1", s);
  for (int i = 2; i <= n; ++i) {
    dp[i] = dp[i - 2] + dp[i - 1];
    const string mid =
        (Suffix(pre[i - 2], len - 1) + Prefix(suf[i - 1], len - 1));
    dp[i] += Count(mid, s);
    if (dp[i] >= oo) {
      dp[i] = oo;
    }
  }
  return dp[n];
}
int main() {
  int n, m;
  long long k;
  scanf("%d%lld%d", &n, &k, &m);
  pre[0] = suf[0] = "0";
  pre[1] = suf[1] = "1";
  for (int i = 2; i <= n; ++i) {
    pre[i] = Prefix(pre[i - 2] + pre[i - 1], m);
    suf[i] = Suffix(suf[i - 2] + suf[i - 1], m);
  }
  string curr;
  for (int i = 0; i < m; ++i) {
    if (Suffix(suf[n], i) == curr) {
      if (k == 0) break;
      k -= 1;
    }
    curr.push_back('0');
    const long long cnt = Count(curr, n, m);
    if (k >= cnt) {
      k -= cnt;
      curr.pop_back();
      curr.push_back('1');
    }
  }
  printf("%s\n", curr.c_str());
  return 0;
}
