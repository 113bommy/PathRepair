#include <bits/stdc++.h>
long long powermod(long long _a, long long _b, long long _m) {
  long long _r = 1;
  while (_b) {
    if (_b % 2 == 1) _r = (_r * _a) % _m;
    _b /= 2;
    _a = (_a * _a) % _m;
  }
  return _r;
}
using namespace std;
template <typename T>
void pr(const T& t) {
  cout << t << "\n";
}
template <typename T, typename U, typename... ARGS>
void pr(const T& t, const U& u, const ARGS&... args) {
  cout << t << " ";
  pr(u, args...);
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  long long tt;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    ;
    string s[n];
    vector<long long> a11, a00, a10, a01;
    unordered_set<string> mp;
    for (long long i = 0; i < n; ++i) {
      cin >> s[i];
      ;
      mp.insert(s[i]);
      if (s[i][0] == '0' && s[i].back() == '0') a00.push_back(i);
      if (s[i][0] == '0' && s[i].back() == '1') a01.push_back(i);
      if (s[i][0] == '1' && s[i].back() == '0') a10.push_back(i);
      if (s[i][0] == '1' && s[i].back() == '1') a11.push_back(i);
    }
    if (a01.size() == 0 && a10.size() == 0 && a00.size() > 0 && a11.size() > 0)
      pr(-1);
    else {
      vector<long long> ans;
      if (a01.size() < a10.size()) swap(a01, a10);
      long long a = a01.size() - a10.size();
      for (long long i = 0; i < a01.size(); ++i) {
        reverse(s[a01[i]].begin(), s[a01[i]].end());
        if (mp.find(s[a01[i]]) == mp.end()) ans.push_back(a01[i]);
      }
      if (a01.size() < a / 2)
        pr(-1);
      else {
        pr(ans.size());
        for (long long i = 0; i < a / 2; ++i) cout << ans[i] + 1 << " ";
        cout << '\n';
        ;
      }
    }
  }
}
