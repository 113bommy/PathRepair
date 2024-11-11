#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
struct Node {
  int x, y;
};
vector<Node> hh[N];
bool cmp(Node a, Node b) { return a.x < b.x; }
int smg[N];
map<pair<int, int>, int> flag;
int n, m;
bool solve(int x) {
  for (int i = 1; i <= n / 2; i++) {
    if (hh[i].size()) {
      for (int j = 0; j < hh[i].size(); j++) {
        int tep = hh[i][j].x + x;
        while (tep > n) tep -= n;
        if (flag[make_pair(tep, i)])
          continue;
        else {
          return 0;
        }
      }
    }
  }
  return 1;
}
vector<int> ans;
int main() {
  scanf("%d%d", &n, &m);
  bool f = 0;
  Node tep;
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (y > x) swap(x, y);
    if (x - y > y + n - x) {
      tep.x = x;
      tep.y = y;
      hh[y + n - x].push_back(tep);
      flag[make_pair(x, y + n - x)] = 1;
      if ((n % 2) == 0 && y + n - x == n / 2) flag[make_pair(y, y + n - x)] = 1;
    } else {
      tep.x = y;
      tep.y = x;
      hh[x - y].push_back(tep);
      flag[make_pair(y, x - y)] = 1;
      if ((n % 2) == 0 && x - y == n / 2) flag[make_pair(x, x - y)] = 1;
    }
  }
  for (int i = 1; i <= n / 2; i++) {
    if ((n % i) == 0) ans.push_back(i);
  }
  for (int i = 1; i < ans.size(); i++) {
    if (solve(ans[i])) {
      f = 1;
      printf("Yes\n");
      break;
    }
  }
  if (f == 0) printf("No\n");
  return 0;
}
