#include <bits/stdc++.h>
using namespace std;
int n, m, a[100010];
struct Segline {
  int l, r;
  double p;
} data[100010];
bool cmp(const Segline &a, const Segline &b) {
  if (a.l != b.l) return a.l < b.l;
  return a.r < b.r;
}
struct Node {
  int l, r;
  vector<pair<int, double> > v;
  vector<double> addList;
  vector<Node> sons;
  Node(int _l = 0, int _r = 0) : l(_l), r(_r) {}
  void insert(int _l, int _r, double p) {
    if (l == _l && r == _r) {
      addList.push_back(p);
      return;
    }
    for (int i = 0; i < (sons.size()); i++) {
      if (sons[i].l <= _l && _r <= sons[i].r) {
        sons[i].insert(_l, _r, p);
        return;
      }
    }
    sons.push_back(Node(_l, _r));
    sons[sons.size() - 1].insert(_l, _r, p);
  }
  void ask() {
    for (int i = 0; i < (sons.size()); i++) {
      sons[i].ask();
    }
    int low = 0, high = 0;
    for (int pos = l, i = 0; pos <= r; pos++) {
      if (i != sons.size() && pos == sons[i].l) {
        pos = sons[i].r;
        low = max(low, sons[i].v.front().first);
        high = max(high, sons[i].v.back().first);
        i++;
        continue;
      }
      low = max(low, a[pos]);
      high = max(high, a[pos]);
    }
    for (int i = low; i <= high; i++) v.push_back(make_pair(i, 1));
    for (int i = 0; i < (sons.size()); i++) {
      Node &son = sons[i];
      double p = 1.0;
      for (int h = son.v.size() - 1, g = v.size() - 1; h >= 0; h--) {
        while (g >= 0 && v[g].first > son.v[h].first) g--;
        if (g < 0) break;
        v[g].second *= son.v[h].second;
      }
    }
    for (int i = 0; i < (addList.size()); i++) {
      double p = addList[i];
      v.push_back(make_pair(v.back().first + 1, 1));
      for (int g = v.size() - 2; g >= 1; g--) {
        v[g].second -= (v[g].second - v[g - 1].second) * p;
      }
      v[0].second *= (1 - p);
    }
  }
} root;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < (n); i++) scanf("%d", &a[i]);
  for (int i = 0; i < (m); i++) {
    scanf("%d%d%lf", &data[i].l, &data[i].r, &data[i].p);
    data[i].l--;
    data[i].r--;
  }
  sort(data, data + m, cmp);
  root = Node(0, n - 1);
  for (int i = 0; i < (m); i++) root.insert(data[i].l, data[i].r, data[i].p);
  root.ask();
  double ans = 0;
  for (int i = 0; i < (root.v.size()); i++)
    ans += root.v[i].first *
           (root.v[i].second - (i == 0 ? 0 : root.v[i - 1].second));
  printf("%.10lf\n", ans);
  return 0;
}
