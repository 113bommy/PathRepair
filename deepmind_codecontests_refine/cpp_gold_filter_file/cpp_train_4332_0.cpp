#include <bits/stdc++.h>
using namespace std;
signed main() {
  string s, t;
  cin >> s >> t;
  std::vector<long long> tc(26, 0), sc(26, 0);
  long long qc = count(s.begin(), s.end(), '?');
  for (auto i : t) tc[i - 'a']++;
  for (auto i : s) {
    if (i != '?') sc[i - 'a']++;
  }
  long long l = 0, r = 1e8, f = 0;
  while (r - l) {
    if (r - l <= 1) f = 1;
    long long m = ((unsigned long long)r + (unsigned long long)l) >> 1;
    long long cnt = 0;
    for (long long i = 0; i < 26; i++) {
      if (sc[i] < tc[i] * m) cnt += (m * tc[i] - sc[i]);
    }
    if (cnt <= qc)
      l = m;
    else
      r = m;
    if (f) break;
  }
  for (long long i = 0; i < s.size(); i++) {
    if (s[i] == '?') {
      for (long long j = 0; j < 26; j++) {
        if (sc[j] < tc[j] * l) {
          s[i] = char(j + 97), sc[j]++;
          break;
        }
      }
    }
  }
  for (long long i = 0; i < s.size(); i++) {
    if (s[i] == '?') s[i] = 'a';
  }
  std::cout << s << std::endl;
  return 0;
}
