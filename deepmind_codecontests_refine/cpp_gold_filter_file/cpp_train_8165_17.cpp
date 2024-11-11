#include <bits/stdc++.h>
using namespace std;
set<long long> s;
unordered_map<long long, long long> mp;
long long a[101000], dp[1010000][2], n;
int main() {
  long long x;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> x;
    s.insert(x);
    mp[x]++;
  }
  n = s.size();
  int k = 1;
  set<long long>::iterator it;
  for (it = s.begin(); it != s.end(); it++) a[k++] = *it;
  long long maxi = 0;
  for (int i = 1; i <= n; i++) maxi = max(a[i], maxi);
  for (int i = 1; i <= maxi; i++) {
    dp[i][1] = mp[i] * i + dp[i - 1][0];
    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
  }
  cout << max(dp[maxi][1], dp[maxi][0]) << endl;
}
