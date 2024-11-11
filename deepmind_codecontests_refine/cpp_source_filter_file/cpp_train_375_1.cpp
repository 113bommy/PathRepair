#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2>
void chmin(T1 &a, T2 b) {
  if (a > b) a = b;
}
template <class T1, class T2>
void chmax(T1 &a, T2 b) {
  if (a < b) a = b;
}
using Pi = pair<long long, long long>;
using Ti = tuple<long long, long long, long long>;
using vint = vector<long long>;
const long long inf = 1LL << 55;
const long long mod = 1e9 + 7;
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);
  string s;
  cin >> s;
  long long n = s.size();
  vector<Pi> vec;
  vec.emplace_back(s[0], 1);
  for (long long i = (long long)(1); i < (long long)(n); i++) {
    if (vec.back().first == s[i])
      vec.back().second++;
    else
      vec.emplace_back(s[i], 1);
  }
  long long ans = 0;
  while (1) {
    if (vec.size() <= 1) break;
    ans++;
    vector<Pi> tmp;
    long long m = vec.size();
    for (long long i = (long long)(0); i < (long long)(m); i++) {
      if (i == 0 || i == m - 1)
        vec[i].second--;
      else
        vec[i].second -= 2;
      if (vec[i].second <= 0) continue;
      if (!tmp.empty() && tmp.back().first == vec[i].first)
        tmp.back().first += vec[i].second;
      else
        tmp.emplace_back(vec[i]);
    }
    vec = tmp;
  }
  cout << ans << endl;
  return 0;
}
