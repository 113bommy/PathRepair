#include <bits/stdc++.h>
using namespace std;
struct point {
  int x, y, val;
};
int n, m, k, ccnt, ans;
point cur, pos;
vector<pair<int, int> > way[2501];
int new_val(int x, int y) { return min(y, n - x + 1); }
void change(int type) {
  if (type == 1) {
    if (cur.y <= m)
      cur.y++;
    else
      cur.x++;
    cur.val = new_val(cur.x, cur.y);
  } else {
    if (cur.x > 1)
      cur.x--;
    else
      cur.y--;
    cur.val = new_val(cur.x, cur.y);
  }
}
int main() {
  cin >> n >> m >> k;
  cur.x = cur.y = cur.val = 1;
  int cnt = 1;
  while (cnt < k) {
    change(1);
    cnt += cur.val;
  }
  cnt -= cur.val;
  pos.x = cur.x;
  pos.y = cur.y;
  while (cnt) {
    if (cnt == k - ccnt) {
      change(-1);
      cnt -= cur.val;
      pos.x = cur.x;
      pos.y = cur.y;
    }
    for (int i = 1; i < pos.y; ++i) way[ccnt].push_back(make_pair(1, i));
    for (int i = 1; i <= pos.x; ++i) way[ccnt].push_back(make_pair(i, pos.y));
    pos.y--;
    pos.x++;
    ccnt++;
    ans += cur.y - 1 + cur.x;
  }
  if (k == 1) {
    ans++;
    way[0].push_back(make_pair(1, 1));
    ccnt++;
  }
  cout << ans << endl;
  for (int i = 0; i < ccnt; ++i) {
    for (int j = 0; j < (int)(way[i].size()); ++j) {
      cout << '(' << way[i][j].first << ", " << way[i][j].second << ")";
      if (j < (int)(way[i].size()) - 1) cout << ' ';
    }
    if (i < ccnt - 1) cout << endl;
  }
}
