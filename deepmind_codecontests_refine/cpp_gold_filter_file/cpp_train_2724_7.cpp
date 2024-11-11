#include <bits/stdc++.h>
using namespace std;
int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }
void err(istream_iterator<string> it) { cout << endl; }
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << ' ';
  err(++it, args...);
}
long long n1, n2, k1, k2;
long long dp[102][102][12][12];
long long solve(long long f, long long h, long long kf, long long kh) {
  if (dp[f][h][kf][kh] != -1)
    return dp[f][h][kf][kh];
  else {
    if (f + h == 0)
      return 1;
    else {
      long long ans = 0;
      if (f > 0 and kf > 0)
        ans = (ans + solve(f - 1, h, kf - 1, k2)) % 100000000;
      if (h > 0 and kh > 0)
        ans = (ans + solve(f, h - 1, k1, kh - 1)) % 100000000;
      return dp[f][h][kf][kh] = ans;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  memset(dp, -1, sizeof(dp));
  cin >> n1 >> n2 >> k1 >> k2;
  cout << solve(n1, n2, k1, k2) << endl;
  return 0;
}
