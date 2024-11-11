#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
  std::ios_base::sync_with_stdio(0);
  cin >> s;
  if (s.size() < 3) {
    cout << "No\n";
    return 0;
  }
  for (int i = 0; i < s.size() - 3; i++) {
    if (s[i] == '.' || s[i + 1] == '.' || s[i + 2] == '.') continue;
    if (s[i] != s[i + 1] && s[i] != s[i + 2] && s[i + 1] != s[i + 2]) {
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";
}
