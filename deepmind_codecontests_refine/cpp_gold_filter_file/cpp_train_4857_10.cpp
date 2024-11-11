#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  long long n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  vector<long long> cnt_s(26, 0), cnt_t(26, 0);
  for (long long i = 0; i < n; i++) {
    cnt_s[s[i] - 'a']++;
    cnt_t[t[i] - 'a']++;
  }
  if (cnt_s != cnt_t) {
    cout << -1 << endl;
    return 0;
  }
  vector<long long> ans;
  for (long long pos = 0; pos < n; pos++) {
    char c = t[pos];
    if (pos % 2 == 0) {
      long long p = find(s.begin(), s.begin() + (n - pos), c) - s.begin();
      long long alpha = p, betta = n - pos - 1 - p, gamma = pos;
      ans.push_back(gamma + betta);
      ans.push_back(1);
      string tmp = string(1, c);
      for (long long j = 0; j < gamma; j++) tmp.push_back(s[n - 1 - j]);
      for (long long j = 0; j < betta; j++) tmp.push_back(s[n - gamma - 1 - j]);
      for (long long i = 0; i < alpha; i++) tmp.push_back(s[i]);
      s = tmp;
    } else {
      long long p = find(s.begin() + pos, s.end(), c) - s.begin();
      long long alpha = p - pos, betta = n - p - 1, gamma = pos;
      ans.push_back(betta + 1);
      ans.push_back(n);
      ans.push_back(betta);
      string tmp = "";
      for (long long i = 0; i < betta; i++) tmp.push_back(s[n - 1 - i]);
      for (long long i = 0; i < alpha; i++) tmp.push_back(s[n - betta - 2 - i]);
      for (long long i = 0; i < gamma; i++) tmp.push_back(s[gamma - 1 - i]);
      tmp.push_back(c);
      s = tmp;
    }
  }
  if (n % 2) ans.push_back(n);
  cout << ans.size() << endl;
  ;
  for (auto e : ans) cout << e << " ";
  return 0;
}
