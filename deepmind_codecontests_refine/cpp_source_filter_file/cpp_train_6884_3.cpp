#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  int ind1, ind2, ind3, ind4, colons[550000] = {0}, stlines[550000] = {0},
                              f1 = 0, f2 = 0;
  cin >> s;
  if (s[0] = ':') colons[0] = 1;
  if (s[0] == '|') stlines[0] = 1;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '[') {
      f1 = 1;
      ind1 = i;
      break;
    }
  }
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == ']') {
      f2 = 1;
      ind2 = i;
    }
  }
  if (f1 == 0 || f2 == 0) {
    cout << "-1";
    return;
  }
  for (int i = 1; i < s.size(); i++) {
    if (s[i] == ':')
      colons[i] = colons[i - 1] + 1;
    else
      colons[i] = colons[i - 1];
  }
  for (int i = 1; i < s.size(); i++) {
    if (s[i] == '|')
      stlines[i] = stlines[i - 1] + 1;
    else
      stlines[i] = stlines[i - 1];
  }
  if (colons[ind2 - 1] - colons[ind1] < 2) {
    cout << "-1";
  } else {
    for (int i = ind1 + 1; i <= ind2 - 1; i++) {
      if (s[i] == ':') {
        ind3 = i;
        break;
      }
    }
    for (int i = ind1 + 1; i < ind2; i++) {
      if (s[i] == ':') {
        ind4 = i;
      }
    }
    cout << stlines[ind4 - 1] - stlines[ind3] + 4 << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}
