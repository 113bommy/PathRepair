#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}
const long long maxn = (long long)110;
const long long maxm = (long long)52;
const int LOGN = 22;
const long long INF = 1e9 + 10;
const long long MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double EPS = 1e-12;
vector<int> GetNxt(const string& str) {
  int n = str.size();
  vector<int> nxt(n, 0);
  int len = 0;
  for (int i = 1; i < n; ++i) {
    while (len != 0 && str[i] != str[len]) len = nxt[len - 1];
    if (str[i] == str[len]) ++len;
    nxt[i] = len;
  }
  return nxt;
}
vector<vector<int>> LCP(const string& s1, const string& s2) {
  int n1 = s1.size(), n2 = s2.size();
  vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
  for (int i = n1 - 1; i >= 0; --i) {
    for (int j = n2 - 1; j >= 0; --j) {
      if (s1[i] == s2[j]) {
        dp[i][j] = dp[i + 1][j + 1] + 1;
      } else {
        dp[i][j] = 0;
      }
    }
  }
  return dp;
}
unsigned long long MUL = 11;
vector<unsigned long long> GetPrefixHash(const string& s) {
  int n = s.size();
  vector<unsigned long long> ans(n, 0);
  for (int i = 0; i < n; ++i) {
    if (i > 0) {
      ans[i] = ans[i - 1] * MUL + (s[i] - 'a' + 1);
    } else {
      ans[i] = s[i] - 'a' + 1;
    }
  }
  return ans;
}
unsigned long long GetSubstrHash(const vector<unsigned long long>& prefix_hash,
                                 int i, int j) {
  static vector<unsigned long long> mul;
  if (mul.empty()) {
    int n = prefix_hash.size();
    mul.resize(n, 0);
    mul[0] = 1;
    for (int i = 1; i < n; ++i) mul[i] = mul[i - 1] * MUL;
  }
  return prefix_hash[j] - (i == 0 ? 0 : prefix_hash[i - 1]) * mul[j - i];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s, s1, s2;
  cin >> s >> s1 >> s2;
  int n = s.size();
  int n1 = s1.size(), n2 = s2.size();
  auto hash = GetPrefixHash(s);
  auto dp1 = LCP(s, s1);
  auto dp2 = LCP(s, s2);
  unordered_set<unsigned long long> d;
  for (int i = 0; i < n; ++i)
    if (dp1[i][0] == n1) {
      for (int j = i; j < n; ++j)
        if (dp2[j][0] == n2 && i + n1 <= j + n2) {
          auto code = GetSubstrHash(hash, i, j);
          d.insert(code);
        }
    }
  cout << d.size() << endl;
  return 0;
}
