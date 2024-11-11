#include <bits/stdc++.h>
using namespace std;
const int nax = 1000 * 1007;
const int INF = 1e9;
long long int pow(long long int x, long long int y) {
  long long int res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  vector<int> s;
  int ans = v[0] ^ v[1];
  for (int i = 0; i < n; i++) {
    while (s.size() != 0 && s.back() < v[i]) s.pop_back();
    s.push_back(v[i]);
    if (s.size() >= 2) ans = max(ans, s[s.size() - 1] ^ s[s.size() - 2]);
  }
  s.clear();
  reverse(v.begin(), v.end());
  ans = max(ans, v[0] ^ v[1]);
  for (int i = 0; i < n; i++) {
    while (s.size() != 0 && s.back() < v[i]) s.pop_back();
    s.push_back(v[i]);
    if (s.size() >= 2) ans = max(ans, s[s.size() - 1] ^ s[s.size() - 2]);
  }
  cout << ans << endl;
}
