#include <bits/stdc++.h>
using namespace std;
string s, t;
string doi(int x) {
  stringstream ss;
  ss << x;
  return ss.str();
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> s >> t;
  if (s.size() != t.size()) {
    cout << "WRONG_ANSWER";
    return 0;
  }
  sort(s.begin(), s.end());
  int i = 0;
  while (s[i] == 48 && i < s.size()) i++;
  swap(s[i], s[0]);
  if (t == s)
    cout << "OK";
  else
    cout << "WRONG_ANSWER";
  return 0;
}
