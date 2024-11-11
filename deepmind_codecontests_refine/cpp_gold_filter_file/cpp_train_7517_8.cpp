#include <bits/stdc++.h>
using namespace std;
bool issafe(map<pair<int, int>, int> m, int i, int j) {
  return i >= 1 && i <= 8 && j >= 1 && j <= 8 && (m.find({i, j}) == m.end());
}
int main() {
  string str;
  map<pair<int, int>, int> statues;
  map<pair<int, int>, int> player;
  for (int i = 1; i <= 8; i++) {
    cin >> str;
    for (int j = 1; j <= 8; j++) {
      if (str[j - 1] == 'S') statues[{i, j}] = 1;
      ;
    }
  }
  player[{8, 1}] = 1;
  ;
  int row[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
  int col[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
  int cnt = 1;
  map<pair<int, int>, int>::iterator it;
  while (player.size() > 0 && cnt <= 7) {
    map<pair<int, int>, int> dup;
    for (it = player.begin(); it != player.end(); it++) {
      for (int i = 0; i <= 8; i++) {
        if (issafe(statues, row[i] + (it->first).first,
                   col[i] + (it->first).second))
          dup[{row[i] + (it->first).first, col[i] + (it->first).second}] = 1;
      }
    }
    player.clear();
    for (it = dup.begin(); it != dup.end(); it++) {
      int r = (it->first).first;
      int c = (it->first).second;
      player[{r, c}] = 1;
    }
    dup.clear();
    for (it = statues.begin(); it != statues.end(); it++) {
      int r = (it->first).first + 1;
      int c = (it->first).second;
      if (r <= 8) dup[{r, c}] = 1;
      if (player.find({r, c}) != player.end()) player.erase({r, c});
    }
    statues.clear();
    for (it = dup.begin(); it != dup.end(); it++) {
      int r = (it->first).first;
      int c = (it->first).second;
      statues[{r, c}] = 1;
    }
    cnt++;
  }
  if (player.size() > 0)
    cout << "WIN";
  else
    cout << "LOSE";
  return 0;
}
