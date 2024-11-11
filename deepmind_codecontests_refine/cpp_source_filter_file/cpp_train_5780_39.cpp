#include <bits/stdc++.h>
using namespace std;
struct node {
  int id, len, ok;
};
bool cmp(node a, node b) {
  if (a.len == b.len) return a.ok > b.ok;
  return a.len < b.len;
}
int main() {
  int i, j, k, n, m;
  vector<node> vn;
  vector<int> u, v;
  vector<int> used;
  cin >> n >> m;
  u.resize(m), v.resize(m);
  for (i = 0; i < m; i++) {
    node tmp;
    int w, fg;
    cin >> w >> fg;
    tmp.id = i;
    tmp.len = w;
    tmp.ok = fg;
    vn.push_back(tmp);
  }
  sort(vn.begin(), vn.end(), cmp);
  used.push_back(1);
  int x, y;
  x = 1;
  y = 1;
  for (i = 0; i < m; i++) {
    if (vn[i].ok) {
      u[vn[i].id] = used[used.size() - 1];
      v[vn[i].id] = used.size() + 1;
      used.push_back(used.size() + 1);
    } else {
      if (x + 1 >= y) {
        cout << -1 << endl;
        return 0;
      }
      u[vn[i].id] = x;
      v[vn[i].id] = y;
      x++;
    }
    if (x + 1 >= y && y + 1 <= used.size()) y++;
  }
  for (i = 0; i < m; i++) cout << u[i] << " " << v[i] << "\n";
  return 0;
}
