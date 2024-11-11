#include <bits/stdc++.h>
using namespace std;
struct Node {
  int p, id;
  bool operator<(const Node &B) const { return p > B.p; }
};
int p[200001], a[200001], b[200001], c[200001];
bool flag[200001];
int n, m;
priority_queue<Node> q[1000];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> c[i];
  }
  for (int i = 1; i <= n; i++) {
    Node tmp;
    tmp.p = p[i];
    tmp.id = i;
    q[a[i]].push(tmp);
    if (a[i] != b[i]) q[b[i]].push(tmp);
  }
  for (int i = 1; i <= m; i++) {
    Node cur;
    bool fg = false;
    while (!q[c[i]].empty()) {
      cur = q[c[i]].top();
      q[c[i]].pop();
      if (flag[cur.id] == 0) {
        flag[cur.id] = 1;
        fg = true;
        break;
      }
    }
    if (!q[c[i]].empty()) {
      cout << p[cur.id];
    } else {
      if (fg == true)
        cout << p[cur.id];
      else
        cout << "-1";
    }
    cout << " ";
  }
  return 0;
}
