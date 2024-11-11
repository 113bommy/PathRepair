#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << " ; ";
  err(++it, args...);
  cout << endl;
}
long long N;
long long arr[200009];
long long dp[200009][4];
long long solve(long long i, long long flag) {
  if (i > N) {
    return 0;
  }
  if (dp[i][flag] != -1) return dp[i][flag];
  long long ret = arr[i];
  if (flag == 0) ret *= -1;
  if (flag == 1)
    ret = max(ret, ret + solve(i + 1, 0));
  else
    ret = max(ret, ret + solve(i + 1, 1));
  dp[i][flag] = ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  N = n - 1;
  long long brr[n + 10];
  for (long long i = 1; i <= n; i++) {
    cin >> brr[i];
  }
  for (int i = 1; i < n; i++) {
    arr[i] = abs(brr[i] - brr[i + 1]);
  }
  long long mx = -200000000000000000;
  memset(dp, -1, sizeof dp);
  for (long long i = n - 1; i >= 1; i--) {
    mx = max(mx, solve(i, 1));
  }
  cout << mx << endl;
  return 0;
}
