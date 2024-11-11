#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
vector<pair<pair<int, int>, int> > edges;
int a[N][2];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int w, z;
    scanf("%d %d", &w, &z);
    edges.push_back({{w, z}, i});
  }
  sort(edges.begin(), edges.end());
  int k = 0;
  int u = 0, v = 2;
  for (auto e : edges) {
    if (e.first.second) {
      a[e.second][0] = k++;
      a[e.second][1] = k;
    } else {
      if (v > k) {
        puts("-1");
        return 0;
      }
      a[e.second][0] = u++;
      a[e.second][1] = v;
      if (v == u + 1) {
        v++;
        u = 0;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    cout << a[i][0] + 1 << " " << a[i][1] + 1 << endl;
  }
  return 0;
}
