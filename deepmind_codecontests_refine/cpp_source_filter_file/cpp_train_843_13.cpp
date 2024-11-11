#include <bits/stdc++.h>
using namespace std;
vector<int> lps(string& str) {
  int n = str.size();
  vector<int> ans(n + 1);
  int i = 1;
  int l = 0;
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
vector<int> z_alg(string& s) {
  int n = s.size();
  int l = 0;
  int r = 0;
  vector<int> z(n);
  for (int i = 1; i < n; i++) {
    if (i < r) z[i] = min(r - i, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
    if (i + z[i] > r) {
      r = i + z[i];
      l = i;
    }
  }
  return z;
}
vector<int> sub_counter(string& s, string& t) {
  int nt = t.size();
  int ns = s.size();
  vector<int> match(nt);
  vector<int> psv = lps(t);
  int j = 0;
  for (int i = 1; i < ns; i++) {
    if (j == nt) j = psv[j];
    while (j > 0 && s[i] != t[j]) j = psv[j];
    if (s[i] == t[j]) j++;
    match[j]++;
  }
  for (int i = nt - 1; i > 0; i--) match[psv[i]] += match[i];
  return match;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s, t;
  cin >> s >> t;
  vector<int> lps_t = lps(t);
  vector<int> match = sub_counter(s, t);
  long long acc = 0;
  for (int i = 1; i <= (int)t.size(); i++) {
    acc += s.size();
    if (lps_t[i] > 0 && i - lps_t[i] < (int)s.size()) {
      acc -= match[i - lps_t[i]];
    }
  }
  cout << acc << '\n';
  return 0;
}
