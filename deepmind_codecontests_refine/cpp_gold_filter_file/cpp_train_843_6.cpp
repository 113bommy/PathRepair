#include <bits/stdc++.h>
using namespace std;
vector<long long> lps(string& str) {
  long long n = str.size();
  vector<long long> ans(n + 1);
  long long i = 1;
  long long l = 0;
  while (i < n) {
    if (str[i] == str[l]) {
      ans[++i] = ++l;
      continue;
    }
    if (l > 0) {
      l = ans[l];
      continue;
    }
    ans[++i] = 0;
  }
  return ans;
}
vector<long long> z_alg(string& s) {
  long long n = s.size();
  long long l = 0;
  long long r = 0;
  vector<long long> z(n);
  for (long long i = 1; i < n; i++) {
    if (i < r) z[i] = min(r - i, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
    if (i + z[i] > r) {
      r = i + z[i];
      l = i;
    }
  }
  return z;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s, t;
  cin >> s >> t;
  vector<long long> lps_t = lps(t);
  string ts = t + '$' + s;
  vector<long long> z = z_alg(ts);
  vector<long long> match(s.size(), 0);
  for (long long i = 1; i < (long long)s.size(); i++) {
    match[z[t.size() + 1 + i]]++;
  }
  for (long long i = s.size() - 1; i > 0; i--) match[i - 1] += match[i];
  long long acc = 0;
  for (long long i = 1; i <= (long long)t.size(); i++) {
    acc += s.size();
    if (lps_t[i] > 0 && i - lps_t[i] < (int)s.size()) {
      acc -= match[i - lps_t[i]];
    }
  }
  cout << acc << '\n';
  return 0;
}
