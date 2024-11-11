#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    map<char, int> m;
    for (int i = 0; i < s.size(); ++i) {
      m[s[i]]++;
    }
    int r = abs(m['R'] - m['L']);
    int u = abs(m['U'] - m['D']);
    if (m['R'] == 0 && m['L'] == 0 && m['U'] != 0 && m['D'] != 0) {
      cout << 2 << '\n' << "UD\n";
      continue;
    } else if (m['U'] == 0 && m['D'] == 0 && m['R'] != 0 && m['L'] != 0) {
      cout << 2 << '\n' << "LR" << '\n';
      continue;
    }
    vector<char> v;
    v.push_back('R');
    v.push_back('L');
    v.push_back('U');
    v.push_back('D');
    string ans = "";
    cout << s.size() - (r + u) << '\n';
    for (int j = 0; j < min(m['R'], m['L']); ++j) {
      ans += 'R';
    }
    for (int j = 0; j < min(m['U'], m['D']); ++j) {
      ans += 'U';
    }
    for (int j = 0; j < min(m['R'], m['L']); ++j) {
      ans += 'L';
    }
    for (int j = 0; j < min(m['U'], m['D']); ++j) {
      ans += 'D';
    }
    cout << ans << '\n';
  }
  return 0;
}
