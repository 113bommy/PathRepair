#include <bits/stdc++.h>
using namespace std;
vector<int> calc_z(string s) {
  int n = s.length();
  int l = 0;
  int r = 0;
  vector<int> z(n, 0);
  for (int i = 1; i < n; ++i) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
  return z;
}
int n;
string s;
vector<int> z, v;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> s;
  n = s.length();
  if (n < 3) {
    cout << "Just a legend";
    return 0;
  }
  s = s + "#" + s.substr(1, n - 2);
  z = calc_z(s);
  for (int i = 1; i < n - 1; ++i)
    if (i + z[i] == n) v.push_back(z[i]);
  int ma = *max_element(z.begin() + n, z.end());
  for (int i = 0; i < v.size(); ++i) {
    if (v[i] <= ma) {
      cout << s.substr(0, v[i]);
      return 0;
    }
  }
  cout << "Just a legend";
  return 0;
}
