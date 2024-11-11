#include <bits/stdc++.h>
using namespace std;
struct Node {
  int r, c, id;
  bool operator<(const Node &p) const { return r < p.r || r == p.r && c < p.c; }
};
int main() {
  int n, m;
  cin >> n >> m;
  vector<Node> v(m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &v[i].r, &v[i].c);
    v[i].id = i + 1;
    v[i].c = n - v[i].c + 1;
  }
  sort(v.begin(), v.end());
  set<int> s;
  for (int i = 1; i <= n; i++) {
    s.insert(i);
  }
  vector<int> ret;
  for (int i = 0; i < m; i++) {
    set<int>::iterator it = s.lower_bound(v[i].c);
    if (it != s.end() && *it <= v[i].r) {
      ret.push_back(v[i].id);
      s.erase(it);
    }
  }
  cout << ret.size() << endl;
  for (int i = 0; i < ret.size(); i++) {
    printf("%d ", ret[i]);
  }
  return 0;
}
