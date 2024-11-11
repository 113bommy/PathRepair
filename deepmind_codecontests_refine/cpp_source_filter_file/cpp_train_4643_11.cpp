#include <bits/stdc++.h>
using namespace std;
const int Z = (int)3e3 + 111;
const int N = (int)3e5 + 111;
const int INF = (int)1e9 + 111;
const int MOD = (int)1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<char> u, t;
  string s;
  cin >> s;
  int n = s.length();
  vector<int> a(26, 0);
  for (int i = 0; i < n; i++) a[s[i] - 'a']++;
  for (int i = 0; i < n; i++) {
    int mn = 0;
    for (int j = 25; j >= 0; j--)
      if (a[j]) mn = j;
    while (!t.empty() && t.back() - 'a' == mn) {
      u.push_back(t.back());
      t.pop_back();
    }
    while (s[i] - 'a' != mn && i < n) {
      t.push_back(s[i]);
      a[s[i] - 'a']--;
      i++;
    }
    while (s[i] - 'a' == mn && i < n) {
      u.push_back(s[i]);
      a[s[i] - 'a']--;
      i++;
    }
    i--;
  }
  while (!t.empty()) {
    u.push_back(t.back());
    t.pop_back();
  }
  for (int i = 0; i < u.size(); i++) cout << u[i];
  return 0;
}
