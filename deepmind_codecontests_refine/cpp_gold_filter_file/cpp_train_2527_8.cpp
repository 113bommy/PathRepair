#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
vector<string> vec_splitter(string s) {
  s += ',';
  vector<string> res;
  while (!s.empty()) {
    res.push_back(s.substr(0, s.find(',')));
    s = s.substr(s.find(',') + 1);
  }
  return res;
}
void debug_out(vector<string> __attribute__((unused)) args,
               __attribute__((unused)) long long int idx,
               __attribute__((unused)) long long int LINE_NUM) {
  cout << '\n';
}
template <typename Head, typename... Tail>
void debug_out(vector<string> args, long long int idx, long long int LINE_NUM,
               Head H, Tail... T) {
  if (idx > 0)
    cout << ", ";
  else
    cout << "Line(" << LINE_NUM << ") ";
  stringstream ss;
  ss << H;
  cout << args[idx] << " = " << ss.str();
  debug_out(args, idx + 1, LINE_NUM, T...);
}
const long long int mod = 1000000007;
const long long int inf = 1e18;
const long long int N = 2e5 + 5;
long long int dp[N][5];
string s;
long long int n;
string abc = "abc";
long long int go(long long int idx, long long int pos) {
  if (pos > 3LL) {
    return 0;
  }
  if (idx == n) {
    return (pos == 3LL);
  }
  long long int &ans = dp[idx][pos];
  if (ans != -1) return ans;
  ans = 0;
  if (s[idx] != '?') {
    if (s[idx] == abc[pos]) {
      ans += go(idx + 1, pos + 1);
      ans %= mod;
    }
    ans += go(idx + 1, pos);
    ans %= mod;
  } else {
    for (char x = 'a'; x <= 'c'; x++) {
      if (x == abc[pos]) {
        ans += go(idx + 1, pos + 1);
        ans %= mod;
      }
      ans += go(idx + 1, pos);
      ans %= mod;
    }
  }
  return ans;
}
void HyperBeast() {
  memset(dp, -1, sizeof(dp));
  cin >> n >> s;
  cout << go(0, 0);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int T = 1;
  for (long long int ti = 1; ti <= T; ti++) {
    HyperBeast();
    cout << '\n';
  }
}
