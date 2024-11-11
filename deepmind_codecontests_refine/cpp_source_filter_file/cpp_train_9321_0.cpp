#include <bits/stdc++.h>
using namespace std;
char ch[11111];
int n;
map<char, int> num;
set<vector<int> > pos;
int main() {
  cin >> n;
  cin >> ch;
  num['G'] = 0;
  num['H'] = 1;
  num['R'] = 2;
  num['S'] = 3;
  pos.insert(vector<int>(4, 0));
  for (int(i) = 0; (i) < (n); ++(i)) {
    set<vector<int> > np;
    np.clear();
    for (set<vector<int> >::iterator it = pos.begin(); it != pos.end(); ++it) {
      vector<int> cur = *it;
      if (ch[i] != '?') {
        cur[num[ch[i]]]++;
        np.insert(cur);
      } else {
        int val = *min_element((cur).begin(), (cur).end());
        for (int(k) = 0; (k) < (4); ++(k))
          if (cur[k] == val) {
            cur[k]++;
            np.insert(cur);
            cur[k]--;
          }
      }
    }
    pos = np;
  }
  int can[4];
  memset((can), 0, sizeof((can)));
  for (set<vector<int> >::iterator it = pos.begin(); it != pos.end(); ++it) {
    int val = *min_element((*it).begin(), (*it).end());
    vector<int> cur = *it;
    for (int k = 0; k < 4; ++k)
      if (cur[k] == val) can[k] = 1;
  }
  if (can[0]) cout << "Griffindor\n";
  if (can[1]) cout << "Hufflepuff\n";
  if (can[2]) cout << "Ravenclaw\n";
  if (can[3]) cout << "Slytherin\n";
}
