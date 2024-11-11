#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e5 + 5;
long long int d, s;
long long int dp[501][5001];
long long int solve() {
  queue<pair<pair<long long int, long long int>, string> > Q;
  for (long long int i = 1; i < 10; ++i) {
    char c = '0' + i;
    string t;
    t += c;
    if (i % d == 0 && i == s) {
      cout << i << "\n";
      return 0;
    }
    if (i < s) Q.push(make_pair(make_pair(i % d, i), t));
  }
  memset(dp, -1, sizeof(dp));
  for (long long int i = 0; i < 100000; ++i) {
    queue<pair<pair<long long int, long long int>, string> > Q2;
    while (!Q.empty()) {
      pair<pair<long long int, long long int>, string> P = Q.front();
      long long int r = P.first.first;
      long long int sum = P.first.second;
      for (long long int j = 0; j < 10; ++j) {
        long long int r2 = (r * 10 + j) % d;
        long long int s2 = sum + j;
        if (s2 > s) continue;
        if (dp[r2][s2] == -1) {
          char c = '0' + j;
          string t = P.second;
          t += c;
          if (s2 == s && r2 == 0) {
            cout << t << "\n";
            return 0;
          } else if (s2 < s) {
            Q2.push(make_pair(make_pair(r2, s2), t));
          }
          dp[r2][s2] = 1;
        }
      }
      Q.pop();
    }
    Q = Q2;
    while (!Q2.empty()) {
      pair<pair<long long int, long long int>, string> P = Q2.front();
      Q2.pop();
    }
  }
  cout << -1 << "\n";
  return 0;
}
int main() {
  cin >> d >> s;
  solve();
  return 0;
}
