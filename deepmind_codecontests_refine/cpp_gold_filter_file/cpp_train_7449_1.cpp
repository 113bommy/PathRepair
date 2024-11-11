#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n, k;
long long x, seq[N];
struct Node {
  long long x;
  int id;
  bool operator<(const Node &rhs) const { return abs(x) > abs(rhs.x); }
};
priority_queue<Node> que;
vector<Node> ans;
bool cmp(const Node &lhs, const Node &rhs) { return lhs.id < rhs.id; }
int main() {
  ios::sync_with_stdio(false);
  while (!que.empty()) que.pop();
  ans.clear();
  cin >> n >> k >> x;
  int zcnt = 0;
  for (int i = 0; i < n; ++i) {
    cin >> seq[i];
    que.push((Node){seq[i], i});
    if (seq[i] < 0) ++zcnt;
  }
  while (k) {
    Node tp = que.top();
    que.pop();
    if (zcnt & 1) {
      if (tp.x >= 0)
        tp.x += x;
      else
        tp.x -= x;
    } else {
      if (tp.x < 0) {
        tp.x += x;
        if (tp.x >= 0) zcnt--;
      } else {
        tp.x -= x;
        if (tp.x < 0) zcnt++;
      }
    }
    que.push(tp);
    --k;
  }
  while (!que.empty()) {
    ans.push_back(que.top());
    que.pop();
  }
  sort(ans.begin(), ans.end(), cmp);
  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i].x;
    if (i < ans.size() - 1)
      cout << " ";
    else
      cout << endl;
  }
  return 0;
}
