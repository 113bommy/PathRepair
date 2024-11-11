#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;
vector<string> nums;
long long fun(string s1, string s2, long long m, long long n) {
  long long j = 0;
  long long i;
  for (i = 0; i < m; i++) {
    if (s1[i] == s2[j]) {
      j++;
    }
    if (j == n) break;
  }
  return (m - j) + (n - j);
}
void testcases() {
  long long i = 1;
  long long n;
  cin >> n;
  string s = to_string(n);
  long long ans = INT_MAX;
  for (auto i : nums) {
    long long h = fun(s, i, s.size(), i.size());
    ans = min(ans, h);
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  long long i = 1;
  while (i < 100000000000) {
    nums.push_back(to_string(i));
    i = i * 2;
  }
  cin >> t;
  long long d = 1;
  while (t--) {
    testcases();
  }
}
