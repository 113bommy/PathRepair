#include <bits/stdc++.h>
using namespace std;
struct Vertex {
  int id, deg, v;
  bool operator<(const Vertex &rhs) const { return deg < rhs.deg; }
} v[100005], p[100005];
int n;
vector<pair<int, int> > ans;
int main() {
  while (scanf("%d", &n) == 1) {
    ans.clear();
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &v[i].deg, &v[i].v);
    }
    queue<int> Q;
    for (int i = 0; i < n; i++)
      if (v[i].deg == 1) Q.push(i);
    while (!Q.empty()) {
      int i = Q.front();
      Q.pop();
      if (v[i].deg == 0) continue;
      v[v[i].v].deg--;
      v[i].deg--;
      if (v[v[i].v].deg == 1) Q.push(v[i].v);
      v[v[i].v].v ^= i;
      ans.push_back(make_pair(v[i].v, i));
      v[i].v = 0;
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
      printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}
