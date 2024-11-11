#include <bits/stdc++.h>
using namespace std;
const int MD = 1e9 + 7;
int n, m, k, lst[27], ind[27];
long long sum, dp[27];
set<pair<int, int> > s;
string str;
int main() {
  cin >> m >> k;
  cin >> str;
  n = str.size();
  sum = 1;
  memset(ind, -1, sizeof(ind));
  for (int i = 0; i < k; i++) s.insert({-1, i});
  for (int i = 1; i <= n; i++) {
    long long presum = sum;
    sum = 2 * sum - dp[(int)(str[i - 1]) - 97];
    sum %= MD;
    sum += MD;
    sum %= MD;
    dp[(int)(str[i - 1]) - 97] += (sum - presum);
    dp[(int)(str[i - 1]) - 97] %= MD;
    s.erase(s.find({ind[(int)(str[i - 1]) - 97], (int)(str[i - 1]) - 97}));
    ind[(int)(str[i - 1]) - 97] = i;
    s.insert({ind[(int)(str[i - 1]) - 97], (int)(str[i - 1]) - 97});
  }
  for (int i = 1; i <= m; i++) {
    int x = s.begin()->second;
    s.erase(s.begin());
    long long presum = sum;
    sum = 2 * sum - dp[x];
    sum %= MD;
    sum += MD;
    sum %= MD;
    dp[x] += (sum - presum);
    dp[x] %= MD;
    ind[x] = i + n;
    s.insert({ind[x], x});
  }
  cout << sum << '\n';
}
