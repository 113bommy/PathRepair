#include <bits/stdc++.h>
const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;
const long long mod = 1e9 + 7;
using namespace std;
string s;
long long fun(string s) {
  int cur = 0;
  for (int i = 0; i < s.size(); i++) cur *= 2, cur += s[i] - '0';
  vector<int> a;
  for (int i = 0; i < 1 << (s.size()); i++) {
    a.push_back(i ^ cur);
  }
  int ans = 0;
  for (int i = 0; i < a.size(); i++)
    for (int j = i + 1; j < a.size(); j++)
      if (a[i] > a[j]) ans++;
  return ans;
}
long long gun(int pos, int pt) {
  if (pos == s.size()) return 0;
  if (s[pos] == '0') return 2 * gun(pos + 1, pt - 1);
  if (s[pos] == '1') {
    long long pls = 1;
    for (int i = 1; i < pt; i++) pls = (pls + pls) % mod;
    (pls *= pls) %= mod;
    return (2 * gun(pos + 1, pt - 1) + pls) % mod;
  }
}
int main(int argc, const char* argv[]) {
  cin >> s;
  cout << gun(0, s.size());
  return 0;
}
