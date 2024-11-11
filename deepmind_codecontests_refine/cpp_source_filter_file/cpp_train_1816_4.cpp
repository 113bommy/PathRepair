#include <bits/stdc++.h>
using namespace std;
bool mir[255];
string g = "AHIMOUVWXY";
int main() {
  string s;
  cin >> s;
  for (int j = 0; j < (int(g.size())); ++j) mir[g[j]] = 1;
  for (int i = 0, j = (int(s.size())) - 1; i <= j; ++i, --j) {
    if (s[i] != s[j] || !mir[s[i]]) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}
