#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<long long, int> l, pair<long long, int> r) {
  return l.first < r.first;
}
long long fastexpo(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b % 2 == 1) res = ((res) % 1000000007 * (a) % 1000000007) % 1000000007;
    a = ((a) % 1000000007 * (a) % 1000000007) % 1000000007;
    b /= 2;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  string s;
  cin >> s;
  int n;
  cin >> n;
  vector<string> queries(n + 1);
  vector<int> a(n + 1, 0);
  string t;
  for (int i = 1; i <= n; i++) {
    cin >> queries[i];
    ;
    a[i] = queries[i][0] - '0';
    queries[i] = queries[i].substr(3);
  }
  queries[0] = s;
  vector<long long> dp(10);
  vector<long long> len(10);
  for (int i = 0; i <= 9; i++) {
    dp[i] = i;
    len[i] = 1;
  }
  for (int i = n; i >= 0; i--) {
    int node = a[i];
    long long tempval = dp[a[i]];
    long long templen = len[a[i]];
    dp[node] = 0;
    len[node] = 0;
    for (int j = queries[i].length() - 1; j >= 0; j--) {
      long long add = dp[queries[i][j] - '0'];
      long long addlen = len[queries[i][j] - '0'];
      if (queries[i][j] - '0' == node) {
        add = tempval;
        addlen = templen;
      }
      dp[node] += ((long long)1 * (add) % 1000000007 *
                   (fastexpo(10, len[node]) % 1000000007)) %
                  1000000007;
      if (dp[node] >= 1000000007) dp[node] -= 1000000007;
      len[node] += addlen;
      len[node] = len[node] % 1000000007;
    }
  }
  cout << dp[0];
  return 0;
}
