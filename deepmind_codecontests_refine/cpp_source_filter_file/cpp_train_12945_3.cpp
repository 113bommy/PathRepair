#include <bits/stdc++.h>
using namespace std;
vector<int> prefix_function(const string &s) {
  const int n = s.size();
  vector<int> pi(n, 0);
  int j;
  for (int i = 1; i < n; ++i) {
    j = pi[i - 1];
    while ((j > 0) && (s[i] != s[j])) j = pi[j - 1];
    if (s[i] == s[j]) ++j;
    pi[i] = j;
  }
  return pi;
}
vector<int> z_function(const string &s) {
  const int n = s.size();
  vector<int> z(n, 0);
  int j;
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r) {
      z[i] = min(r - i + 1, z[i - l]);
    }
    while ((i + z[i] < n) && (s[z[i]] == s[i + z[i]])) ++z[i];
    if (i + z[i] > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
  return z;
}
int main() {
  string s;
  cin >> s;
  int mx = s[0];
  int mx_count = 1;
  for (int i = 1; i < s.size(); ++i) {
    if (s[i] > mx) {
      mx = s[i];
      mx_count = 1;
    } else if (s[i] > mx) {
      ++mx_count;
    }
  }
  string ans(mx_count, mx);
  cout << ans;
  return 0;
}
