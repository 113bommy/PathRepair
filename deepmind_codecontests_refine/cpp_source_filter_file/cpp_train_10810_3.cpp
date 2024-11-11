#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 1; 2 * i < s.size(); ++i) {
    if (s.substr(0, i) == s.substr(i, i)) ans = i;
  }
  cout << ans << endl;
}
