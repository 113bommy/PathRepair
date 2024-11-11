#include <bits/stdc++.h>
using namespace std;
long long get(string a, string b) {
  long long last = 0;
  for (long long i = 0; i < b.size(); ++i) {
    auto fd = find(a.begin() + last, a.end(), b[i]);
    last = fd - a.begin() + 1;
    if (fd == a.end()) {
      return (long long)a.size() - (i) + (long long)b.size() - i;
    }
  }
  return (long long)a.size() - b.size();
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  vector<long long> pw;
  pw = {1};
  while (pw.back() <= (1LL << 38LL)) {
    pw.push_back(pw.back() * 2);
  }
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long res = s.size() + 1;
    for (auto i : pw) {
      res = min(res, get(s, to_string(i)));
    }
    cout << res << '\n';
  }
}
