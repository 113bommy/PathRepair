#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
const long long SIZE = 1e6 * 2, MOD = 1e9 + 7;
vector<long long> vec;
long long q, cnt[26];
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, k;
  cin >> n >> k;
  string line;
  cin >> line;
  for (int i = 0; i < line.size(); i++) {
    cnt[line[i] - 'A']++;
  }
  long long ans = INT64_MAX;
  for (int i = 0; i < k; i++) {
    ans = min(ans, cnt[i]);
  }
  cout << ans;
  return 0;
}
