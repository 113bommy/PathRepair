#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
const int mod = 1e9 + 7;
const long long inf = 1e18 + 5;
const long double pi = 3.1415926535897932384626433;
const long double eps = 1e-12;
const int oo = 1e9;
long long fast_pow(long long a, long long b) {
  long long res = a, ret = 1;
  while (b > 0) {
    if (b % 2) ret = (ret * res) % mod;
    res = (res * res) % mod;
    b /= 2;
  }
  return ret;
}
pair<long long, long long> solve(string s) {
  long long ans1 = 0, ans2 = 0;
  int cnt1[2], cnt2[2];
  cnt1[0] = cnt1[1] = cnt2[0] = cnt2[1] = 0;
  for (int i = 0; i < ((int)(s).size()); ++i) {
    ans2++;
    int j = s[i] - 'a';
    if (i % 2 == 0) {
      ans2 += cnt1[j];
      ans1 += cnt2[j];
      cnt1[j]++;
    } else {
      ans2 += cnt2[j];
      ans1 += cnt1[j];
      cnt2[j]++;
    }
  }
  return make_pair(ans1, ans2);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  pair<long long, long long> ans = solve(s);
  cout << ans.first << " " << ans.second << endl;
  return 0;
}
