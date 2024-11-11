#include <bits/stdc++.h>
const int N = 2 * 1e5 + 100;
const int M = 4 * 1e5 + 100;
const double EPS = 1e-9;
using namespace std;
int n, m, k;
vector<pair<long long, int> > v[N];
struct Node {
  long long w;
  int u, v;
  Node(long long a, int b, int c) : w(a), u(b), v(c) {}
  bool operator<(Node xx) const { return w > xx.w; }
};
map<pair<int, int>, int> mp;
vector<Node> temp;
priority_queue<Node> q;
void dijsktra() {
  int cnt = 0;
  mp.clear();
  while (q.size()) q.pop();
  for (int i = 1; i <= n; i++) q.push({0, i, i});
  while (q.size()) {
    Node tp = q.top();
    q.pop();
    if (mp.find(make_pair(tp.u, tp.v)) != mp.end()) continue;
    if (mp.find(make_pair(tp.u, tp.v)) == mp.end() &&
        mp.find(make_pair(tp.v, tp.u)) == mp.end()) {
      cnt++;
      if (cnt == k) {
        printf("%lld\n", tp.w);
        return;
      }
    }
    mp[make_pair(tp.u, tp.v)] = 1;
    int rt = 0;
    for (pair<long long, int> &thp : v[tp.v]) {
      rt++;
      if (rt + cnt > k) break;
      int y = thp.second;
      if (mp.find(make_pair(tp.u, y)) != mp.end()) continue;
      q.push({tp.w + thp.first, tp.u, y});
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= m; i++) {
    int x, y;
    long long w;
    scanf("%d%d%lld", &x, &y, &w);
    temp.push_back({w, y, x});
  }
  sort(temp.begin(), temp.end());
  int siz = temp.size();
  for (int i = siz - 1; i >= max(siz - 1 - k, 0); i--) {
    int x = temp[i].u, y = temp[i].v, w = temp[i].w;
    v[x].push_back(make_pair(w, y));
    v[y].push_back(make_pair(w, x));
  }
  for (int i = 1; i <= n; i++) sort(v[i].begin(), v[i].end());
  dijsktra();
  return 0;
}
