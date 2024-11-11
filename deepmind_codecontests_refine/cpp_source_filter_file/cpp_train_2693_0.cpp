#include <bits/stdc++.h>
using namespace std;
const int lim = 2154;
long long n;
vector<long long> s;
set<long long> st;
map<long long, pair<int, int>> mp;
long long solve();
int main() {
  bool cube = 0;
  for (long long i = 1; i <= lim; ++i) st.insert(i * i * i);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    long long p;
    cin >> p;
    if (st.find(p) != st.end())
      cube = 1;
    else
      s.push_back(p);
  }
  n = s.size();
  cout << solve() + cube << endl;
  return 0;
}
long long solve() {
  long long res = 0;
  for (int i = 0; i < n; ++i) {
    long long now = 1, tmp = s[i];
    for (long long j = 2; j * j * j <= tmp; ++j) {
      while (s[i] % (j * j * j) == 0) s[i] /= j * j * j, tmp /= j * j * j;
      if (tmp % (j * j) == 0)
        now *= j, tmp /= j * j;
      else if (s[i] % j == 0)
        now *= j * j, tmp /= j;
    }
    if ((long long)sqrt(tmp) * sqrt(tmp) == tmp)
      now *= (long long)sqrt(tmp);
    else
      now *= tmp * tmp;
    if (now < s[i])
      ++mp[min(s[i], now)].first;
    else
      ++mp[min(s[i], now)].second;
  }
  for (auto p : mp) res += max(p.second.first, p.second.second);
  return res;
}
