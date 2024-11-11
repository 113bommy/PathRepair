#include <bits/stdc++.h>
using namespace std;
const long long inf = 10000000000000001;
long long n, m, k = 0, q;
string s;
map<string, int> mp;
bool is_lucky(string x) {
  for (int i = 0; i < x.length(); i++)
    if (x[i] != '4' && x[i] != '7') return 0;
  return 1;
}
int main() {
  cin >> s;
  n = s.length();
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < n - i; j++) {
      string str = "";
      for (int u = j; u <= j + i - 1; u++) {
        str.push_back(s[u]);
      }
      mp[str]++;
    }
  }
  int cnt = 0;
  s = "-1";
  for (auto x : mp) {
    if (is_lucky(x.first)) {
      if (cnt < x.second) {
        cnt = x.second;
        s = x.first;
      }
    }
  }
  cout << s;
  return 0;
}
