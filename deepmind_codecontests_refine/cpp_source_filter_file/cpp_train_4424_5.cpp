#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  string g = "CODEFORCES";
  if (g.size() > s.size()) {
    cout << "NO" << endl;
    return 0;
  }
  int cnt = 0;
  for (int i = 0; i < s.size(); i++)
    if (s[i] != g[i]) {
      cnt = i + 1;
      break;
    }
  int cnt2 = 0;
  for (int i = 0; i < s.size(); i++)
    if (s[s.size() - i - 1] != g[g.size() - i - 1]) {
      cnt2 = i;
      break;
    }
  if (cnt2 + cnt >= g.size())
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
