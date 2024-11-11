#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long INF = 998244353;
const int N = 100000 + 7;
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int l = s.length();
    bool m1 = false;
    for (int i = 1; i < l; i++) {
      if (s[i] != '?' && s[i] == s[i - 1]) {
        m1 = true;
        break;
      }
    }
    if (m1) {
      cout << "-1\n";
      continue;
    }
    s.push_back('z');
    if (s[0] == '?') {
      if (s[1] != 'a')
        s[0] = 'a';
      else
        s[0] = 'b';
    }
    for (int i = 1; i < l; i++) {
      if (s[i] == '?') {
        if (s[i - 1] != 'b' && s[i + 1] != 'b') {
          s[i] = 'b';
        } else if (s[i - 1] != 'c' && s[i + 1] != 'c') {
          s[i] = 'c';
        } else if (s[i - 1] != 'a' && s[i + 1] != 'a') {
          s[i] = 'a';
        }
      }
    }
    s.pop_back();
    cout << s << "\n";
  }
  return 0;
}
