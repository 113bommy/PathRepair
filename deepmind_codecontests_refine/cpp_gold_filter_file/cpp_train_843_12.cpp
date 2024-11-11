#include <bits/stdc++.h>
using namespace std;
vector<int> kmp(const string& s) {
  vector<int> pi(s.size());
  for (int i = 1; i < s.size(); i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}
vector<int> zet(const string& s) {
  vector<int> z(s.size());
  for (int i = 1, l = 0, r = 0; i < s.size(); i++) {
    if (i < r) z[i] = min(r - i, z[i - l]);
    while (i + z[i] < s.size() && s[z[i]] == s[i + z[i]]) z[i]++;
    if (i + z[i] > r) l = i, r = i + z[i];
  }
  return z;
}
long long solve(const string& s, const string& t) {
  vector<int> pi(kmp(t)), z(zet(t));
  vector<int> mx(t.size());
  for (int i = 1; i < t.size(); i++) mx[i] = max(z[i], mx[pi[i - 1]]);
  long long ans = 0;
  for (int i = 0, j = 0; i < s.size(); i++) {
    while (j > 0 && s[i] != t[j]) j = pi[j - 1];
    if (s[i] == t[j]) j++;
    if (j == t.size() || j == i + 1) j = pi[j - 1];
    ans += t.size() - mx[j];
  }
  return ans;
}
int main() {
  string s, t;
  cin >> s >> t;
  cout << solve(s, t);
  return 0;
}
