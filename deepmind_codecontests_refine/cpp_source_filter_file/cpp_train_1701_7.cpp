#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
int main() {
  int n;
  cin >> n;
  map<string, int> m;
  for (int i = (0); i < (n); i++) {
    string s;
    int p;
    cin >> s >> p;
    if (m.find(s) == m.end())
      m[s] = p;
    else
      m[s] = max(m[s], p);
  }
  int num = m.size();
  cout << num << endl;
  for (auto i = (m).begin(); i != (m).end(); i++) {
    int better = 0;
    for (auto j = (m).begin(); j != (m).end(); j++) {
      if (j->second > i->second) better++;
    }
    if (better >= 0.5 * num)
      cout << i->first << " noob" << endl;
    else if (better >= 0.2 * num)
      cout << i->first << " random" << endl;
    else if (better >= 0.1 * num)
      cout << i->first << " average" << endl;
    else if (better >= 0.01 * num)
      cout << i->first << " hardcore" << endl;
    else
      cout << i->first << " pro" << endl;
  }
}
