#include <bits/stdc++.h>
using namespace std;
int n, k;
struct node {
  int pos, x, y;
  node() {}
  node(int _x, int _y, int _pos) {
    x = _x;
    y = _y;
    pos = _pos;
  }
  bool operator<(const node &nd) const { return y < nd.y; }
};
bool cmp(node a, node b) {
  if (a.x < b.x) return true;
  if (a.x == b.x) return a.y != -1;
  return false;
}
vector<node> v;
vector<int> ans;
bool used[int(2 * 1e5 + 5)];
int main() {
  int i, a, b, sz, tsz = 0;
  cin >> n >> k;
  for (i = 0; i < n; i++) {
    cin >> a >> b;
    v.push_back(node(a, b, i));
    v.push_back(node(b, -1, i));
  }
  sort(v.begin(), v.end(), cmp);
  priority_queue<node> q;
  sz = v.size();
  for (i = 0; i < sz; i++) {
    node nd = v[i];
    if (nd.y != -1) {
      q.push(nd);
      tsz++;
      if (tsz > k) {
        ans.push_back(q.top().pos);
        used[q.top().pos] = true;
        q.pop();
        tsz--;
      }
    } else {
      if (!used[nd.pos]) tsz--;
    }
  }
  sz = ans.size();
  sort(ans.begin(), ans.end());
  cout << sz << endl;
  for (i = 0; i < sz; i++) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
