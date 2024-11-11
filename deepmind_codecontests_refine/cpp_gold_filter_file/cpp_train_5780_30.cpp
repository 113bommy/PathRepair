#include <bits/stdc++.h>
using namespace std;
const long long INF = ((long long)1 << 60);
struct edge {
  long long w;
  long long on;
  pair<long long, long long> e;
  int pos;
};
bool cmp(edge a, edge b) {
  if (a.w != b.w)
    return a.w < b.w;
  else {
    return a.on > b.on;
  }
}
bool cmp2(edge a, edge b) { return a.pos < b.pos; }
int main() {
  std::ios::sync_with_stdio(false);
  long long n, m;
  cin >> n >> m;
  vector<edge> edges(m);
  for (int i = 0; i < m; ++i) {
    cin >> edges[i].w >> edges[i].on;
    edges[i].pos = i;
  }
  if (n == 2) {
    if (edges[0].on == 1)
      cout << 1 << " " << 2 << endl;
    else
      cout << -1 << endl;
    return 0;
  }
  sort(edges.begin(), edges.end(), cmp);
  long long ones = 1;
  int start = 2;
  int end = start + 1;
  for (int i = 0; i < m; i++) {
    if (edges[i].on == 1) {
      ++ones;
      edges[i].e = make_pair(1, ones);
    } else {
      if (end > ones) {
        cout << -1 << endl;
        return 0;
      }
      edges[i].e = make_pair(start, end);
      start++;
      if (start == end) {
        end++;
        start = 2;
      }
    }
  }
  sort(edges.begin(), edges.end(), cmp2);
  for (int i = 0; i < edges.size(); ++i) {
    cout << edges[i].e.first << " " << edges[i].e.second << "\n";
  }
  return 0;
}
