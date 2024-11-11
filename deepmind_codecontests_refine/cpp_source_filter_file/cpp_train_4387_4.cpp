#include <bits/stdc++.h>
using namespace std;
inline void boost() {
  ios_base::sync_with_stdio();
  cin.tie(0);
}
const long long MAX = 1e5 + 111;
const long long mod = 1e9 + 7;
map<string, int> maap;
vector<int> g[MAX];
int main() {
  boost();
  string s, s1, s2, s3, s4, s5, s6;
  cin >> s;
  cin >> s2 >> s4 >> s5 >> s6;
  s1 = s2 + s3 + s4 + s5 + s6;
  for (int i = 0; i < s1.size(); i += 2) {
    if (s1[i] == s[0]) {
      cout << "YES";
      return 0;
    }
  }
  for (int i = 1; i < s1.size(); i += 2) {
    if (s1[i] == s[1]) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  exit(0);
}
