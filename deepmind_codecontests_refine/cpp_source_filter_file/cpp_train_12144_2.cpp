#include <bits/stdc++.h>
using namespace std;
int n, k, f[33];
double ans = 0;
vector<int> v[33];
string s;
template <class T>
ostream& operator<<(ostream& out, vector<T> v) {
  out << v.size() << '\n';
  for (auto e : v) out << e << ' ';
  return out;
}
double check(int k) {
  double ans = 0, local;
  for (int i = 0; i < n; i++) {
    memset(f, 0, sizeof f);
    for (auto j : v[k]) {
      f[s[(j + i) % n] - 'a']++;
    }
    local = 0;
    for (int i = 0; i < 'z' - 'a'; i++)
      if (f[i] == 1) local += (double)1. / v[k].size();
    ans = max(ans, local);
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> s;
  n = s.size();
  for (int i = 0; i < s.size(); i++) v[s[i] - 'a'].push_back(i);
  for (int i = 0; i <= 'z' - 'a'; i++) {
    ans += ((double)v[i].size() / n) * check(i);
  }
  cout << fixed << setprecision(13) << ans << '\n';
}
