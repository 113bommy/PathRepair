#include <bits/stdc++.h>
using namespace std;
vector<int> p, p1, p2;
bool vis[100005];
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  p.resize(n + 1);
  for (int i = 0; i < n; i++) cin >> p[i + 1];
  int c1 = -1, c2 = -1;
  for (int i = 1; i < n + 1; i++)
    if (p[i] == i) c1 = i;
  for (int i = 1; i < n + 1; i++)
    if (i == p[p[i]]) c2 = i;
  if (c1 != -1) {
    cout << "YES" << endl;
    for (int i = 1; i < n + 1; i++)
      if (i != c1) cout << (i) << " " << (c1) << endl;
  } else if (c2 != -1) {
    bool can = true;
    memset(vis, false, sizeof vis);
    p1.clear();
    p2.clear();
    int g1 = c2, g2 = p[c2];
    vis[g1] = vis[g2] = true;
    for (int i = 1; i < n + 1; i++) {
      if (!vis[i]) {
        int par = 1, cur = i;
        p1.push_back(i);
        vis[i] = true;
        while (p[cur] != i) {
          cur = p[cur];
          vis[cur] = true;
          ++par;
          if (par & 1)
            p1.push_back(cur);
          else
            p2.push_back(cur);
        }
        if (par & 1) {
          can = false;
          break;
        }
      }
    }
    if (!can)
      cout << "NO" << endl;
    else {
      cout << "YES" << endl;
      cout << g1 << " " << g2 << endl;
      for (int i = 0; i < p1.size(); i++) cout << g1 << " " << p1[i] << endl;
      for (int i = 0; i < p2.size(); i++) cout << g2 << " " << p2[i] << endl;
    }
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
