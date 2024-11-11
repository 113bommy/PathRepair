#include <bits/stdc++.h>
using namespace std;
const long long MOD = (long long)1e9 + 7;
vector<long long> vec, vec2;
bool ck(long long num) {
  long long l = 2, r = min((long long)1e9 + 1, num);
  while (l + 1 < r) {
    long long mid = (l + r) / 2;
    if (mid * mid > num)
      r = mid;
    else
      l = mid;
  }
  return l * l == num;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (int i = 2; i <= 1e6; i++) {
    long long tmp = i * 1LL * i;
    while (tmp <= 1e18 / i) {
      tmp *= i;
      vec.push_back(tmp);
    }
  }
  sort(vec.begin(), vec.end());
  vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
  for (int i = 0; i < (int)vec.size(); i++) {
    if (!ck(vec[i])) vec2.push_back(vec[i]);
  }
  int t;
  long long n;
  cin >> t;
  while (t--) {
    cin >> n;
    long long ans =
        n - 1 - (upper_bound(vec2.begin(), vec2.end(), n) - vec2.begin());
    ans -= (long long)sqrt(n) - 1;
    cout << ans << "\n";
  }
  return 0;
}
