#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  map<char, int> m;
  int ans = 0;
  for (int i = 0; i < (s.size()); i++) ans += 2 * (m[s[i]]++) + 1;
  cout << ans << endl;
}
