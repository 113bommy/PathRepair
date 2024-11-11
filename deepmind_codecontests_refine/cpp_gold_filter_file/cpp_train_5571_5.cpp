#include <bits/stdc++.h>
using namespace std;
template <class T>
T max(T a, T b, T c) {
  return max(a, max(b, c));
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long n;
  cin >> n;
  long long ans = -1e18 + 5;
  map<long long, long long> m;
  while (n--) {
    long long temp;
    cin >> temp;
    m[temp]++;
    m[temp + 1]++;
    m[temp - 1] = 0;
    m[temp + 2] = 0;
    ans = max(ans, m[temp], m[temp + 1]);
  }
  cout << ans << '\n';
  return 0;
}
