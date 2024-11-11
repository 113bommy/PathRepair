#include <bits/stdc++.h>
using namespace std;
long long power(long long first, long long n) {
  long long result = 1;
  while (n > 0) {
    if (n % 2 == 1) result = (result * first) % 1000000007;
    first = (first * first) % 1000000007;
    n = n / 2;
  }
  return result % 1000000007;
}
long long val[10][100005], len[10][100005];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  long long n;
  cin >> n;
  vector<pair<long long, string>> v(n);
  for (long long i = 0; i < n; i++) {
    string s;
    cin >> s;
    v[i].first = s[0] - '0';
    v[i].second = s.substr(3, s.length());
    reverse((v[i].second).begin(), (v[i].second).end());
  }
  for (long long i = 0; i < 10; i++) val[i][n] = i, len[i][n] = 1;
  for (long long i = n - 1; i >= 0; i--) {
    long long dig = v[i].first;
    for (long long ii = 0; ii < 10; ii++) {
      if (ii == dig) {
        for (char c : v[i].second)
          len[dig][i] = (len[dig][i] + len[c - '0'][i + 1]) % (1000000007 - 1);
        if (v[i].second == "") {
          val[dig][i] = 0;
          continue;
        }
        val[dig][i] = val[v[i].second[0] - '0'][i + 1];
        long long psum = (len[v[i].second[0] - '0'][i + 1]) % (1000000007 - 1);
        for (long long j = 1; j < v[i].second.length(); j++) {
          val[dig][i] = (val[dig][i] +
                         (power(10, psum) * val[v[i].second[j] - '0'][i + 1]) %
                             1000000007) %
                        1000000007;
          psum = (psum + len[v[i].second[j] - '0'][i + 1]) % (1000000007 - 1);
        }
      } else
        val[ii][i] = val[ii][i + 1], len[ii][i] = len[ii][i + 1];
    }
  }
  reverse((s).begin(), (s).end());
  long long ans = val[s[0] - '0'][0],
            psum = (len[s[0] - '0'][0]) % (1000000007 - 1);
  for (long long j = 1; j < s.length(); j++) {
    ans = (ans + (power(10, psum) * val[s[j] - '0'][0]) % 1000000007) %
          1000000007;
    psum = (psum + len[s[j] - '0'][0]) % (1000000007 - 1);
  }
  cout << ans;
}
