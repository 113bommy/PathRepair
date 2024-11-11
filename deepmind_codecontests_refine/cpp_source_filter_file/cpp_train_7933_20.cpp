#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
int main() {
  char ch[13][13];
  memset(ch, '.', sizeof(ch));
  for (int i = 0; i < 8; i++) {
    cin.getline(ch[i], 13);
  }
  vector<pair<int, int> > v;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (ch[i][j] == 'S') {
        v.push_back(make_pair(i, j));
      }
    }
  }
  queue<pair<int, int> > q;
  queue<int> qq;
  q.push(make_pair(7, 0));
  qq.push(1);
  int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
  int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
  pair<int, int> t, to;
  while (!q.empty()) {
    t = q.front();
    q.pop();
    int tt = qq.front();
    qq.pop();
    if (tt == 9) {
      cout << "WIN";
      return 0;
    }
    for (int i = 0; i < 8; i++) {
      to.first = t.first + dx[i];
      to.second = t.second + dy[i];
      if (to.first >= 0 && to.first < 8 && to.second >= 0 && to.second < 8) {
        bool fl = true;
        for (int j = 0; j < v.size(); j++) {
          if ((v[j].first + tt - 1 == to.first && v[j].second == to.second) ||
              (v[j].first + tt == to.first && v[j].second == to.second)) {
            fl = false;
            break;
          }
        }
        if (fl) {
          q.push(to);
          qq.push(tt + 1);
        }
      }
    }
  }
  cout << "LOSE";
  return 0;
}
