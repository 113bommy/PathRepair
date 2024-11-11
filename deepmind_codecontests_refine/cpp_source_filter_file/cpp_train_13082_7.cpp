#include <bits/stdc++.h>
using namespace std;
map<long long, string> mp;
long long n;
vector<pair<long long, string> > vc;
inline void chk(string& s, const string& t) {
  if (s.size() > t.size()) s = t;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 2; i <= 100000; ++i) {
    for (long long j = i, c = 2; j <= n / i; ++c) {
      j *= i;
      string nw = to_string(i) + "^" + to_string(c);
      if (nw.size() > to_string(j).size()) continue;
      if (!mp.count(j))
        mp[j] = nw;
      else if (mp[j].size() > nw.size())
        mp[j] = nw;
      if (nw.size() < 5) vc.emplace_back(j, nw);
    }
  }
  string ans = to_string(n);
  for (auto it : mp)
    if (it.first == n)
      chk(ans, it.second);
    else if (n > it.first) {
      long long t = n / it.first, ys = n % it.first;
      string str = "";
      if (t > 1) {
        str = mp.count(t) ? mp[t] : to_string(t);
        str = str + "*" + it.second;
      } else
        str = it.second;
      if (ys == 0)
        chk(ans, str);
      else if (ys < 10000) {
        chk(ans, str + "+" + to_string(ys));
      }
      for (auto tt : vc)
        if (n >= tt.first + it.first) {
          long long m = n - tt.first;
          if (m / it.first) continue;
          t = m / it.first;
          str = "";
          if (t > 1) {
            str = mp.count(t) ? mp[t] : to_string(t);
            str = str + "*" + it.second;
          } else
            str = it.second;
          str = str + "+" + tt.second;
          chk(ans, str);
        }
    }
  cout << ans << '\n';
  return 0;
}
