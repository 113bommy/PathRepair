#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y;
  node() {}
  node(int x_, int y_) : x(x_), y(y_) {}
};
vector<node> v1, v2;
int solve() {
  vector<int> my_p;
  for (auto i : v1) {
    vector<int> poss;
    for (auto j : v2) {
      if ((i.x == j.x && i.y == j.y) || (i.x == j.y && i.y == j.x)) continue;
      if (i.x == j.x || i.y == j.x) poss.push_back(j.x);
      if (i.y == j.y || i.x == j.y) poss.push_back(j.y);
    }
    if ((int)poss.size() == 0) continue;
    int only = poss[0], flag = 1;
    for (auto j : poss)
      if (only != j) {
        flag = 0;
        break;
      }
    if (flag)
      my_p.push_back(only);
    else
      return -1;
  }
  for (auto i : v2) {
    vector<int> poss;
    for (auto j : v1) {
      if ((i.x == j.x && i.y == j.y) || (i.x == j.y && i.y == j.x)) continue;
      if (i.x == j.x || i.y == j.x) poss.push_back(j.x);
      if (i.y == j.y || i.x == j.y) poss.push_back(j.y);
    }
    if ((int)poss.size() == 0) continue;
    int only = poss[0], flag = 1;
    for (auto j : poss)
      if (only != j) {
        flag = 0;
        break;
      }
    if (flag)
      my_p.push_back(only);
    else
      return -1;
  }
  if ((int)my_p.size() == 0) return 0;
  int only = my_p[0];
  for (auto i : my_p)
    if (only != i) return 0;
  return 1;
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  v1.resize(n);
  v2.resize(m);
  for (int j = 0; j < n; j++) cin >> v1[j].x >> v1[j].y;
  for (int j = 0; j < m; j++) cin >> v2[j].x >> v2[j].y;
  cout << solve() << endl;
  return 0;
}
