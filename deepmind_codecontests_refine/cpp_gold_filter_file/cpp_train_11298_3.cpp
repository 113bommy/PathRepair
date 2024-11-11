#include <bits/stdc++.h>
using namespace std;
set<pair<int, string> > rat;
set<pair<int, string> > woman_child;
set<pair<int, string> > man;
set<pair<int, string> > captain;
int n;
string s1, s2;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s1 >> s2;
    if (s2 == "rat") rat.insert(make_pair(i, s1));
    if (s2 == "woman" || s2 == "child") woman_child.insert(make_pair(i, s1));
    if (s2 == "man") man.insert(make_pair(i, s1));
    if (s2 == "captain") captain.insert(make_pair(i, s1));
  }
  set<pair<int, string> >::iterator it;
  for (it = rat.begin(); it != rat.end(); ++it) cout << it->second << endl;
  for (it = woman_child.begin(); it != woman_child.end(); ++it)
    cout << it->second << endl;
  for (it = man.begin(); it != man.end(); ++it) cout << it->second << endl;
  for (it = captain.begin(); it != captain.end(); ++it)
    cout << it->second << endl;
  return 0;
}
