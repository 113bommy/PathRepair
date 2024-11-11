#include <bits/stdc++.h>
using namespace std;
string s, str;
int n;
vector<string> in;
int last[100010][10];
int lastd[10];
pair<long long, long long> dp[100010];
long long pot(long long a, long long b) {
  if (b == 0) return 1LL;
  if (b % 2 == 0) {
    long long x = pot(a, b / 2);
    return (x % 1000000007 * x % 1000000007) % 1000000007;
  }
  return (a % 1000000007 * pot(a, b - 1) % 1000000007) % 1000000007;
}
pair<long long, long long> solve(int curr) {
  if (in[curr].size() == 3) return make_pair(0LL, 0LL);
  pair<long long, long long>& ret = dp[curr];
  if (ret != make_pair(-1LL, -1LL)) {
    return ret;
  }
  ret = make_pair(0LL, 0LL);
  for (int i = in[curr].size() - 1; i >= 3; --i) {
    int digit = in[curr][i] - '0';
    if (last[curr][digit] != -1) {
      pair<long long, long long> ret2 = solve(last[curr][digit]);
      if (ret2 == make_pair(0LL, 0LL)) {
        continue;
      } else {
        ret.first =
            (ret.first % 1000000007 +
             (ret2.first % 1000000007 * pot(10, ret.second) % 1000000007) %
                 1000000007) %
            1000000007;
        ret.second =
            (ret.second % (1000000007 - 2) + ret2.second % (1000000007 - 2)) %
            (1000000007 - 2);
      }
    } else {
      ret.first = (ret.first % 1000000007 +
                   (digit * pot(10, ret.second)) % 1000000007) %
                  1000000007;
      ret.second++;
      ret.second %= (1000000007 - 2);
    }
  }
  return ret;
}
int main(void) {
  cin >> s >> n;
  for (int i = 0; i < n; ++i) {
    cin >> str;
    in.push_back(str);
  }
  memset(last, -1, sizeof last);
  memset(lastd, -1, sizeof lastd);
  for (int i = in.size() - 1; i >= 0; --i) {
    int digit = in[i][0] - '0';
    for (int j = 0; j <= 9; ++j) last[i][j] = lastd[j];
    lastd[digit] = i;
  }
  int qnt = 0;
  long long answ = 0;
  memset(dp, -1, sizeof dp);
  for (int i = s.size() - 1; i >= 0; --i) {
    int digit = s[i] - '0';
    if (lastd[digit] != -1) {
      pair<long long, int> ret = solve(lastd[digit]);
      answ =
          (answ % 1000000007 +
           (ret.first % 1000000007 * pot(10, qnt) % 1000000007) % 1000000007) %
          1000000007;
      qnt = (qnt % (1000000007 - 2) + ret.second % (1000000007 - 2)) %
            (1000000007 - 2);
    } else {
      answ = (answ % 1000000007 +
              (digit % 1000000007 * pot(10, qnt) % 1000000007) % 1000000007) %
             1000000007;
      qnt++;
      qnt %= (1000000007 - 2);
    }
  }
  cout << answ << "\n";
  return 0;
}
