#include <bits/stdc++.h>
using namespace std;
string solve() {
  string a, b;
  cin >> a >> b;
  map<char, set<int>> pos;
  for (int i = 0; i < (int)a.size(); ++i) pos[a[i]].insert(i);
  for (int i = 0; i < (int)min(a.size(), b.size()) && a[i] >= b[i]; ++i) {
    pos[a[i]].erase(i);
    if (pos[a[i]].empty()) pos.erase(a[i]);
    if (pos.empty()) break;
    if (pos.begin()->first < a[i]) {
      swap(a[i], a[*(--(pos.begin()->second.end()))]);
      break;
    }
  }
  if (lexicographical_compare(a.begin(), a.end(), b.begin(), b.end())) return a;
  return "---";
}
int main() {
  int t;
  cin >> t;
  while (t--) cout << solve() << "\n";
}
