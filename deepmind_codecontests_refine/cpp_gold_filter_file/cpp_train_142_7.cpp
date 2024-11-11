#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
void ha() {
  string s;
  cin >> s;
  if (s.size() == 1)
    cout << s;
  else {
    vector<char> vs;
    for (int i = 0; i < s.size(); i += 2) vs.push_back(s[i]);
    sort(vs.begin(), vs.end());
    for (int i = 0; i < vs.size() - 1; ++i) cout << vs[i] << "+";
    cout << vs[vs.size() - 1];
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ha();
  return 0;
}
