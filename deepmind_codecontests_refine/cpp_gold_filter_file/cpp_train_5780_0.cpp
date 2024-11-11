#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int a, b, id;
  bool operator<(const Edge &r) const { return a < r.a || a == r.a && b > r.b; }
};
Edge edges[100000];
pair<int, int> ans[100000];
int useds[100000];
int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);
  int n, m;
  while (cin >> n >> m) {
    for (int i = int(0); i < int(m); i++) {
      cin >> edges[i].a >> edges[i].b;
      edges[i].id = i;
    }
    sort(edges, edges + m);
    bool possible = true;
    int uC = 0;
    int tC = 0;
    for (int i = int(0); i < int(m); i++) {
      if (edges[i].b) {
        ans[edges[i].id] = pair<int, int>(uC + 2, uC + 1);
        uC++;
        useds[uC] = 1;
      } else {
        while (useds[tC] == tC) {
          tC++;
        }
        useds[tC]++;
        if (tC > uC) {
          possible = false;
          break;
        }
        ans[edges[i].id] = pair<int, int>(tC + 1, tC - useds[tC] + 1);
      }
    }
    if (possible) {
      for (int i = int(0); i < int(m); i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
      }
    } else
      cout << "-1" << endl;
  }
  return 0;
}
