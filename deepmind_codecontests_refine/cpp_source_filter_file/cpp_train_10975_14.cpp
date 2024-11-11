#include <bits/stdc++.h>
using namespace std;
string s;
bool possible(int bloc) {
  int pos = 0;
  int mini = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'L')
      pos--;
    else
      pos++;
    if (pos == bloc) pos--;
    if (i < s.size() - 1) mini = min(mini, pos);
  }
  if (pos < mini) return true;
  return false;
}
int main() {
  cin >> s;
  if (s[s.size() - 1] == 'R') {
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'L')
        s[i] = 'R';
      else
        s[i] = 'L';
    }
  }
  if (possible(s.size() + 10)) {
    cout << 1 << endl;
    return 0;
  }
  if (!possible(1)) {
    cout << 0 << endl;
    return 0;
  }
  int gauche = 1, droite = 100 * 1000;
  while (gauche + 1 < droite) {
    int milieu = (gauche + droite) / 2;
    if (possible(milieu)) {
      gauche = milieu;
    } else {
      droite = milieu;
    }
  }
  if (possible(gauche + 1))
    cout << gauche + 1 << endl;
  else
    cout << gauche << endl;
}
