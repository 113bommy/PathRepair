#include <bits/stdc++.h>
using namespace std;
long long n;
long long memo[20000001];
long long res = 0;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    string s;
    cin >> s;
    long long cur = 0;
    for (long long j = 0; j < s.size(); j++) {
      long long k = (s[j] - 'a');
      cur |= (1 << k);
    }
    memo[cur]++;
  }
  for (long long i = 0; i < 24; i++)
    for (long long bitmask = 0; bitmask < (1 << 24); bitmask++)
      if ((1 << i) & bitmask) memo[bitmask] += memo[bitmask ^ (1 << i)];
  for (long long bitmask = 0; bitmask < (1 << 24); bitmask++) {
    long long cur = (((1 << 24) - 1) ^ bitmask);
    long long z = n - memo[cur];
    res = res ^ (z * z);
  }
  cout << res;
}
