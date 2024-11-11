#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int> > v;
long long dp[2][5001][51][51];
const long long oo = 1e16;
int main() {
  cin >> n;
  v.resize(n);
  for (auto &x : v) cin >> x.first;
  int total = 0;
  for (auto &x : v) {
    cin >> x.second;
    total += x.second;
  }
  vector<int> bef(n, 1);
  sort(v.rbegin(), v.rend());
  for (int i = 1; i < n; ++i)
    if (v[i - 1].first == v[i].first) bef[i] += bef[i - 1];
  bef.push_back(1);
  v.push_back(make_pair(-1, -1));
  for (int i = n; i >= 0; --i) {
    for (int rem = total; rem >= 0; --rem) {
      for (int g = 0; g <= i; ++g) {
        int me = bef[i];
        for (int cg = 0; cg < me; ++cg) {
          long long ret = oo;
          if (i == n) {
            if (rem == 0) ret = 0;
          } else {
            const bool ch = v[i + 1].first != v[i].first;
            if (g > 0) {
              if (ch)
                ret = dp[1 & ~i][rem][g - 1 + cg][0];
              else
                ret = dp[1 & ~i][rem][g - 1][cg];
            }
            if (rem >= v[i].second) {
              if (ch)
                ret =
                    min(ret, v[i].first +
                                 dp[1 & ~i][rem - v[i].second][g + cg + 1][0]);
              else
                ret = min(
                    ret, v[i].first + dp[1 & ~i][rem - v[i].second][g][cg + 1]);
            }
          }
          dp[i & 1][rem][g][cg] = ret;
        }
      }
    }
  }
  pair<long long, long long> ans;
  long long res = -1;
  for (int i = 1; i <= total; ++i) {
    long long cur = dp[0][i][0][0];
    if (cur == oo) continue;
    if (res == -1) {
      ans.first = cur;
      ans.second = i;
      res = 0;
    } else {
      if (ans.first * i <= cur * ans.second) continue;
      ans.first = cur;
      ans.second = i;
    }
  }
  res = ans.first * 10000;
  res = (res + ans.second - 1) / ans.second;
  int add = res % 10 > 0;
  res = res / 10 + add;
  cout << res << endl;
  return 0;
}
