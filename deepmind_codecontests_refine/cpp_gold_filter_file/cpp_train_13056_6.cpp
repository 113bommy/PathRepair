#include <bits/stdc++.h>
using namespace std;
const int M = 1000 + 5;
struct NODE {
  int pow;
  int dam;
  bool used;
  int index;
} node[M];
int main() {
  int N, maxh, reg;
  cin >> N >> maxh >> reg;
  for (int i = 0; i < N; i++) {
    cin >> node[i].pow >> node[i].dam;
    node[i].used = false;
    node[i].index = i + 1;
  }
  int wintime = -1;
  int damage = 0;
  int curh = maxh;
  vector<pair<int, int> > ans;
  for (int t = 0; t <= 3000; t++) {
    int curh1 = curh - damage;
    curh1 = curh1 + reg;
    if (curh1 > maxh) {
      curh1 = maxh;
    }
    if (curh1 <= 0) {
      wintime = t;
      break;
    }
    curh = curh1;
    int index = -1;
    int maxd = 0;
    for (int i = 0; i < N; i++) {
      if (node[i].used == false) {
        if (100 * curh <= node[i].pow * maxh) {
          if (node[i].dam > maxd) {
            maxd = node[i].dam;
            index = node[i].index;
          }
        }
      }
    }
    if (index != -1) {
      damage = damage + node[index - 1].dam;
      node[index - 1].used = true;
      ans.push_back(make_pair(t, index));
    }
  }
  if (wintime == -1) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    cout << wintime << " " << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i].first << " " << ans[i].second << endl;
    }
  }
  return 0;
}
