#include <bits/stdc++.h>
using namespace std;
vector<long long> fib = {1, 2};
const long long N = 1e18;
long long dp[100][2];
long long t, n;
void pre() {
  while (fib[fib.size() - 1] < N) {
    fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
  }
}
long long solver(vector<pair<long long, long long>> v) {
  dp[0][0] = v[0].second / 2;
  dp[0][1] = 1;
  for (int i = 1; i < v.size(); i++) {
    dp[i][1] = dp[i - 1][1] + dp[i - 1][0];
    long long dif = v[i].second - v[i - 1].second;
    if (dif % 2) {
      dp[i][0] = (dif / 2) * (dp[i - 1][1] + dp[i - 1][0]);
    } else {
      dp[i][0] = ((dif / 2) - 1) * dp[i - 1][1] + dif / 2 * dp[i - 1][0];
    }
  }
  return dp[v.size() - 1][0] + dp[v.size() - 1][1];
}
void decompose(long long n) {
  vector<pair<long long, long long>> dec;
  while (n != 0) {
    long long tmp = *(--lower_bound(fib.begin(), fib.end(), n));
    long long ind = (--lower_bound(fib.begin(), fib.end(), n)) - fib.begin();
    long long t = *lower_bound(fib.begin(), fib.end(), n);
    if (t == n) {
      ind++;
      swap(tmp, t);
    }
    n -= tmp;
    dec.push_back({tmp, ind + 1});
  }
  reverse(dec.begin(), dec.end());
  cout << solver(dec) << endl;
}
int main() {
  pre();
  cin >> t;
  for (long long i = 0; i < t; i++) {
    cin >> n;
    decompose(n);
  }
}
