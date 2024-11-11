#include <bits/stdc++.h>
using namespace std;
class TreeNode {
 public:
  long long a;
  long long depth;
  long long ans;
  vector<pair<int, int> > ch;
};
void calc_depth(vector<TreeNode>& tree, int cur, int depth) {
  tree[cur].depth = depth;
  for (int i = 0; i < tree[cur].ch.size(); i++) {
    calc_depth(tree, tree[cur].ch[i].first, depth + tree[cur].ch[i].second);
  }
}
void calc_ans(vector<TreeNode>& tree, int cur, priority_queue<long long>& qu) {
  priority_queue<long long> tmp;
  int init_size = qu.size();
  for (int i = 0; i < tree[cur].ch.size(); i++) {
    calc_ans(tree, tree[cur].ch[i].first, qu);
    while (!qu.empty() && qu.top() > tree[cur].depth) {
      qu.pop();
    }
  }
  tree[cur].ans = qu.size() - init_size;
  qu.push((tree[cur].depth - tree[cur].a));
}
int main() {
  int n;
  cin >> n;
  vector<TreeNode> tree(n);
  for (int i = 0; i < n; i++) cin >> tree[i].a;
  for (int i = 1; i < n; i++) {
    int p, w;
    cin >> p >> w;
    p--;
    tree[p].ch.push_back(make_pair(i, w));
  }
  calc_depth(tree, 0, 0);
  priority_queue<long long> qu;
  calc_ans(tree, 0, qu);
  for (int i = 0; i < n; i++) {
    cout << ((i > 0) ? " " : "") << tree[i].ans;
  }
  return 0;
}
