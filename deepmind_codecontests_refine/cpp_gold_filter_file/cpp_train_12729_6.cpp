#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
using vi = vector<int>;
using pi = pair<int, int>;
using vpi = vector<pi>;
using si = set<int>;
string s[3];
map<char, int> m_needed, m_possible;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for (int i = 0; i < 3; i++) cin >> s[i];
  for (int i = 0; i < s[0].size(); i++) m_needed[s[0][i]]++;
  for (int i = 0; i < s[1].size(); i++) m_needed[s[1][i]]++;
  for (int i = 0; i < s[2].size(); i++) m_possible[s[2][i]]++;
  bool ok = true;
  for (char c = 'A'; c <= 'Z'; c++) {
    if (m_possible[c] != m_needed[c]) ok = false;
  }
  if (ok)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
