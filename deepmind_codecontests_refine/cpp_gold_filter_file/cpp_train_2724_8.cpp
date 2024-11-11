#include <bits/stdc++.h>
using namespace std;
string to_string(char c) { return "" + c; }
string to_string(bool b) { return b ? "true" : "false"; }
template <typename A>
string to_string(vector<A> v) {
  string s = "(";
  int first = 1;
  for (A a : v) {
    if (!first) {
      s += ", ";
    }
    first = 0;
    s += to_string(a);
  }
  s += ")";
  return s;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
const long long mod = 1e8;
namespace SOLVE {
long long n1, n2, k1, k2;
vector<vector<vector<vector<long long>>>> dp(
    101, vector<vector<vector<long long>>>(
             101, vector<vector<long long>>(11, vector<long long>(11, -1))));
long long get(long long a, long long b, long long c, long long d) {
  if (a < 0 || b < 0) {
    return 0;
  }
  if (c > k1 || d > k2) {
    return 0;
  }
  if (a == 0 && b == 0) {
    return 1;
  }
  if (dp[a][b][c][d] != -1) {
    return dp[a][b][c][d];
  }
  long long ans = (get(a - 1, b, c + 1, 0) + get(a, b - 1, 0, d + 1)) % mod;
  dp[a][b][c][d] = ans;
  return ans;
}
void main() {
  cin >> n1 >> n2 >> k1 >> k2;
  cout << get(n1, n2, 0, 0) << endl;
}
}  // namespace SOLVE
signed main() {
  int t;
  t = 1;
  while (t--) {
    SOLVE::main();
  }
  return 0;
}
