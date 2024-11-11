#include <bits/stdc++.h>
using namespace std;
int color(char c) {
  switch (c) {
    case 'R':
      return 0;
    case 'G':
      return 1;
    case 'B':
      return 2;
    case 'Y':
      return 3;
    case 'W':
      return 4;
  }
}
int main() {
  int n;
  cin >> n;
  set<int> cards;
  for (int i = 0; i < n; i++) {
    string c;
    cin >> c;
    int v = (1 << 5 << color(c[0])) | (1 << (c[1] - '1'));
    cards.insert(v);
  }
  vector<int> uc(cards.begin(), cards.end());
  int ans = 10;
  for (int ss = 0; ss < 1 << 10; ss++) {
    map<int, set<int> > groups;
    bool possible = true;
    for (int i = 0; i < uc.size(); i++) {
      groups[uc[i] & ss].insert(uc[i]);
      if (groups[uc[i] & ss].size() > 1) {
        possible = false;
        break;
      }
    }
    if (possible) ans = min(ans, __builtin_popcount(ss));
  }
  cout << ans << '\n';
  return 0;
}
